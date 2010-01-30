//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/random/actor/normalized.hpp>
#include <fcppt/random/actor/element.hpp>
#include <fcppt/random/inclusive_range.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/format.hpp>
#include <boost/foreach.hpp>
#include <numeric>
#include <functional>

fcppt::random::actor::normalized::normalized(
	container const &elements
)
:
	elements(elements),
	rng(
		random::make_inclusive_range(
			static_cast<float_type>(0),
			std::accumulate(
				elements.begin(),
				elements.end(),
				static_cast<float_type>(0),
				std::tr1::bind(
					std::plus<
						float_type
					>(),
					std::tr1::placeholders::_1,
					std::tr1::bind(
						&element::prob,
						std::tr1::placeholders::_2
					)
				)
			)
		)
	)
{
	if(elements.empty())
		throw exception(
			FCPPT_TEXT("actor::normalized: elements may not be empty!")
		);
}

fcppt::random::actor::normalized::~normalized()
{}

void
fcppt::random::actor::normalized::operator()()
{
	float_type const val(
		rng()
	);

	float_type cur(
		val
	);

	BOOST_FOREACH(
		container::const_reference ref,
		elements
	)
	{
		if(cur <= ref.prob())
		{
			ref.callback()();
			return;
		}
		cur -= ref.prob();
	}

	throw exception(
		(fcppt::format(
			FCPPT_TEXT("random::actor::normalized: nothing matched! Return value was %1% and is now %2%!")
		) % val % cur).str()
	);
}
