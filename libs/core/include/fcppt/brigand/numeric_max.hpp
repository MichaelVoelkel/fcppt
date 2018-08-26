//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_NUMERIC_MAX_HPP_INCLUDED
#define FCPPT_BRIGAND_NUMERIC_MAX_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Metafunction to compute the maximum value of a type.

\ingroup fcpptbrigand

\tparam Type Must be a type such that <code>std::numeric_limits<Type>::max()</code> is defined.
*/
template<
	typename Type
>
using
numeric_max
=
std::integral_constant<
	Type,
	std::numeric_limits<
		Type
	>::max()
>;

}
}

#endif
