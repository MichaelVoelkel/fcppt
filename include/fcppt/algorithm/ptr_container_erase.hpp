//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{
template<
	typename Container,
	typename Ptr>
void ptr_container_erase(
	Container &,
	Ptr);
}
}

#include "detail/ptr_container_erase_impl.hpp"

#endif
