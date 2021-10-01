//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>

namespace fcppt::math::matrix
{
/**
\brief Calculates a transposed matrix

\ingroup fcpptmathmatrix
*/
template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
fcppt::math::matrix::static_<T, C, R>
transpose(fcppt::math::matrix::object<T, R, C, S> const &_matrix)
{
  return fcppt::math::matrix::init<fcppt::math::matrix::static_<T, C, R>>(
      [&_matrix]<fcppt::math::size_type Row, fcppt::math::size_type Col>(
          fcppt::math::matrix::index<Row, Col>)
      { return fcppt::math::matrix::at_r_c<Col, Row>(_matrix); });
}

}

#endif
