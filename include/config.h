#ifndef _CONFIG_H_INCLUDED_
#define _CONFIG_H_INCLUDED_

// Sets up platform and other settings required for the game

#include <cstdint>
#ifdef DEBUG
#define DEBUG_BUILD
#else
#define PRODUCTION_BUILD
#endif

// Platform
#if defined(_WIN32)
#define PLATFORM_WINDOWS
#elif defined(__linux__)
#define PLATFORM_LINUX
#else
#error Platform not currently supported
#endif

// Sizes
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;


// APP Build Details
#define APP_TITLE "Castle"


#endif // !_CONFIG_H_INCLUDED_
