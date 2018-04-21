//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_SUM_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_SUM_HPP_INCLUDED

#include <fcppt/options/sum_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Creates the sum of two parsers.

\ingroup fcpptoptions
*/
template<
	typename Parser1,
	typename Parser2
>
inline
fcppt::options::sum<
	fcppt::type_traits::remove_cv_ref_t<
		Parser1
	>,
	fcppt::type_traits::remove_cv_ref_t<
		Parser2
	>
>
make_sum(
	Parser1 &&_parser1,
	Parser2 &&_parser2
)
{
	return
		fcppt::options::sum<
			fcppt::type_traits::remove_cv_ref_t<
				Parser1
			>,
			fcppt::type_traits::remove_cv_ref_t<
				Parser2
			>
		>(
			std::forward<
				Parser1
			>(
				_parser1
			),
			std::forward<
				Parser2
			>(
				_parser2
			)
		);
}

}
}

#endif
