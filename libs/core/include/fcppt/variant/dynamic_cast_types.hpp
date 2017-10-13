//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DYNAMIC_CAST_TYPES_HPP_INCLUDED
#define FCPPT_VARIANT_DYNAMIC_CAST_TYPES_HPP_INCLUDED

#include <fcppt/add_reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief The variant element types used for \link fcppt::variant::dynamic_cast_\endlink.

\ingroup fcpptvariant
*/
template<
	typename Types
>
using
dynamic_cast_types
=
typename
boost::mpl::transform<
	Types,
	fcppt::add_reference<
		boost::mpl::_1
	>
>::type;

}
}

#endif