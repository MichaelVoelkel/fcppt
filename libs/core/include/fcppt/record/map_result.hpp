//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_MAP_RESULT_HPP_INCLUDED
#define FCPPT_RECORD_MAP_RESULT_HPP_INCLUDED

#include <fcppt/record/map_elements.hpp>
#include <fcppt/record/detail/map_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The result of mapping a record.

\ingroup fcpptrecord
*/
template<
	typename Record,
	typename Function
>
using
map_result
=
fcppt::record::map_elements<
	Record,
	fcppt::record::detail::map_result<
		Function,
		boost::mpl::_
	>
>;

}
}

#endif