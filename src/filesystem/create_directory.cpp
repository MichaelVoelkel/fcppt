//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/create_directory.hpp>
#include <fcppt/filesystem/create_directory_failed.hpp>
#include <boost/filesystem/operations.hpp>

void
fcppt::filesystem::create_directory(
	path const &p
)
{
	if(
		!boost::filesystem::create_directory(
			p
		)
	)
		throw create_directory_failed(
			p
		);
}
