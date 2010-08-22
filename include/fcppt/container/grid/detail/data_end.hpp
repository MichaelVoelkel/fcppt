//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_DATA_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_DATA_END_HPP_INCLUDED

#include <fcppt/container/grid/detail/choose_pointer.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/container/is_raw_vector.hpp>
#include <fcppt/container/is_std_vector.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <boost/utility/enable_if.hpp>
#include <vector>

namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Container
>
typename boost::enable_if<
	container::is_std_vector<
		Container
	>,
	typename detail::choose_pointer<
		Container	
	>::type
>::type
data_end(
	Container &_impl
)
{
	return
		fcppt::container::data_end(
			_impl
		);
}

template<
	typename Container
>
typename boost::enable_if<
	container::is_raw_vector<
		Container
	>,
	typename detail::choose_pointer<
		Container
	>::type
>::type
data_end(
	Container &_impl
)
{
	return _impl.data_end();
}

}
}
}
}

#endif
