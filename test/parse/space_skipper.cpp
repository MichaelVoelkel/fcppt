//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/space_skipper.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::space_skipper",
	"[parse]"
)
{
	auto const parser{
		*fcppt::parse::char_{}
	};

	typedef
	fcppt::parse::result_of<
		decltype(
			parser
		)
	>
	result_type;

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::space_skipper()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				" \t"
			},
			fcppt::parse::space_skipper()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				" \t\nab"
			},
			fcppt::parse::space_skipper()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{
				'a', 'b'
			}
		)
	);
}
