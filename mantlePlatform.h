#pragma once
#ifndef MANTLEPLATFORM_H_
#define MANTLEPLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define GR_STDCALL __stdcall
#define GR_VOID void
#else
#define GR_STDCALL
#define GR_VOID
#endif

#include <stddef.h>
#include <Windows.h>

#if !defined(GR_NO_STDINT_H)
#if defined(_MSC_VER) && (_MSC_VER < 1600)
	typedef unsigned char GR_BYTE;
	typedef char GR_CHAR;
	typedef float GR_FLOAT;
	typedef unsigned char GR_UINT8;
	typedef signed int GR_INT;
	typedef signed __int32 GR_INT32;
	typedef unsigned int GR_UINT;
	typedef unsigned __int32 GR_UINT32;
	typedef unsigned __int64 GR_UINT64;
	typedef unsigned long long GR_SIZE;
	typedef unsigned long long GR_GPU_SIZE;
	typedef signed int GR_ENUM;
	typedef void GR_VOID;
	typedef unsigned int GR_FLAGS;
	typedef unsigned int GR_BOOL;
	typedef unsigned __int32 GR_SAMPLE_MASK;
#else
#include <stdint.h>
	typedef BYTE GR_BYTE;
	typedef char GR_CHAR;
	typedef float GR_FLOAT;
	typedef BOOL GR_BOOL;
	typedef int8_t GR_INT8;
	typedef uint8_t GR_UINT8;
	typedef INT GR_INT;
	typedef UINT GR_UINT;
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
#endif

#ifdef __cplusplus
}
#endif
#endif
