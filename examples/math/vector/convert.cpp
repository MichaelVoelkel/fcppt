//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[vectorconvert
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int main()
{
	typedef fcppt::math::vector::static_<
		float,
		2
	>::type float2_vec;

	float2_vec const vecf2(
		1.5f,
		2.0f
	);

	typedef fcppt::math::vector::static_<
		unsigned,
		2
	>::type unsigned2_vec;

	// cast all the elements from float to unsigned int
	unsigned2_vec const vecui2(
		fcppt::math::vector::structure_cast<
			unsigned2_vec
		>(
			vecf2
		)
	);

	std::cout << vecui2 << '\n';

	typedef fcppt::math::vector::static_<
		unsigned,
		3
	>::type unsigned3_vec;

	// construct a three dimensional vector from a two dimensional one
	unsigned3_vec const vecui3(
		fcppt::math::vector::construct(
			vecui2,
			42u
		)
	);

	std::cout << vecui3 << '\n';

	// throw away the newly added element
	unsigned2_vec const vecui2n(
		fcppt::math::vector::narrow_cast<
			unsigned2_vec
		>(
			vecui3
		)
	);

	std::cout << vecui2n << '\n';
}

//]

