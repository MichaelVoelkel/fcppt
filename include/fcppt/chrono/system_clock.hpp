/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CHRONO_SYSTEM_CLOCK_HPP_INCLUDED
#define SGE_CHRONO_SYSTEM_CLOCK_HPP_INCLUDED

#include <sge/chrono/system_clock_fwd.hpp>
#include <sge/chrono/duration_fwd.hpp>
#include <sge/chrono/time_point_fwd.hpp>
#include <sge/ratio.hpp>
#include <sge/export.hpp>
#include <ctime>

namespace sge
{
namespace chrono
{

class system_clock {
public:
	typedef unsigned long rep;

	typedef sge::micro period;

	typedef chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		system_clock
	> time_point;

	static bool const is_monotonic = false;

	SGE_SYMBOL static
	time_point
	now();

	SGE_SYMBOL static
	std::time_t
	to_time_t(
		time_point const &
	);

	SGE_SYMBOL
	static time_point
	from_time_t(
		std::time_t
	);
};

}
}

#endif
