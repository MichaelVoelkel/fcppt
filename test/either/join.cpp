//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/join.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("either::join", "[either]")
{
  using inner_either = fcppt::either::object<int, std::string>;

  using outer_either = fcppt::either::object<int, inner_either>;

  CHECK(fcppt::either::join(outer_either(5)) == inner_either(5));

  CHECK(fcppt::either::join(outer_either(inner_either(5))) == inner_either(5));

  CHECK(
      fcppt::either::join(outer_either(inner_either(std::string("test")))) ==
      inner_either(std::string("test")));
}

FCPPT_CATCH_END
