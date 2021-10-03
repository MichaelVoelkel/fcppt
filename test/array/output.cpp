//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/array/output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("array output", "[array]")
{
  CHECK(fcppt::output_to_std_string(fcppt::array::object<int, 2U>{5, 10}) == "[5,10]");
}

FCPPT_CATCH_END
