//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_SPACE_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_SPACE_HPP_INCLUDED

#include <fcppt/parse/skipper/basic_space.hpp>

namespace fcppt::parse::skipper
{
/**
\brief The skipper <code>basic_space<char></code>.
\ingroup fcpptparse
*/
inline auto space() { return fcppt::parse::skipper::basic_space<char>(); }

}

#endif
