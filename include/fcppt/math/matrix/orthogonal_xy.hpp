//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ORTHOGONAL_XY_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ORTHOGONAL_XY_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/static.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T
>
typename static_<T, 4, 4>::type const
orthogonal_xy();

}
}
}

#include <fcppt/math/matrix/detail/orthogonal_xy_impl.hpp>

#endif
