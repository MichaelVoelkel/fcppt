//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION_HPP_INCLUDED

namespace fcppt
{
namespace type_traits
{
/// See http://stackoverflow.com/questions/257288/possible-for-c-template-to-check-for-a-functions-existence/264088#264088
#define FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION(func)\
	template<typename T, typename Sign>\
	struct has_ ## func\
	{\
		template<typename U, U> struct type_check;\
		template<typename _1> static char (& chk(type_check<Sign, &_1::func> *))[1];\
		template<typename   > static char (& chk(...))[2];\
		static bool const value = sizeof(chk<T>(0)) == 1;\
	}
}
}

#endif
