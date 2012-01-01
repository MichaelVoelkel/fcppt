//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/info.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/parameters/with_context.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int main()
try
{
	fcppt::log::context context;

	fcppt::io::ostream &output_stream(
		fcppt::io::cout()
	);

	fcppt::log::level::type const level(
		fcppt::log::level::debug
	);

	fcppt::log::location const root_location(
		FCPPT_TEXT("fcppt")
	);

	fcppt::log::object logger(
		fcppt::log::parameters::with_context(
			context,
			output_stream,
			root_location
		)
		.level_defaults(
			level
		)
		.enabled(
			true
		)
	);

	fcppt::log::location const child_location(
		root_location
		/
		FCPPT_TEXT("child")
	);

	fcppt::log::object child_logger(
		fcppt::log::parameters::with_context(
			context,
			output_stream,
			child_location
		)
		.level_defaults(
			level
		)
		// not enabled
	);

	fcppt::log::optional_object const ref(
		context.find(
			logger.context_location()->location()
		)
	);

	FCPPT_ASSERT_ERROR(
		ref.has_value()
	);

	FCPPT_LOG_INFO(
		*ref,
		fcppt::log::_
			<< FCPPT_TEXT("test output!")
	);

	fcppt::log::optional_object const child_ref(
		context.find(
			child_location
		)
	);

	FCPPT_ASSERT_ERROR(
		child_ref.has_value()
	);

	fcppt::io::cout()
		<< FCPPT_TEXT("location of child: ")
		<< child_ref->context_location()->location().string()
		<< FCPPT_TEXT('\n');

	FCPPT_LOG_INFO(
		*child_ref,
		fcppt::log::_
			<< FCPPT_TEXT("child output!")
	);

	context.apply(
		logger.context_location()->location(),
		std::tr1::bind(
			&fcppt::log::object::enable,
			std::tr1::placeholders::_1,
			false
		)
	);

	FCPPT_LOG_INFO(
		*child_ref,
		fcppt::log::_
			<< FCPPT_TEXT("shouldn't be shown!")
	);
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
