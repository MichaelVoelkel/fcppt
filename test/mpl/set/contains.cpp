//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/object.hpp>

int main()
{
  using set = fcppt::mpl::set::object<bool, float>;

  static_assert(fcppt::mpl::set::contains<set,bool>::value);
  static_assert(fcppt::mpl::set::contains<set,float>::value);
  static_assert(!fcppt::mpl::set::contains<set,double>::value);
}
