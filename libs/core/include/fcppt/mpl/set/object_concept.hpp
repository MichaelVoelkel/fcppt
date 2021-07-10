//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_OBJECT_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_SET_OBJECT_CONCEPT_HPP_INCLUDED

#include <fcppt/mpl/set/is_object.hpp>

namespace fcppt::mpl::set
{

/**
\brief Concept for sets.
\ingroup fcpptmpl
\see fcppt::mpl::set::is_object
*/
template<typename T>
concept object_concept = fcppt::mpl::set::is_object<T>::value;

}

#endif
