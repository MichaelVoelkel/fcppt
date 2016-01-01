//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_FORWARD_GET_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_FORWARD_GET_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/is_object_reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{
namespace detail
{

template<
	typename Optional,
	typename Arg
>
inline
typename
boost::enable_if<
	fcppt::optional::is_object_reference<
		Optional
	>,
	Arg &
>::type
forward_get(
	Arg &_arg
)
{
	return
		_arg;
}

template<
	typename Optional,
	typename Arg
>
inline
typename
boost::disable_if<
	fcppt::optional::is_object_reference<
		Optional
	>,
	decltype(
		fcppt::move_if_rvalue<
			Optional
		>(
			std::declval<
				Arg &
			>()
		)
	)
>::type
forward_get(
	Arg &_arg
)
{
	return
		fcppt::move_if_rvalue<
			Optional
		>(
			_arg
		);
}

}
}
}

#endif