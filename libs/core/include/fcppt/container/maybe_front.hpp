//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_MAYBE_FRONT_HPP_INCLUDED
#define FCPPT_CONTAINER_MAYBE_FRONT_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/reference.hpp>

namespace fcppt::container
{
/**
\brief Returns the front of a container as an optional.

\ingroup fcpptcontainer
*/
template <typename Container>
fcppt::optional::reference<fcppt::container::to_value_type<Container>>
maybe_front(Container &_container)
{
  using result_type = fcppt::optional::reference<fcppt::container::to_value_type<Container>>;

  return _container.empty() ? result_type{} : result_type{fcppt::make_ref(_container.front())};
}

}

#endif
