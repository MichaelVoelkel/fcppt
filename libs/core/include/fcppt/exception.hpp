//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXCEPTION_HPP_INCLUDED
#define FCPPT_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception_fwd.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief The base class for all exceptions.

\ingroup fcpptstring

fcppt::exception is a wrapper around an exception that uses \link fcppt::string
\endlink to store the error message. Note that you will have to use \link
fcppt::exception::string \endlink to obtain the string. If you use
<code>what()</code>, which is only provided for compatibility with
<code>std::exception</code>, nothing useful will be returned. The reason behind
this is that a string conversion itself can result in exceptions being thrown.
That is why <code>what()</code> does not try to convert from \link
fcppt::string \endlink to <code>std::string</code>.
*/
class exception
:
	public std::exception
{
public:
	/**
	\brief Constructs an exception from a string
	*/
	explicit
	exception(
		fcppt::string &&what
	);

	exception(
		exception const &
	);

	exception(
		exception &&
	);

	exception &
	operator=(
		exception const &
	);

	exception &
	operator=(
		exception &&
	);

	/**
	\brief Returns the error message

	Use this function to print the error message instead of
	<code>what()</code>
	*/
	fcppt::string const &
	string() const;

	/**
	\brief Returns a generic error

	This function's purpose is to provide compatibility with
	<code>std::exception</code>. It returns nothing useful.
	*/
	char const *
	what() const noexcept
	override;

	~exception() noexcept
	override;
private:
	fcppt::string string_;
};

}

#include <fcppt/impl/exception.hpp>

#endif
