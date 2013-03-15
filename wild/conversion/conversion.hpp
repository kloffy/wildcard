#ifndef WILD_CONVERSION_CONVERSION_HPP
#define WILD_CONVERSION_CONVERSION_HPP

namespace wild {

template<typename Target, typename Source, typename Enable = void>
struct conversion
{
	static_assert(sizeof(Target) == 0 || sizeof(Source) == 0, "Must specialize conversion!");

	Target operator()(Source const& value) const;
};

template<typename Target, typename Source, typename Conversion = conversion<Target, Source>>
Target conversion_cast(Source const& value, Conversion conversion = Conversion())
{
	return conversion(value);
}

}

#endif // WILD_CONVERSION_CONVERSION_HPP