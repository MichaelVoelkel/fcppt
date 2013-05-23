//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CEIL_DIV_SIGNED_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_SIGNED_HPP_INCLUDED

#include <fcppt/math/ceil_div.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates dividend / divisor rounded towards infinity
\tparam T A signed type
\ingroup fcpptmath
\param _dividend The dividend
\param _divisor The divisor
*/
template<
	typename T
>
typename boost::enable_if<
	std::is_signed<
		T
	>,
	T
>::type
ceil_div_signed(
	T const &_dividend,
	T const &_divisor
)
{
	typedef
	typename
	std::make_unsigned<
		T
	>::type
	unsigned_type;

	return
		(
			_dividend
			<
			0
		)
		?
			_dividend
			/
			_divisor
		:
			static_cast<
				T
			>(
				fcppt::math::ceil_div(
					static_cast<
						unsigned_type
					>(
						_dividend
					),
					static_cast<
						unsigned_type
					>(
						_divisor
					)
				)
			)
		;
}

}
}

#endif