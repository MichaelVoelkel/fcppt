//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_FLOAT_OR_DOUBLE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_FLOAT_OR_DOUBLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a type is float or double

\ingroup fcppttypetraits

Checks if \a Type is float or double.

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_float_or_double
:
boost::mpl::or_<
	boost::is_same<
		Type,
		float
	>,
	boost::is_same<
		Type,
		double
	>
>
{};

}
}

#endif
