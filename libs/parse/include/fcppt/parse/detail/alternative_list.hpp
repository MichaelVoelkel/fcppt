//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_ALTERNATIVE_LIST_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_ALTERNATIVE_LIST_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename T
>
struct alternative_list
{
	typedef
	::metal::list<
		T
	>
	type;
};

template<
	typename... List
>
struct alternative_list<
	fcppt::variant::object<
		List...
	>
>
{
	typedef
	fcppt::variant::types_of<
		fcppt::variant::object<
			List...
		>
	>
	type;
};

}
}
}

#endif
