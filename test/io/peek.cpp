//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/peek.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::peek", "[io]")
{
  using optional_char = fcppt::optional::object<char>;

  {
    std::istringstream stream{"x"};

    CHECK(fcppt::io::peek(stream) == optional_char{'x'});
  }

  {
    std::istringstream stream{};

    CHECK(fcppt::io::peek(stream) == optional_char{});
  }
}

FCPPT_CATCH_END
