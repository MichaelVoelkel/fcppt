//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_IS_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_IS_SKIPPER_HPP_INCLUDED

#include <fcppt/parse/skipper/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
template <typename Type>
using is_skipper = std::is_base_of<fcppt::parse::skipper::tag, Type>;

}
}
}

#endif