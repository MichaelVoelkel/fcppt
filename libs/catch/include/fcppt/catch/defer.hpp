//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_DEFER_HPP_INCLUDED
#define FCPPT_CATCH_DEFER_HPP_INCLUDED


namespace fcppt
{
namespace catch_
{

/**
\brief Use this to avoid catch printing an expression.

\ingroup fcpptcatch
*/
inline
bool
defer(
	bool const _value
)
{
	return
		_value;
}

}
}

#endif
