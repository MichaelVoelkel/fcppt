//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/bit/shift_count.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/bitfield/underlying_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::bitfield::underlying_value", "[container],[bitfield]")
{
  enum class test_enum
  {
    test1,
    test2,
    test3,
    fcppt_maximum = test3
  };

  using bitfield = fcppt::container::bitfield::object<test_enum>;

  using internal_type = bitfield::internal_type;

  auto const check_bit([](internal_type const _value, test_enum const _enum) -> bool {
    return fcppt::bit::test(
        _value,
        fcppt::bit::shifted_mask<bitfield::internal_type>(
            fcppt::cast::enum_to_int<fcppt::bit::shift_count>(_enum)));
  });

  bitfield field1(bitfield::null());

  field1[test_enum::test2] = true;

  bitfield::internal_type const value(fcppt::container::bitfield::underlying_value(field1));

  CHECK_FALSE(check_bit(value, test_enum::test1));

  CHECK(check_bit(value, test_enum::test2));

  CHECK_FALSE(check_bit(value, test_enum::test3));
}

FCPPT_CATCH_END
