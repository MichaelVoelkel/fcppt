//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/log/format/create_chain.hpp>


fcppt::log::format::const_object_ptr const
fcppt::log::format::create_chain(
	format::const_object_ptr const _parent,
	format::const_object_ptr const _child
)
{
	FCPPT_ASSERT_PRE(
		_parent
		||
		_child
	);

	if(
		!_parent
	)
		return _child;

	if(
		!_child
	)
		return _parent;

	return
		fcppt::make_shared_ptr<
			format::chain
		>(
			_parent,
			_child
		);
}
