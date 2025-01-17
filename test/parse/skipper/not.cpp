//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/no_error_comparison.hpp>
#include <fcppt/either/no_error_output.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/skipper/any.hpp>
#include <fcppt/parse/skipper/literal.hpp>
#include <fcppt/parse/skipper/operators/not.hpp>
#include <fcppt/parse/skipper/operators/sequence.hpp>
#include <fcppt/test/parse/skipper/make_success.hpp>
#include <fcppt/test/parse/skipper/skip_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::skipper::not", "[parse]")
{
  auto const parser{!fcppt::parse::skipper::literal{'X'} >> fcppt::parse::skipper::any{}};

  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{"XY"}).has_failure());

  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{"Y"}) ==
      fcppt::test::parse::skipper::make_success<char>());
}

FCPPT_CATCH_END
