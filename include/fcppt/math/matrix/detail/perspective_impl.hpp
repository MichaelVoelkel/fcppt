//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_PERSPECTIVE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_PERSPECTIVE_IMPL_HPP_INCLUDED

#include <fcppt/math/compare.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <cmath>

template<
	typename T
>
typename fcppt::math::matrix::static_<T, 4, 4>::type const
fcppt::math::matrix::perspective(
	T const aspect,
	T const fov,
	T const near,
	T const far)
{
	if(compare(far, near))
		throw exception(
			FCPPT_TEXT("matrix::perspective(): far may not be near!")
		);

	if(almost_zero(near))
		throw exception(
			FCPPT_TEXT("matrix::perspective(): near must not be 0!")
		);

	T const
		h = static_cast<T>(1) / std::tan(fov / static_cast<T>(2)),
		w = h / aspect,
		q = (far + near) / (near - far),
		p = static_cast<T>(2) * far * near / (near - far),
		zero = static_cast<T>(0);

	return typename static_<T, 4, 4>::type
	       (w, zero, zero, zero,
	        zero, h, zero, zero,
	        zero, zero, q, static_cast<T>(-1),
	        zero, zero, p, zero);
}

#endif
