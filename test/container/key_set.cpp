//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/key_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <set>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container key_set"
          "[container_key_set]")
{
  using int_set = std::set<int>;

  using int_string_map = std::map<int, std::string>;

  CHECK(
      fcppt::container::key_set<int_set>(int_string_map{
          std::make_pair(42, std::string("test")), std::make_pair(10, std::string("test2"))}) ==
      int_set{10, 42});
}

FCPPT_CATCH_END
