#ifndef FCPPT_MATH_MATRIX_DELETE_COLUMN_AND_ROW_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DELETE_COLUMN_AND_ROW_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/// Deletes a specific row and rolumn (a cross) from the matrix
template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename static_<T, N::value-1, M::value-1>::type const
delete_column_and_row(
	basic<T, N, M, S> const &t,
	typename basic<T, N, M, S>::size_type const column,
	typename basic<T, N, M, S>::size_type const row)
{
	typedef typename
	static_<T, N::value-1, M::value-1>::type
	ret_type;

	typedef typename
	ret_type::size_type 
	size_type;

	ret_type ret;

	for(
		size_type i = 
			static_cast<size_type>(0); 
		i < t.rows(); 
		++i)
	{
		if (i == row)
			continue;

		size_type const reali = 
			i > row 
			? 
				static_cast<size_type>(
					i-1) 
			: i;

		for(
			size_type j = static_cast<size_type>(0); 
			j < t.columns(); 
			++j)
		{
			if (j == column)
				continue;

			size_type const realj = 
				j > column
				? 
					static_cast<size_type>(j-1) 
				: 
					j;

			ret[realj][reali] = t[j][i];
		}
	}

	return ret;
}
}
}
}

#endif
