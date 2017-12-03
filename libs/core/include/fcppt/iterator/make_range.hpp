//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_MAKE_RANGE_HPP_INCLUDED
#define FCPPT_ITERATOR_MAKE_RANGE_HPP_INCLUDED

#include <fcppt/iterator/range_impl.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Iterator
>
fcppt::iterator::range<
	Iterator
>
make_range(
	Iterator const _begin,
	Iterator const _end
)
{
	return
		fcppt::iterator::range<
			Iterator
		>(
			_begin,
			_end
		);
}

}
}

#endif
