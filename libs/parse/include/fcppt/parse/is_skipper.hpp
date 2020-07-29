//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_IS_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_IS_SKIPPER_HPP_INCLUDED

#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Type
>
using
is_skipper
=
std::conjunction<
	fcppt::parse::is_parser<
		Type
	>,
	std::is_same<
		fcppt::parse::result_of<
			Type
		>,
		fcppt::unit
	>
>;

}
}

#endif