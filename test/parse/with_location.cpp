//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/parse/column.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/line.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/location_output.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/make_with_location.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("parse::with_location", "[parse]")
{
  auto const parser{fcppt::parse::make_with_location(fcppt::parse::literal{'X'})};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X"}) ==
      fcppt::parse::make_success<char>(fcppt::tuple::make(
          fcppt::optional::make(
              fcppt::parse::location{fcppt::parse::line{1U}, fcppt::parse::column{1U}}),
          fcppt::unit{})));

  CHECK(fcppt::parse::parse_string(parser, std::string{"Y"}).has_failure());
}