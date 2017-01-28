//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_from_second.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main(
	int argc,
	char **argv
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::argument<
		arg_label,
		int
	>
	parser_type;

	parser_type const parser{
		fcppt::options::long_name{
			FCPPT_TEXT("arg1")
		},
		fcppt::options::optional_help_text{
			fcppt::options::help_text{
				FCPPT_TEXT("The main argument")
			}
		}
	};

	// ![options_parse_help]
	fcppt::options::help_result<
		parser_type::result_type
	> const result{
		fcppt::options::parse_help(
			fcppt::options::default_help_switch(),
			parser,
			fcppt::args_from_second(
				argc,
				argv
			)
		)
	};
	// ![options_parse_help]

	// ![options_help_match]
	fcppt::variant::match(
		result,
		[](
			fcppt::options::result<
				parser_type::result_type
			> const &
		)
		{
			// ...
		},
		[](
			fcppt::options::help_text const &_help_text
		)
		{
			fcppt::io::cout()
				<<
				_help_text
				<<
				FCPPT_TEXT('\n');
		}
	);
	// ![options_help_match]

	return
		EXIT_SUCCESS;
}
