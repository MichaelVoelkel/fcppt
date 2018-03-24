//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/detail/combine_errors.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/logical/or.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename T
>
T
append_errors(
	T &&_error1,
	T &&_error2
)
{
	return
		std::move(
			_error1
		)
		+
		T{
			FCPPT_TEXT("\n")
		}
		+
		std::move(
			_error2
		);
}

template<
	typename Error1,
	typename Error2
>
using
errors_same
=
std::is_same<
	fcppt::type_traits::remove_cv_ref_t<
		Error1
	>,
	fcppt::type_traits::remove_cv_ref_t<
		Error2
	>
>;

struct combiner
{
	template<
		typename Error1,
		typename Error2
	>
	std::enable_if_t<
		errors_same<
			Error1,
			Error2
		>::value,
		fcppt::options::error
	>
	operator()(
		Error1 &&_error1,
		Error2 &&_error2
	) const
	{
		return
			fcppt::options::error{
				append_errors(
					std::move(
						_error1
					),
					std::move(
						_error2
					)
				)
			};
	}

	template<
		typename Error1,
		typename Error2
	>
	std::enable_if_t<
		!errors_same<
			Error1,
			Error2
		>::value,
		fcppt::options::error
	>
	operator()(
		Error1 &&_error1,
		Error2 &&_error2
	) const
	{
		static_assert(
			::brigand::or_<
				std::is_same<
					fcppt::type_traits::remove_cv_ref_t<
						Error1
					>,
					fcppt::options::other_error
				>,
				std::is_same<
					fcppt::type_traits::remove_cv_ref_t<
						Error2
					>,
					fcppt::options::other_error
				>
			>::value,
			"One of the types must be other_error"
		);

		return
			fcppt::options::error{
				fcppt::options::other_error{
					append_errors(
						std::move(
							_error1.get()
						),
						std::move(
							_error2.get()
						)
					)
				}
			};
	}
};

}

fcppt::options::error
fcppt::options::detail::combine_errors(
	fcppt::options::error &&_error1,
	fcppt::options::error &&_error2
)
{
	return
		fcppt::variant::apply_binary(
			combiner{},
			std::move(
				_error1
			),
			std::move(
				_error2
			)
		);
}
