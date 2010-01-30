//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_IMPLICATION_HPP_INCLUDED
#define FCPPT_MPL_IMPLICATION_HPP_INCLUDED

#include <boost/mpl/or.hpp>
#include <boost/mpl/not.hpp>

namespace fcppt
{
namespace mpl
{

template<
	typename Left,
	typename Right
>
struct implication
:
boost::mpl::or_<
	boost::mpl::not_<
		Left
	>,
	Right
>
{};

}
}

#endif
