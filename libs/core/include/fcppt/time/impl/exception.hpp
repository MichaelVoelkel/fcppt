//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_TIME_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


inline
fcppt::time::exception::exception(
	fcppt::string &&_what
)
:
	fcppt::exception{
		FCPPT_TEXT("time: ")
		+
		std::move(
			_what
		)
	}
{
}

#endif
