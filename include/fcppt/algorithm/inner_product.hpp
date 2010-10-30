#ifndef FCPPT_ALGORITHM_INNER_PRODUCT_HPP_INCLUDED
#define FCPPT_ALGORITHM_INNER_PRODUCT_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{
template
<
	typename Range1,
	typename Range2,
	typename ValueType,
	typename OuterOperation,
	typename InnerOperation
>
ValueType const
inner_product(
	Range1 const &r1,
	Range2 const &r2,
	ValueType result,
	OuterOperation const &outer,
	InnerOperation const &inner)
{
	typename Range1::const_iterator r1i = r1.begin();
	typename Range2::const_iterator r2i = r2.begin();

	for (;r1i != r1.end(); ++r1i, ++r2i)
		result = outer(result,inner(*r1i,*r2i));

	return result;
}
}
}

#endif
