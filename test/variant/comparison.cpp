//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/type_info.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("variant equal", "[variant]")
{
  using variant = fcppt::variant::object<bool, int, std::string>;

  std::string const string("hello world");

  variant const v1(string);

  variant const v2(string);

  CHECK(v1 == v2);

  variant const v3(42);

  CHECK(v1 != v3);

  CHECK(fcppt::variant::type_info(v1) == fcppt::variant::type_info(v2));
}

TEST_CASE("variant less", "[variant]")
{
  using variant = fcppt::variant::object<int, std::string>;

  variant const v1(10);

  variant const v2(20);

  CHECK(v1 < v2);

  CHECK_FALSE(v2 < v1);

  variant const v3(std::string("hello world"));

  CHECK(v1 < v3);

  CHECK_FALSE(v3 < v1);
}

FCPPT_CATCH_END
