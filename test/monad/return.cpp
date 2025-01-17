//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit_fwd.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/monad/return.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/monad.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("monad::return", "[optional]")
{
  CHECK(fcppt::monad::return_<fcppt::optional::object<fcppt::unit>>(5) == fcppt::optional::make(5));
}

FCPPT_CATCH_END
