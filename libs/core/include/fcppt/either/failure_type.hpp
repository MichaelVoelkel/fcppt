//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FAILURE_TYPE_HPP_INCLUDED
#define FCPPT_EITHER_FAILURE_TYPE_HPP_INCLUDED

#include <fcppt/either/detail/failure_type.hpp>

namespace fcppt
{
namespace either
{
/**
\brief The failure type of an either.

\ingroup fcppteither

\tparam Either Must be an #fcppt::either::object.
*/
template <typename Either>
using failure_type = typename fcppt::either::detail::failure_type<Either>::type;

}
}

#endif
