//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_CONSTRUCT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_CONSTRUCT_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Variant
>
class construct
{
	FCPPT_NONASSIGNABLE(
		construct
	);
public:
	typedef void result_type;

	explicit construct(
		Variant &_obj
	)
	:
		obj_(_obj)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T const &_value
	) const
	{
		obj_ = _value;
	}
private:
	Variant &obj_;
};

}
}
}

#endif
