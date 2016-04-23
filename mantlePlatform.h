#pragma once
#ifndef MANTLEPLATFORM_H_
#define MANTLEPLATFORM_H_

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_WIN32)
	#define GR_STDCALL __stdcall
#else
	#define GR_STDCALL
#endif

#include <stddef.h>

#if !defined(GR_NO_STDINT_H)
	#if defined(_MSC_VER) && (_MSC_VER < 1600)
		typedef char GR_CHAR;
		typedef float GR_FLOAT;
		typedef signed int GR_INT;
		typedef unsigned int GR_UINT;
		typedef unsigned __int32 GR_UINT32;
		typedef unsigned __int64 GR_UINT64;
		typedef unsigned long long GR_SIZE;
		typedef unsigned long long GR_GPU_SIZE;
		typedef signed int GR_ENUM;
		typedef void GR_VOID;
		typedef unsigned int GR_FLAGS;
		typedef unsigned int GR_BOOL;
	#else
		#include <stdint.h>
		typedef char GR_CHAR;
		typedef float GR_FLOAT;
		typedef int32_t GR_INT;
		typedef uint32_t GR_UINT;
		typedef uint32_t GR_UINT32;
		typedef uint64_t GR_UINT64;
		typedef rsize_t GR_SIZE;
		typedef uint64_t GR_GPU_SIZE;
		typedef int32_t GR_ENUM;
		typedef void GR_VOID;
		typedef int32_t GR_FLAGS;
		typedef int32_t GR_BOOL;
	#endif
#endif

#ifdef __cplusplus
}
#endif

#ifdef GR_USE_PLATFORM_WIN32_KHR
	#include <windows.h>
#endif

#endif
