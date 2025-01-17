//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("either::failure_opt", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using optional_string = fcppt::optional::object<std::string>;

  CHECK(
      fcppt::either::failure_opt(either_int(std::string("test"))) ==
      optional_string(std::string("test")));

  CHECK(fcppt::either::failure_opt(either_int(42)) == optional_string());
}

FCPPT_CATCH_END
