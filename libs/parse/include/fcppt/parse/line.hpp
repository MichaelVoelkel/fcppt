//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LINE_HPP_INCLUDED
#define FCPPT_PARSE_LINE_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief The line type of a position.
\ingroup fcpptparse
*/
FCPPT_DECLARE_STRONG_TYPEDEF(std::uint64_t, line);

}

#endif
