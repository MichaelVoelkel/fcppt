//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object_impl.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/from_array.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

TEST_CASE("tuple::from_array", "[tuple]")
{
  CHECK(
      fcppt::tuple::from_array(fcppt::array::object<int, 3>{
          1,
          2,
          3,
      }) == fcppt::tuple::make(1, 2, 3));
}
