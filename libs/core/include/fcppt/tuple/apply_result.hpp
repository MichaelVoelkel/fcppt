//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_APPLY_RESULT_HPP_INCLUDED
#define FCPPT_TUPLE_APPLY_RESULT_HPP_INCLUDED

#include <fcppt/tuple/size.hpp>
#include <fcppt/tuple/detail/apply_result_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Result of #fcppt::tuple::apply.

\ingroup fcppttuple
*/
template <typename Function, typename... Tuples>
using apply_result = typename fcppt::tuple::detail::apply_result_impl<
    Function,
    std::make_index_sequence<fcppt::tuple::size<::metal::front<::metal::list<Tuples...>>>::value>,
    Tuples...>::type;

}

#endif