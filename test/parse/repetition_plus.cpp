//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition_plus.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::repetition_plus", "[parse]")
{
  auto const parser{+fcppt::parse::char_{}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"XYZ"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{'X', 'Y', 'Z'}));
}

FCPPT_CATCH_END
