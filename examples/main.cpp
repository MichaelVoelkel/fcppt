//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
// ![print_at_2]
void print_at_2(std::vector<int> const &_vec)
{
  fcppt::optional::reference<int const> ref{fcppt::container::at_optional(_vec, 2)};

  fcppt::optional::maybe(
      ref,
      [] { std::cout << "No value at position 2\n"; },
      [](fcppt::reference<int const> _value) {
        std::cout << "The value is " << _value.get() << '\n';
      });
}
// ![print_at_2]

// ![vec_to_string]
std::vector<std::string> int_vec_to_string_vec(std::vector<int> &&_vec)
{
  return fcppt::algorithm::map<std::vector<std::string>>(
      std::move(_vec), [](int const _value) { return fcppt::output_to_std_string(_value); });
}
// ![vec_to_string]

// ![init_array]
template <std::size_t N>
struct make_value
{
  static constexpr unsigned int const value = fcppt::cast::size<unsigned int>(N);
};

template <std::size_t N>
fcppt::array::object<unsigned int, N> init_array()
{
  return fcppt::array::init<fcppt::array::object<unsigned int, N>>(
      []<std::size_t Index>(std::integral_constant<std::size_t, Index>)
      { return make_value<Index>::value; });
}
// ![init_array]
}

int main()
try
{
  print_at_2(std::vector<int>{});

  int_vec_to_string_vec(std::vector<int>{});

  init_array<4U>();
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
