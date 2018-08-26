//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORY_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORY_HPP_INCLUDED

#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/preprocessor/warn_unused_result.hpp>
#include <fcppt/system/optional_error_code.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Tries to create a directory

\ingroup fcpptfilesystem

Tries to create the last component of \a path as a directory.
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::system::optional_error_code
create_directory(
	boost::filesystem::path const &path
)
FCPPT_PP_WARN_UNUSED_RESULT;

}
}

#endif
