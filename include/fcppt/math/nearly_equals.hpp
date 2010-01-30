//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_NEARLY_EQUALS_HPP_INCLUDED
#define FCPPT_MATH_NEARLY_EQUALS_HPP_INCLUDED

#include <fcppt/math/diff.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <limits>

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
nearly_equals(
	T const &a,
	T const &b)
{
	return diff(a, b) < std::numeric_limits<T>::epsilon();
}

}
}

#endif
