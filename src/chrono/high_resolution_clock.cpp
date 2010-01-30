//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/config.h>
#ifdef FCPPT_WINDOWS_PLATFORM
#include "performance_counter_time.hpp"
#elif FCPPT_POSIX_PLATFORM
#include "clock_gettime_impl.hpp"
#include <time.h>
#else
#error "high_resolution_clock implementation missing"
#endif

fcppt::chrono::high_resolution_clock::time_point
fcppt::chrono::high_resolution_clock::now()
{
#ifdef FCPPT_WINDOWS_PLATFORM
	return performance_counter_time<
		time_point
	>();
#elif FCPPT_POSIX_PLATFORM
	return clock_gettime_impl<
		time_point
	>(
		CLOCK_REALTIME
	);
#endif
}
