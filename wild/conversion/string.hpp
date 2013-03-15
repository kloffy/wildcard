#ifndef WILD_CONVERSION_STRING_HPP
#define WILD_CONVERSION_STRING_HPP

#include <string>

namespace wild {

template<int N>
struct conversion<std::string, const char[N]>
{
	std::string operator()(const char value[N]) const
	{
		return std::string(value);
	}
};

template<>
struct conversion<std::string, const char*>
{
	std::string operator()(const char* value) const
	{
		return std::string(value);
	}
};

template<>
struct conversion<const char*, std::string>
{
	const char* operator()(std::string const& value) const
	{
		return value.c_str();
	}
};

}

#endif // WILD_CONVERSION_STRING_HPP