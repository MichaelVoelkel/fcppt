//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/normalize.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_vector_normalize
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		float,
		2
	>
	float2_vec;

	BOOST_CHECK(
		fcppt::math::vector::normalize(
			float2_vec{
				2.f,
				0.f
			}
		).has_value()
	);

	BOOST_CHECK(
		!fcppt::math::vector::normalize(
			float2_vec{
				0.f,
				0.f
			}
		).has_value()
	);
}