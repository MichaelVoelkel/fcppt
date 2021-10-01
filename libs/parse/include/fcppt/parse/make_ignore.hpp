//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_IGNORE_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_IGNORE_HPP_INCLUDED

#include <fcppt/parse/ignore_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates an #fcppt::parse::ignore parser.
\ingroup fcpptparse
*/
template <typename Parser>
fcppt::parse::ignore<std::remove_cvref_t<Parser>> make_ignore(Parser &&_parser)
{
  return fcppt::parse::ignore<std::remove_cvref_t<Parser>>{
      std::forward<Parser>(_parser)};
}

}

#endif
