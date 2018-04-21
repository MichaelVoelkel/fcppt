//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRODUCT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/product_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/record/disjoint_product.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A product of two parsers.

\ingroup fcpptoptions

This parser first applies its left parser and if that succeeds also applies its
right parser. Use \link fcppt::options::apply\endlink to create a product of
two or more parsers. The result type is a record that contains the elements of
<em>both</em> \a Left and \a Right. Therefore, \a Left and \a Right must have
<em>disjoint</em> label sets.

\see fcppt::options::apply
*/
template<
	typename Left,
	typename Right
>
class product
{
public:
	product(
		Left const &,
		Right const &
	);

	product(
		Left &&,
		Right &&
	);

	product(
		product const &
	);

	product(
		product &&
	);

	product &
	operator=(
		product const &
	);

	product &
	operator=(
		product &&
	);

	~product();

	typedef
	fcppt::record::disjoint_product<
		fcppt::options::result_of<
			Left
		>,
		fcppt::options::result_of<
			Right
		>
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::parse_arguments &
	) const;

	fcppt::options::flag_name_set
	flag_names() const;

	fcppt::options::option_name_set
	option_names() const;

	fcppt::string
	usage() const;
private:
	void
	check_disjoint() const;

	Left left_;

	Right right_;
};

}
}

#endif
