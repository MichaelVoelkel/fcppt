//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_INDEX_OF_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_INDEX_OF_HPP_INCLUDED

#include <fcppt/variant/detail/real_type.hpp>
#include <fcppt/mpl/index_of.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename Element
>
struct index_of
:
fcppt::mpl::index_of<
	Types,
	typename real_type<
		Types,
		Element
	>::type
>
{};

}
}
}

#endif
