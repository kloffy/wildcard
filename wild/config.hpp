#ifndef WILD_CONFIG_HPP
#define WILD_CONFIG_HPP

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

// Availability depends on platfrom or compiler?
#define HAVE_BITSCANFORWARD
#define HAVE_BITSCANREVERSE

#endif

#endif // WILD_CONFIG_HPP