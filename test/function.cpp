//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/function.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

template class fcppt::function<int(int)>;

FCPPT_CATCH_BEGIN

TEST_CASE("function", "[various]")
{
  using function_type = fcppt::function<int(int)>;

  function_type const fun{[](int const _val) { return _val + 10; }};

  CHECK(fun(5) == 15);
}

TEST_CASE("function move", "[various]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using function_type = fcppt::function<int(int_unique_ptr &&)>;

  function_type const fun{[](int_unique_ptr &&_val) { return *_val + 10; }};

  CHECK(fun(fcppt::make_unique_ptr<int>(5)) == 15);
}

FCPPT_CATCH_END
