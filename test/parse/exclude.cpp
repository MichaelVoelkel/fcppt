//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_literal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/operators/exclude.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::exclude", "[parse]")
{
  auto const parser{fcppt::parse::char_{} - fcppt::parse::make_literal('x')};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"x"}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"y"}) ==
      fcppt::parse::make_parse_string_success<char>('y'));
}

FCPPT_CATCH_END
