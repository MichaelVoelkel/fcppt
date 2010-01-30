//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/inner_context_node.hpp>

fcppt::log::detail::inner_context_node::inner_context_node(
	string const &name_
)
:
	name_(name_)
{}

fcppt::string const &
fcppt::log::detail::inner_context_node::name() const
{
	return name_;
}
