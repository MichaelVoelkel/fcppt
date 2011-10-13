//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/default_locale.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

namespace
{

std::locale global;

char const *
probe_locale();

struct init
{
	init();
} instance;

}

std::locale const
fcppt::default_locale()
{
	return global;
}

namespace
{

char const *
probe_locale()
{
	if(
		char const *const lc_all =
			std::getenv(
				"LC_ALL"
			)
	)
		return lc_all;

	if(
		char const *const lc_ctype =
			std::getenv(
				"LC_CTYPE"
			)
	)
		return lc_ctype;

	if(
		char const *const lang =
			std::getenv(
				"LANG"
			)
	)
		return lang;

	return 0;
}

init::init()
{
	char const *const locale_name(
		probe_locale()
	);

	if(
		locale_name
	)
		global =
			std::locale(
				locale_name
			);
}

}
