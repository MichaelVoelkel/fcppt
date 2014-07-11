//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PRINT_ALL_LOCATIONS_HPP_INCLUDED
#define FCPPT_LOG_PRINT_ALL_LOCATIONS_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Prints all locations of a context

\ingroup fcpptlog

Prints all locations of \a context to \a stream.

\param stream The stream to print to

\param context The context to print the locations of
*/
FCPPT_SYMBOL
void
print_all_locations(
	fcppt::io::ostream &stream,
	fcppt::log::context &context
);

}
}

#endif