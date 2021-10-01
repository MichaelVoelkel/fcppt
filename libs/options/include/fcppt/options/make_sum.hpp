//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MAKE_SUM_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_SUM_HPP_INCLUDED

#include <fcppt/options/sum_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief Creates the sum of two parsers.

\ingroup fcpptoptions
*/
template <typename Label, typename Left, typename Right>
inline fcppt::options::sum<Label, std::remove_cvref_t<Left>, std::remove_cvref_t<Right>>
make_sum(Left &&_left, Right &&_right)
{
  return fcppt::options::sum<Label, std::remove_cvref_t<Left>, std::remove_cvref_t<Right>>(
      std::forward<Left>(_left), std::forward<Right>(_right));
}
}

#endif
