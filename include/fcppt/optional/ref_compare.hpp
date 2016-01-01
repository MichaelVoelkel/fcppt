//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_REF_COMPARE_HPP_INCLUDED
#define FCPPT_OPTIONAL_REF_COMPARE_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Compares two optional references for identity

\ingroup fcpptoptional

Compares \a _a and \a _b, which must be optional references, for identity. Two
optional references are equal if they both refer to the same object.

\param _a The first optional
\param _b The second optional

\tparam T Must be a reference type
*/
template<
	typename T
>
bool
ref_compare(
	fcppt::optional::object<
		T
	> const &_a,
	fcppt::optional::object<
		T
	> const &_b
)
{
	static_assert(
		std::is_reference<
			T
		>::value,
		"optional::ref_compare can only be used with optional references"
	);

	return
		_a.data()
		==
		_b.data();
}

}
}

#endif