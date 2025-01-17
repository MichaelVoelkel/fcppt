//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::make", "[assign]")
{
  using sequence = std::vector<fcppt::unique_ptr<int>>;

  auto const result(fcppt::container::make<sequence>(
      fcppt::make_unique_ptr<int>(3), fcppt::make_unique_ptr<int>(4), fcppt::make_unique_ptr<int>(5)

          ));

  REQUIRE(result.size() == 3U);

  CHECK(*result[0] == 3);

  CHECK(*result[1] == 4);

  CHECK(*result[2] == 5);
}

FCPPT_CATCH_END
