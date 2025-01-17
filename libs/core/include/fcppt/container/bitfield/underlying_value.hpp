//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_UNDERLYING_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_UNDERLYING_VALUE_HPP_INCLUDED

#include <fcppt/array/get.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::bitfield
{
/**
\brief Returns the underlying value of a bitfield.

\ingroup fcpptcontainerbitfield

Returns the underlying value of \a _bitfield. This function can only be called
if the bitfield consists of exactly one underlying value (which means that
<code>_bitfield::array_size::value == 1U</code>).
*/
template <
    typename ElementType,
    typename InternalType,
    typename = std::enable_if_t<
        fcppt::container::bitfield::object<ElementType, InternalType>::array_size::value == 1U>>
typename fcppt::container::bitfield::object<ElementType, InternalType>::internal_type
underlying_value(fcppt::container::bitfield::object<ElementType, InternalType> const &_bitfield)
{
  return fcppt::array::get<0>(_bitfield.array());
}
}

#endif
