#ifndef WILD_CONFIG_HPP
#define WILD_CONFIG_HPP

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)

#define WILD_PLATFORM_LINUX

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#define WILD_PLATFORM_MACOS

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

#define WILD_PLATFORM_WIN32

// Availability depends on platfrom or compiler?
#define HAVE_BITSCANFORWARD
#define HAVE_BITSCANREVERSE

#endif

#endif // WILD_CONFIG_HPP