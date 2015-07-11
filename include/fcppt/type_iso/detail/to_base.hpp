//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_DETAIL_TO_BASE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_DETAIL_TO_BASE_HPP_INCLUDED

#include <fcppt/type_iso/base_type.hpp>
#include <fcppt/type_iso/transform.hpp>
#include <fcppt/type_iso/detail/is_terminal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_iso
{
namespace detail
{

template<
	typename Type
>
inline
typename
std::enable_if<
	fcppt::type_iso::detail::is_terminal<
		Type
	>::value,
	Type
>::type
to_base(
	Type const &_value
)
{
	return
		_value;
}

template<
	typename Type
>
inline
typename
std::enable_if<
	!fcppt::type_iso::detail::is_terminal<
		Type
	>::value,
	fcppt::type_iso::base_type<
		Type
	>
>::type
to_base(
	Type const &_value
)
{
	return
		fcppt::type_iso::detail::to_base(
			fcppt::type_iso::transform<
				Type
			>::base_value(
				_value
			)
		);
}

}
}
}

#endif