//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_RANGE_HPP_INCLUDED
#define FCPPT_RANDOM_RANGE_HPP_INCLUDED

#include <fcppt/random/range_fwd.hpp>

namespace fcppt
{
namespace random
{

template<
	typename T
>
class range
{
protected:
	range(
		T const &first_,
		T const &last_
	)
	:
		first_(first_),
		last_(last_)
	{}
public:
	typedef T value_type;

	T first() const
	{
		return first_;
	}

	T last() const
	{
		return last_;
	}
private:
	T
		first_,
		last_;
};

}
}

#endif
