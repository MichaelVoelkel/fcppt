//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
struct function
{
  template <typename T1, typename T2, typename T3>
  void operator()(T1 const &, T2 const &, T3 const &) const
  {
    CHECK(false);
  }

  void operator()(bool const _bool, int const _int, std::string const &_string) const
  {
    CHECK_FALSE(_bool);

    CHECK(_int == 1);

    CHECK(_string == "foo");
  }
};

}

FCPPT_CATCH_BEGIN

TEST_CASE("variant::apply prvalue", "[variant]")
{
  using variant = fcppt::variant::object<bool, int, std::string>;

  std::string const string("foo");

  fcppt::variant::apply(function(), variant(false), variant(1), variant(string));
}

FCPPT_CATCH_END
