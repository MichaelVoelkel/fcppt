//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_MACH_TIMEBASE_HPP_INCLUDED
#define FCPPT_CHRONO_MACH_TIMEBASE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <mach/mach_time.h>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{

struct mach_timebase_info const
mach_timebase();

}
}

#endif
