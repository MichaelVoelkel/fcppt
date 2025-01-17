//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/next_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::next_power_of_2", "[math]")
{
  CHECK(fcppt::math::next_power_of_2(0U) == 1U);

  CHECK(fcppt::math::next_power_of_2(1U) == 1U);

  CHECK(fcppt::math::next_power_of_2(2U) == 2U);

  CHECK(fcppt::math::next_power_of_2(3U) == 4U);

  CHECK(fcppt::math::next_power_of_2(4U) == 4U);
}

FCPPT_CATCH_END
