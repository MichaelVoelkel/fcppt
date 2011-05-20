//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_FILL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_FILL_HPP_INCLUDED

#include <boost/foreach.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ret
>
Ret const
fill(
	typename Ret::value_type const &_value
)
{
	Ret ret;

	BOOST_FOREACH(
		typename Ret::reference ref,
		ret
	)
		ref = _value;

	return ret;
}

}
}
}

#endif
