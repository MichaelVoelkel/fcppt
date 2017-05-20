//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_CURRENT_TYPE_NAME_HPP_INCLUDED
#define FCPPT_VARIANT_CURRENT_TYPE_NAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/type_name_from_index.hpp>
#include <fcppt/use.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Returns the type name of the current type.

\ingroup fcpptvariant
*/
template<
	typename Elements
>
fcppt::string
current_type_name(
	fcppt::variant::object<
		Elements
	> const &_variant
)
{
	return
		fcppt::variant::apply_unary(
			[](
				auto const &_element
			)
			{
				FCPPT_USE(
					_element
				);

				return
					fcppt::type_name_from_index(
						typeid(
							_element
						)
					);
			},
			_variant
		);
}

}
}

#endif