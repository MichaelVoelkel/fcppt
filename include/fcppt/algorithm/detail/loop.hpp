//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_LOOP_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_LOOP_HPP_INCLUDED

#include <fcppt/algorithm/range_element_type.hpp>
#include <fcppt/mpl/for_each.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Range,
	typename Body
>
inline
typename
boost::enable_if<
	boost::mpl::is_sequence<
		typename
		std::decay<
			Range
		>::type
	>,
	void
>::type
loop(
	Range const &,
	Body const &_body
)
{
	fcppt::mpl::for_each<
		Range
	>(
		_body
	);
}

template<
	typename Range,
	typename Body
>
inline
typename
boost::disable_if<
	boost::mpl::is_sequence<
		typename
		std::decay<
			Range
		>::type
	>,
	void
>::type
loop(
	Range &&_range,
	Body const &_body
)
{
	for(
		fcppt::algorithm::range_element_type<
			Range
		> element
		:
		_range
	)
		_body(
			element
		);
}

}
}
}

#endif
