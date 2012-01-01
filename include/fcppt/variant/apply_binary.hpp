//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/binary_unwrap.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Does a binary visitation

\ingroup fcpptvariant

Visits \a _obj1 and \a _obj2 with the visitor \a _op. <code>_op.operator()(T,
U)</code> will be called where <code>T</code> is the type held by \a _obj1 and
<code>U</code> is the type held by \a _obj2.

\tparam Operation The visitor type
\tparam Variant1 The first variant
\tparam Variant2 The second variant

\param _op The visitor to execute
\param _obj1 The first variant to visit
\param _obj2 The second variant to visit

\return The result of <code>_op.operator()(T, U)</code>
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
typename Operation::result_type
apply_binary(
	Operation const &_op,
	Variant1 const &_obj1,
	Variant2 const &_obj2
)
{
	return
		variant::apply_unary(
			detail::binary_unwrap<
				Operation,
				Variant1
			>(
				_op,
				_obj1
			),
			_obj2
		);
}

}
}

#endif
