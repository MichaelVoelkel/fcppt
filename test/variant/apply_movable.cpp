//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef std::unique_ptr<
	int
> int_unique_ptr;

typedef std::unique_ptr<
	std::string
> string_unique_ptr;

typedef std::unique_ptr<
	bool
> bool_unique_ptr;

struct functor
{
	typedef bool result_type;

	template<
		typename T1,
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T1 &,
		T2 &,
		T3 &
	) const
	{
		return false;
	}

	result_type
	operator()(
		int_unique_ptr &_int,
		string_unique_ptr &_string,
		bool_unique_ptr &_bool
	) const
	{
		string_unique_ptr foo(
			std::move(
				_string
			)
		);

		return
			*_int == 42
			&& *foo == "test"
			&& *_bool == true;
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_apply_movable
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::variant::object<
		boost::mpl::vector3<
			int_unique_ptr,
			string_unique_ptr,
			bool_unique_ptr
		>
	> variant;

	variant int_variant(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	variant string_variant(
		fcppt::make_unique_ptr<
			std::string
		>(
			"test"
		)
	);

	variant bool_variant(
		fcppt::make_unique_ptr<
			bool
		>(
			true
		)
	);

	functor const func{};

	BOOST_REQUIRE(
		fcppt::variant::apply_ternary(
			func,
			int_variant,
			string_variant,
			bool_variant
		)
	);

	BOOST_REQUIRE(
		!string_variant.get<
			string_unique_ptr
		>()
	);
}