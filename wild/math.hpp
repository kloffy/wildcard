#ifndef WILD_MATH_HPP
#define WILD_MATH_HPP

#include <cmath>

namespace wild {

inline int mod(int x, int m)
{
	int r = x % m;
	return r<0 ? r+m : r;
}

}

#endif // WILD_MATH_HPP