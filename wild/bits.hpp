#ifndef WILD_BITS_HPP
#define WILD_BITS_HPP

#include <wild/config.hpp>

// Find first set, find last set.
// http://en.wikipedia.org/wiki/Find_first_set
// Warning: Fallback implementation not optimized.

#if defined(HAVE_BITSCANFORWARD) || defined(HAVE_BITSCANREVERSE)
#include <intrin.h>
#pragma intrinsic(_BitScanForward)
#pragma intrinsic(_BitScanReverse)
#elif defined(HAVE_FFS) || defined(HAVE_FLS)
#include <strings.h>
#else
#include <climits>
#endif

namespace wild {

inline unsigned int ffs(unsigned int x)
{
	assert(x > 0);
#if defined(HAVE_BITSCANFORWARD)
	unsigned long r;
	unsigned char res = _BitScanForward(&r, (unsigned long)x);
	assert(res > 0);
	return (unsigned int)r;
#elif defined(HAVE_FFS)
	return ::ffs(x) - 1;
#else
	unsigned int r = 0;
	while (((x >> r++) & 1) == 0);
	return r - 1;
#endif
}

inline unsigned int fls(unsigned int x)
{
	assert(x > 0);
#if defined(HAVE_BITSCANREVERSE)
	unsigned long r;
	unsigned char res = _BitScanReverse(&r, (unsigned long)x);
	assert(res > 0);
	return (unsigned int)r;
#elif defined(HAVE_FLS)
	return ::fls(x) - 1;
#else
	unsigned int r = (sizeof(unsigned int) * CHAR_BIT) - 1;
	while (((x >> r--) & 1) == 0);
	return r + 1;
#endif
}

}

#endif // WILD_BITS_HPP