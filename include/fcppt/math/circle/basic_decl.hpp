//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CIRCLE_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/circle/basic_fwd.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/basic_decl.hpp>

namespace fcppt
{
namespace math
{
namespace circle
{

template<
	typename T
>
class basic
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef T const &const_reference;

	typedef typename vector::static_<
		value_type,
		2
	>::type point_type;

	basic(
		point_type const &origin,
		const_reference radius
	);

	point_type &
	origin();

	point_type const &
	origin() const;

	reference
	radius();

	const_reference
	radius() const;
private:
	point_type origin_;
	value_type radius_;
};

}
}
}

#endif
