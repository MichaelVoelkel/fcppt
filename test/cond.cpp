//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cond.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("cond"
          "[various]")
{
  CHECK(
      fcppt::cond(
          true, [] { return 1; }, [] { return 2; }) == 1);

  CHECK(
      fcppt::cond(
          false, [] { return 1; }, [] { return 2; }) == 2);
}

FCPPT_CATCH_END
