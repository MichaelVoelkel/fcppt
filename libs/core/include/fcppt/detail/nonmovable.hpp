//          Moveright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or move at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_NONMOVABLE_HPP_INCLUDED
#define FCPPT_DETAIL_NONMOVABLE_HPP_INCLUDED


#define FCPPT_DETAIL_NONMOVABLE(\
	classname\
)\
/* NOLINTNEXTLINE(bugprone-macro-parentheses)*/ \
classname(classname &&) = delete; \
classname &operator=(classname &&) = delete /* NOLINT(bugprone-macro-parentheses)*/

#endif