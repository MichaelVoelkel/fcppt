//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/grid/clamped_sup_signed.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::grid::clamped_sup_signed", "[container],[grid]")
{
  using dim = fcppt::container::grid::dim<unsigned, 2>;

  using pos = fcppt::container::grid::pos<int, 2>;

  CHECK(
      fcppt::container::grid::clamped_sup_signed(pos(-1, 5), dim(3U, 3U)).get() ==
      fcppt::math::vector::to_unsigned(pos(0, 3)));
}

FCPPT_CATCH_END
