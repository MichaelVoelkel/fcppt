//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/promote_int.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("cast::promote_int", "[cast]")
{
  CHECK(fcppt::cast::promote_int('c') == 'c');

  static_assert(std::is_same_v<decltype(fcppt::cast::promote_int('c')), decltype(+'c')>);
}

FCPPT_CATCH_END
