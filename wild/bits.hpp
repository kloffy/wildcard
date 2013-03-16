#ifndef WILD_BITS_HPP
#define WILD_BITS_HPP

#if defined(HAVE__BITSCANFORWARD) && defined(HAVE__BITSCANREVERSE)
#include <intrin.h>
#pragma intrinsic(_BitScanForward)
#pragma intrinsic(_BitScanReverse)
#endif

namespace wild {

inline unsigned int ffs(unsigned int x)
{
#if defined(HAVE__BITSCANFORWARD)
	unsigned long r;
	unsigned char res = _BitScanForward(&r, (unsigned long)x);
	assert(res > 0);
	return (unsigned int)r;
#else
	return ::ffs(x) - 1;
#endif
}

inline unsigned int fls(unsigned int x)
{
#if defined(HAVE__BITSCANREVERSE)
	unsigned long r;
	unsigned char res = _BitScanReverse(&r, (unsigned long)x);
	assert(res > 0);
	return (unsigned int)r;
#else
	return ::fls(x) - 1;
#endif
}

}

#endif // WILD_BITS_HPP