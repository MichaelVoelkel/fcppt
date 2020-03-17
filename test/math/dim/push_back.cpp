//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/push_back.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dim::push_back",
	"[math],[dim]"
)
{
	using
	i2_dim
	=
	fcppt::math::dim::static_<
		int,
		2
	>;

	using
	i3_dim
	=
	fcppt::math::dim::static_<
		int,
		3
	>;

	CHECK(
		i3_dim(
			1,
			2,
			3
		)
		==
		fcppt::math::dim::push_back(
			i2_dim(
				1,
				2
			),
			3
		)
	);
}
