//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/union.hpp>

int main()
{
  using result = fcppt::metal::set::union_<
      fcppt::metal::set::make<
          short, // NOLINT(google-runtime-int)
          int>,
      fcppt::metal::set::make<
          int,
          long // NOLINT(google-runtime-int)
          >>;

  static_assert(fcppt::metal::set::contains<result, int>::value, "Set does not contain int");

  static_assert(
      fcppt::metal::set::contains<
          result,
          short // NOLINT(google-runtime-int)
          >::value,
      "Set does not contain short");

  static_assert(
      fcppt::metal::set::contains<
          result,
          long // NOLINT(google-runtime-int)
          >::value,
      "Set does not contain long");
}
