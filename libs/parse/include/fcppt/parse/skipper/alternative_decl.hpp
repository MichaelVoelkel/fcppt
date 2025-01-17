//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_ALTERNATIVE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_ALTERNATIVE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/alternative_fwd.hpp>
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::parse::skipper
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Tries the left skipper, and if that fails also the right skipper.

\ingroup fcpptparse
*/
template <typename Left, typename Right>
class alternative : private fcppt::parse::skipper::tag
{
public:
  alternative(Left &&, Right &&);

  template <typename Ch>
  [[nodiscard]] fcppt::parse::skipper::result<Ch>
  skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;
private:
  Left left_;

  Right right_;
};

FCPPT_PP_POP_WARNING

}

#endif
