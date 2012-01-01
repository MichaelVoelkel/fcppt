//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_IS_STD_VECTOR_HPP_INCLUDED
#define FCPPT_CONTAINER_IS_STD_VECTOR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{

/**
\brief Metafunction to test if a container is a <code>std::%vector</code>
\ingroup fcpptcontainer
*/
template<
	typename T
>
struct is_std_vector
:
boost::false_type
{};

// Without this, doxygen generates another raw_vector type (wtf?)
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename A
>
struct is_std_vector<
	std::vector<
		T,
		A
	>
>
:
boost::true_type
{};
/// \endcond

}
}

#endif
