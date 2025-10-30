#pragma once

// Platform detection using predefined macros
#if defined(__linux__)
	#define ENGINE_PLATFORM_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	// TARGET_OS_MAC exists on all Apple platforms
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "iOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define ENGINE_PLATFORM_IOS
		#error "iOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define ENGINE_PLATFORM_MACOS
	#else
		#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
	#define ENGINE_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(_WIN32) || defined(_WIN64)
	#define ENGINE_PLATFORM_WINDOWS
	#error "Windows is not supported!"
#else
	#error "Unknown platform!"
#endif