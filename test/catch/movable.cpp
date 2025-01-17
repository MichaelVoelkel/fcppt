//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/make_movable.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("catch::movable", "[catch]")
{
  using movable = fcppt::catch_::movable<int>;

  CHECK(movable{10} == movable{10});

  CHECK(movable{10} == fcppt::catch_::make_movable(10));

  {
    int const value{10};

    CHECK(movable{value} == movable{10});
  }
}

FCPPT_CATCH_END
