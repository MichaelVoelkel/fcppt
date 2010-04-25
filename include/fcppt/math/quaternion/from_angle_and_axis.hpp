#ifndef FCPPT_MATH_QUATERNION_FROM_ANGLE_AND_AXIS_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_FROM_ANGLE_AND_AXIS_HPP_INCLUDED

#include <fcppt/math/quaternion/from_scalar_and_vector.hpp>
#include <fcppt/math/quaternion/is_normalized.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/assert.hpp>
#include <boost/math/quaternion.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace quaternion
{
/**
 * Initializes a quaternion from an axis and an angle. See also: from_scalar_and_vector.
 */
template<typename T>
boost::math::quaternion<T> const 
from_angle_and_axis(
	T const &angle,
	typename fcppt::math::vector::static_<T,3>::type const &axis)
{
	T const 
		half_angle = 
			angle/static_cast<T>(2),
		sin_angle = 
			std::sin(
				half_angle),
		cos_angle = 
			std::cos(
				half_angle);

	return 
		from_scalar_and_vector<T>(
			cos_angle,
			sin_angle * axis);
}
}
}
}

#endif
