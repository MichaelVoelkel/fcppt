//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/enum/to_static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class my_enum
{
  test1,
  test2,
  test3,
  fcppt_maximum = test3
};

}

FCPPT_CATCH_BEGIN

TEST_CASE("enum::to_static", "[enum]")
{
  fcppt::enum_::to_static(
      my_enum::test3,
      []<my_enum Value>(std::integral_constant<my_enum, Value>)
      { CHECK(Value == my_enum::test3); });
}

FCPPT_CATCH_END
