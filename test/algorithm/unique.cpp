//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/unique.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_unique
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector vec{
		1,
		1,
		2,
		2,
		3
	};

	fcppt::algorithm::unique(
		vec
	);

	BOOST_REQUIRE_EQUAL(
		vec.size(),
		3u
	);

	BOOST_CHECK_EQUAL(
		vec[0],
		1
	);

	BOOST_CHECK_EQUAL(
		vec[1],
		2
	);

	BOOST_CHECK_EQUAL(
		vec[2],
		3
	);
}