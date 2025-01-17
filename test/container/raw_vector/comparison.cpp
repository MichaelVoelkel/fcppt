//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/raw_vector/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::raw_vector comparison", "[container],[raw_vector]")
{
  using int_vector = fcppt::container::raw_vector::object<int>;

  int_vector const test1{1, 2};

  int_vector const test2{2, 3};

  int_vector const test3{1, 2};

  CHECK(test1 == test3);

  CHECK(test1 != test2);

  CHECK(test1 < test2);

  CHECK(test2 > test1);
}

FCPPT_CATCH_END
