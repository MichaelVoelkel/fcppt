//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/istringstream.hpp>
#include <fcppt/io/narrow_string.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::narrow_string", "[io]")
{
  fcppt::io::istringstream stream{FCPPT_TEXT("test")};
  fcppt::string result{};
  stream >> result;

  CHECK(
      fcppt::io::narrow_string(stream, fcppt::string_view{result}) ==
      fcppt::optional::make(std::string{"test"}));
}

FCPPT_CATCH_END
