//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_MAKE_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_MAKE_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Make an array out of a parameter pack.

\ingroup fcpptcontainerarray

Let \a _args be <code>(a_1,...,a_n)</code>. All elements of \a _args must be of
the same type <code>T</code>. The result is
<code>std::array<T,n>{a_1,...,a_n}</code>.

\tparam Args A parameter pack <code>t_1,...,t_n</code> such that
<code>remove_cv_ref<t_1> = ... = remove_cv_ref<t_n></code>.
*/
template<
	typename... Args
>
inline
std::array<
	::brigand::front<
		::brigand::list<
			fcppt::type_traits::remove_cv_ref_t<
				Args
			>...
		>
	>,
	sizeof...(Args)
>
make(
	Args &&... _args
)
{
	typedef
	::brigand::list<
		fcppt::type_traits::remove_cv_ref_t<
			Args
		>...
	>
	decayed_args;

	typedef
	::brigand::front<
		decayed_args
	>
	first_type;

	typedef
	std::array<
		first_type,
		sizeof...(Args)
	>
	result_type;

	static_assert(
		::brigand::all<
			decayed_args,
			::brigand::bind<
				std::is_same,
				::brigand::pin<
					first_type
				>,
				::brigand::_1
			>
		>::value,
		"All types of array::make must be the same"
	);

	return
		result_type{{
			std::forward<
				Args
			>(
				_args
			)...
		}};
}

}
}
}

#endif
