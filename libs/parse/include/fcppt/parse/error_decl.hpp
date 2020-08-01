//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_DECL_HPP_INCLUDED

#include <fcppt/parse/error_fwd.hpp>
#include <fcppt/parse/fatal_tag_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class error
{
public:
	using
	value_type
	=
	std::basic_string<
		Ch
	>;

	explicit
	error(
		value_type &&
	);

	error(
		value_type &&,
		fcppt::parse::fatal_tag const &
	);

	[[nodiscard]]
	bool
	is_fatal() const;

	[[nodiscard]]
	value_type &
	get();

	[[nodiscard]]
	value_type const &
	get() const;
private:
	value_type value_;

	bool is_fatal_;
};

}
}

#endif
