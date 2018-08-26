//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_HAS_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_HAS_LABEL_HPP_INCLUDED

#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/has_key.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if a record has an \link fcppt::record::label\endlink.

\ingroup fcpptrecord
*/
template<
	typename Record,
	typename Label
>
using
has_label
=
::brigand::has_key<
	fcppt::record::label_set<
		Record
	>,
	Label
>;

}
}

#endif
