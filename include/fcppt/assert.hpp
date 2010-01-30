//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_HPP_INCLUDED
#define FCPPT_ASSERT_HPP_INCLUDED

#include <fcppt/detail/process_assert.hpp>
#include <fcppt/preprocessor/stringize.hpp>
#include <fcppt/preprocessor/file.hpp>

/**
 * @brief Runtime assert macro that throws fcppt::exception
*/
#define FCPPT_ASSERT(cond)\
if (!(cond))\
	fcppt::detail::process_assert(\
		FCPPT_PP_FILE,\
		FCPPT_PP_STRINGIZE(__LINE__),\
		FCPPT_PP_STRINGIZE(cond),\
		FCPPT_PP_STRINGIZE("")\
	);

#endif
