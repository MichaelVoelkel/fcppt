//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_DETAIL_TYPES_OF_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TYPES_OF_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{
template <typename Type>
struct types_of;

template <typename... Types>
struct types_of<fcppt::variant::object<Types...>>
{
  using type = ::metal::list<Types...>;
};

}
}
}

#endif
