//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args.hpp>
#include <fcppt/args_char.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/detail/main_wchar.hpp>
#include <fcppt/iterator/make_range.hpp>
#if !defined(FCPPT_DETAIL_MAIN_WCHAR)
#include <fcppt/from_std_string.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <string>
#if !defined(FCPPT_DETAIL_MAIN_WCHAR)
#include <string_view>
#endif
#include <fcppt/config/external_end.hpp>


fcppt::args_vector fcppt::args(int const _argc, fcppt::args_char const *const *const _argv)
{
  return fcppt::algorithm::map<fcppt::args_vector>(
      fcppt::iterator::make_range(
          _argv,
          _argv + _argc // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
          ),
      [](fcppt::args_char const *const _arg) {
        return
#if defined(FCPPT_DETAIL_MAIN_WCHAR)
            // fcppt::string is std::wstring in this case
            std::basic_string<fcppt::args_char>{_arg};
#else
            fcppt::from_std_string(std::string_view{_arg});
#endif
      });
}
