//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GET_OR_INSERT_WITH_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_GET_OR_INSERT_WITH_RESULT_HPP_INCLUDED

#include <fcppt/maybe.hpp>
#include <fcppt/container/find_opt.hpp>
#include <fcppt/container/get_or_insert_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Gets from or inserts an element into a map and returns a flag

\ingroup fcpptcontainer

Tries to find \a _key in \a _container. If the mapped object is found, it is
returned and <code>inserted</code> is true.  Otherwise, \a _create is called
with _a key to create a new mapped object which is then inserted into \a
_container and returned along with <code>inserted</code> as false.

\tparam Container An associative container

\tparam Create A function of type <code>Container::mapped_type &
(Container::key_type)</code>
*/
template<
	typename Container,
	typename Create
>
fcppt::container::get_or_insert_result<
	typename
	Container::mapped_type &
>
get_or_insert_with_result(
	Container &_container,
	typename Container::key_type const &_key,
	Create const &_create
)
{
	typedef
	fcppt::container::get_or_insert_result<
		typename
		Container::mapped_type &
	>
	result_type;

	return
		fcppt::maybe(
			fcppt::container::find_opt(
				_container,
				_key
			),
			[
				&_container,
				&_create,
				&_key
			]
			{
				auto const inserted(
					_container.insert(
						std::make_pair(
							_key,
							_create(
								_key
							)
						)
					)
				);

				return
					result_type(
						inserted.first->second,
						true
					);
			},
			[](
				typename Container::mapped_type &_element
			)
			{
				return
					result_type(
						_element,
						false
					);
			}
		);
}

}
}

#endif