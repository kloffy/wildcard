#ifndef WILD_MACROS_HPP
#define WILD_MACROS_HPP

#define WILD_STR__(a) #a
#define WILD_STR_(a) WILD_STR__(a)
#define WILD_STR(a) WILD_STR_(a)

#define WILD_CAT__(a, b) a##b
#define WILD_CAT_(a,b) WILD_CAT__(a, b)
#define WILD_CAT(a,b) WILD_CAT_(a, b)

#endif // WILD_MACROS_HPP