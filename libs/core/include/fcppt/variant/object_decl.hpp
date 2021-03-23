//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/metal/is_set.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/has_type.hpp>
#include <fcppt/variant/detail/std_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace variant
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A class that can hold any object from a fixed set of types

\ingroup fcpptvariant

\tparam Types The list of element types. It may not contain dupiicates.

See \ref fcpptvariant for more information.
*/
template <typename... Types>
class object
{
public:
  using this_type = fcppt::variant::object<Types...>;

  /**
  \brief The metal::list of the possible types
  */
  using types = ::metal::list<Types...>;

  static_assert(fcppt::metal::is_set<types>::value, "Variant types must form a set");

  using std_type = fcppt::variant::detail::std_type<types>;

  /**
  \brief Constructs the variant from a value.

  Constructs the variant from \a value.

  \tparam U Must be a type among <code>types</code>
  */
  template <
      typename U,
      typename =
          std::enable_if_t<fcppt::variant::detail::
                               has_type<this_type, fcppt::type_traits::remove_cv_ref_t<U>>::value>>
  explicit object(U &&);

  /**
  \brief Returns a const reference to the held type without any checks.

  \tparam U Must be a type among <code>types</code>

  \warning The behaviour is undefined if the variant does not contain <code>U</code>.
  */
  template <typename U>
  [[nodiscard]] U const &get_unsafe() const;

  /**
  \brief Returns a reference to the held type without any checks.

  \tparam U Must be a type among <code>types</code>

  \warning The behaviour is undefined if the variant does not contain <code>U</code>.
  */
  template <typename U>
  [[nodiscard]] U &get_unsafe();

  /**
  \brief Returns the index of the held type

  \return A runtime index into <code>types</code> of the held type.
  */
  [[nodiscard]] fcppt::variant::size_type type_index() const;

  /**
  \brief Returns if the variant is invalid.

  This can only happen if an assignment of a different type throws an
  exception. There is no way to recover from that, except for falling
  back to heap allocation. An invalid variant should only be destroyed or
  assigned to.
  */
  [[nodiscard]] bool is_invalid() const;

  [[nodiscard]] std_type &impl();

  [[nodiscard]] std_type const &impl() const;

private:
  std_type impl_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
