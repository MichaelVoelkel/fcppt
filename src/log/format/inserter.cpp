//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/format.hpp>
#include <fcppt/log/format/inserter.hpp>


fcppt::log::format::inserter::inserter(
	string const &_format_string
)
:
	format_string_(_format_string)
{}

fcppt::string const
fcppt::log::format::inserter::format(
	string const &_dest
) const
{
	return
		(
			fcppt::format(
				format_string_
			)
			% _dest
		).str();
}
