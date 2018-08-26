//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_FIND_OR_CREATE_CHILD_HPP_INCLUDED
#define FCPPT_LOG_IMPL_FIND_OR_CREATE_CHILD_HPP_INCLUDED

#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace impl
{

fcppt::log::detail::context_tree &
find_or_create_child(
	fcppt::log::detail::context_tree &,
	fcppt::log::name const &
);

}
}
}

#endif
