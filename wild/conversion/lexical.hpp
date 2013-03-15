#ifndef WILD_CONVERSION_LEXICAL_HPP
#define WILD_CONVERSION_LEXICAL_HPP

#include <boost/lexical_cast.hpp>

namespace wild {

template<typename Target, int N>
struct conversion<Target, const char[N]>
{
	Target operator()(const char value[N]) const
	{
		return boost::lexical_cast<Target>(value);
	}
};

template<typename Target>
struct conversion<Target, const char*>
{
	Target operator()(const char* value) const
	{
		return boost::lexical_cast<Target>(value);
	}
};

template<typename Target>
struct conversion<Target, std::string>
{
	Target operator()(std::string const& value) const
	{
		return boost::lexical_cast<Target>(value);
	}
};

template<typename Source>
struct conversion<std::string, Source>
{
	std::string operator()(Source const& value) const
	{
		return boost::lexical_cast<std::string>(value);
	}
};

}

#endif // WILD_CONVERSION_LEXICAL_HPP