//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/math/mod.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/at_c.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculate vector modulo a scalar

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::vector::static_<
	T,
	N
>
mod(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_arg,
	T const _div
)
{
	typedef
	fcppt::math::vector::static_<
		T,
		N
	>
	result_type;

	return
		fcppt::math::vector::init<
			result_type
		>(
			[
				&_arg,
				_div
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::math::mod(
						fcppt::math::vector::at_c<
							_index
						>(
							_arg
						),
						_div
					);
			}
		);
}

/**
\brief Calculate vector modulo a vector

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
fcppt::math::vector::static_<
	T,
	N
>
mod(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &_v0,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &_v1
)
{
	typedef
	fcppt::math::vector::static_<
		T,
		N
	>
	result_type;

	return
		fcppt::math::vector::init<
			result_type
		>(
			[
				&_v0,
				&_v1
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::math::mod(
						fcppt::math::vector::at_c<
							_index
						>(
							_v0
						),
						fcppt::math::vector::at_c<
							_index
						>(
							_index
						)
					);
			}
		);
}

}
}
}

#endif
