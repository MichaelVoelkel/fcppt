//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object_fwd.hpp>
#include <fcppt/array/size.hpp>

int main()
{
  using array = fcppt::array::object<int,2U>;
  static_assert(fcppt::array::size<array>::value == 2U);
}
