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


#ifndef SGE_CONTAINER_BITFIELD_PROXY_HPP_INCLUDED
#define SGE_CONTAINER_BITFIELD_PROXY_HPP_INCLUDED

#include <sge/container/bitfield/proxy_fwd.hpp>
#include <sge/container/bitfield/size_type.hpp>
#include <sge/container/bitfield/value_type.hpp>

namespace sge
{
namespace container
{
namespace bitfield
{

template<
	typename StoredType,
	size_type ElementBits
>
class proxy {
	proxy(
		StoredType array,
		size_type pos
	);

	StoredType array;
	size_type const pos;

	template<
		typename,
		typename,
		size_type
	> friend class iterator;

	static size_type
	bit_offset(
		size_type p);

	static size_type
	array_offset(
		size_type p);
public:
	proxy &
	operator=(
		value_type);

	operator value_type() const;
};

}
}
}

#endif
