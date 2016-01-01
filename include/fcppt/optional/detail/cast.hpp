//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_CAST_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_CAST_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>


#define FCPPT_OPTIONAL_DETAIL_CAST(\
	cast_type\
)\
_optional.has_value() \
? \
	fcppt::optional::object< \
		Result & \
	>( \
		cast_type< \
			Result & \
		>( \
			_optional.get_unsafe() \
		) \
	) \
: \
	fcppt::optional::object< \
		Result & \
	>()

#endif