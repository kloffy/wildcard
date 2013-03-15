#ifndef WILD_CONVERSION_ARITHMETIC_HPP
#define WILD_CONVERSION_ARITHMETIC_HPP

#include <type_traits>

namespace wild {

template<typename Target, typename Source>
struct conversion<Target, Source, typename std::enable_if<std::is_arithmetic<Target>::value && std::is_arithmetic<Source>::value>::type>
{
	Target operator()(Source const& value) const
	{
		return static_cast<Target>(value);
	}
};

}

#endif // WILD_CONVERSION_ARITHMETIC_HPP