//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::output", "[container]")
{
  using int_vector = std::vector<int>;

  int_vector const input{1, 2};

  {
    std::ostringstream stream{};

    stream << fcppt::container::output(input);

    CHECK(stream.str() == std::string("[1,2]"));
  }

  {
    std::wostringstream stream{};

    stream << fcppt::container::output(input);

    CHECK(stream.str() == std::wstring(L"[1,2]"));
  }
}

FCPPT_CATCH_END
