//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/log2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::log2", "[math]")
{
  CHECK(fcppt::math::log2(1U) == 0U);

  CHECK(fcppt::math::log2(2U) == 1U);

  CHECK(fcppt::math::log2(4U) == 2U);

  CHECK(fcppt::math::log2(8U) == 3U);
}

FCPPT_CATCH_END
