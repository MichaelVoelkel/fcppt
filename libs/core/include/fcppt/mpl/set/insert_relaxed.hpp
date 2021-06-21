//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_INSERT_RELAXED_HPP_INCLUDED
#define FCPPT_MPL_SET_INSERT_RELAXED_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/insert.hpp>

namespace fcppt::mpl::set
{
template <fcppt::mpl::set::object_concept Set, typename Value>
using insert_relaxed = fcppt::mpl::apply<fcppt::mpl::if_<
    fcppt::mpl::set::contains<Set, Value>,
    fcppt::mpl::constant<Set>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::set::insert>,
        fcppt::mpl::constant<Set>,
        fcppt::mpl::constant<Value>>>>;
}

#endif
