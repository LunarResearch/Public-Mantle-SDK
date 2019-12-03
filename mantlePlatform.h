/*

Module Name:

	mantlePlatform.h

Abstract:

	Platform specific definitions

*/


#ifndef MANTLEPLATFORM_H_
#define MANTLEPLATFORM_H_


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if defined(_WIN32)
#define GR_STDCALL __stdcall
#define GR_VOID void
#else
#define GR_STDCALL
#define GR_VOID
#endif

#include <stddef.h>

#if !defined(GR_NO_STDINT_H)
#if defined(_MSC_VER) && (_MSC_VER < 1600)
	typedef unsigned char GR_BYTE;
	typedef char GR_CHAR;
	typedef float GR_FLOAT;
	typedef signed __int32 GR_BOOL;
	typedef signed __int8 GR_INT8;
	typedef unsigned __int8 GR_UINT8;
	typedef signed int GR_INT;
	typedef unsigned int GR_UINT;
	typedef signed __int32 GR_INT32;
	typedef unsigned __int32 GR_UINT32;
	typedef signed __int64 GR_INT64;
	typedef  unsigned __int64 GR_UINT64;
	typedef unsigned long long GR_SIZE;
	typedef unsigned long long GR_GPU_SIZE;
	typedef signed __int32 GR_ENUM;
	typedef signed __int32 GR_FLAGS;
	typedef unsigned long GR_SAMPLE_MASK;
#else
#include <stdint.h>
	typedef uint8_t GR_BYTE;
	typedef char GR_CHAR;
	typedef float GR_FLOAT;
	typedef int32_t GR_BOOL;
	typedef int8_t GR_INT8;
	typedef uint8_t GR_UINT8;
	typedef int32_t GR_INT;
	typedef uint32_t GR_UINT;
	typedef int32_t GR_INT32;
	typedef uint32_t GR_UINT32;
	typedef int64_t GR_INT64;
	typedef uint64_t GR_UINT64;
	typedef rsize_t GR_SIZE;
	typedef uint64_t GR_GPU_SIZE;
	typedef int32_t GR_ENUM;
	typedef int32_t GR_FLAGS;
	typedef uint32_t GR_SAMPLE_MASK;
#endif

#endif // !defined(GR_NO_STDINT_H)


#ifdef GR_USE_PLATFORM_WAYLAND
#include <wayland-client.h>
#endif

#ifdef GR_USE_PLATFORM_WIN32
#include <windows.h>
#endif

#ifdef GR_USE_PLATFORM_XCB
#include <xcb/xcb.h>
#endif

#ifdef GR_USE_PLATFORM_XLIB
#include <X11/Xlib.h>
#endif

#ifdef GR_USE_PLATFORM_XLIB_XRANDR_EXT
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#endif

#ifdef GR_USE_PLATFORM_GGP
#include <ggp_c/vulkan_types.h>
#endif


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // MANTLEPLATFORM_H_
