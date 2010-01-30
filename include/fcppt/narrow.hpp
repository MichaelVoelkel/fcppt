//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NARROW_HPP_INCLUDED
#define FCPPT_NARROW_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <string>

namespace fcppt
{

/// convert an std::wstring to std::string using the default locale
FCPPT_SYMBOL std::string const
narrow(
	std::wstring const &
);

}

#endif
