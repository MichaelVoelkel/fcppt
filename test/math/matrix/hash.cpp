//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/object.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::matrix::hash", "[math],[matrix]")
{
  using int22_matrix = fcppt::math::matrix::static_<int, 2, 2>;

  using matrix_set = std::unordered_set<int22_matrix>;

  matrix_set const set{
      int22_matrix(fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4))};

  CHECK(set.contains(int22_matrix(fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4))));

  CHECK_FALSE(
      set.contains(int22_matrix(fcppt::math::matrix::row(4, 2), fcppt::math::matrix::row(3, 4))));
}

FCPPT_CATCH_END
