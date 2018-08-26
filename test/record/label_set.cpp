//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/element.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/has_key.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		bool_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			int
		>,
		fcppt::record::element<
			bool_label,
			bool
		>
	>
	my_record;

	typedef
	fcppt::record::label_set<
		my_record
	>
	label_set;

	static_assert(
		brigand::has_key<
			label_set,
			int_label
		>::value,
		""
	);

	static_assert(
		brigand::has_key<
			label_set,
			bool_label
		>::value,
		""
	);

	static_assert(
		!brigand::has_key<
			label_set,
			int
		>::value,
		""
	);
}
