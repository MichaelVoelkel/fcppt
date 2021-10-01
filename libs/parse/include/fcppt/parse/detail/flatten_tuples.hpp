//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_FLATTEN_TUPLES_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_FLATTEN_TUPLES_HPP_INCLUDED

#include <fcppt/parse/detail/make_tuple.hpp>
#include <fcppt/tuple/concat.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename... Types>
auto flatten_tuples(Types &&..._values)
{
  return fcppt::tuple::concat(fcppt::parse::detail::make_tuple(std::forward<Types>(_values))...);
}

}

#endif
