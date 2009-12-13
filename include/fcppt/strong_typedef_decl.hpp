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


#ifndef SGE_STRONG_TYPEDEF_DECL_HPP_INCLUDED
#define SGE_STRONG_TYPEDEF_DECL_HPP_INCLUDED

#include <sge/strong_typedef_fwd.hpp>

namespace sge
{

template<
	typename T,
	typename Tag
>
class strong_typedef {
public:
	typedef T value_type;

	typedef Tag tag_type;

	strong_typedef();

	template<
		typename U
	>
	explicit strong_typedef(
		U const &t
	);

	template<
		typename U
	>
	strong_typedef &
	operator=(
		U const &
	);

	operator T &();

	operator T const &() const;

	bool
	operator< (
		strong_typedef const &
	) const;
private:
	T t;
};

}

#endif
