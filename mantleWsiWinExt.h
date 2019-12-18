/*

Module Name:

	mantleWsiWinExt.h

Abstract:

	Windows® specific WSI extension interface

*/


#ifndef MANTLEWSIWINEXT_H_
#define MANTLEWSIWINEXT_H_

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


	GR_HANDLE(GR_WSI_WIN_DISPLAY);


#define GR_MAX_DEVICE_NAME_LEN 32
#define GR_MAX_GAMMA_RAMP_CONTROL_POINTS 1025


	// ======================================================
	// =================== ENUMERATIONS =====================
	// ======================================================
	typedef enum _GR_WSI_WIN_IMAGE_STATE {
		GR_WSI_WIN_IMAGE_STATE_PRESENT_WINDOWED = 0x00200000,
		GR_WSI_WIN_IMAGE_STATE_PRESENT_FULLSCREEN = 0x00200001,
	} GR_WSI_WIN_IMAGE_STATE;

	typedef enum _GR_WSI_WIN_INFO_TYPE {
		GR_WSI_WIN_INFO_TYPE_QUEUE_PROPERTIES = 0x00206800,
		GR_WSI_WIN_INFO_TYPE_DISPLAY_PROPERTIES = 0x00206801,
		GR_WSI_WIN_INFO_TYPE_GAMMA_RAMP_CAPABILITIES = 0x00206802,
		GR_WSI_WIN_INFO_TYPE_DISPLAY_FREESYNC_SUPPORT = 0x00206803,
		GR_WSI_WIN_INFO_TYPE_PRESENTABLE_IMAGE_PROPERTIES = 0x00206804,
		GR_WSI_WIN_INFO_TYPE_EXTENDED_DISPLAY_PROPERTIES = 0x00206805,
	} GR_WSI_WIN_INFO_TYPE;

	typedef enum _GR_WSI_WIN_PRESENT_MODE {
		GR_WSI_WIN_PRESENT_MODE_WINDOWED = 0x00200200,
		GR_WSI_WIN_PRESENT_MODE_FULLSCREEN = 0x00200201,
	} GR_WSI_WIN_PRESENT_MODE;

	typedef enum _GR_WSI_WIN_ROTATION_ANGLE {
		GR_WSI_WIN_ROTATION_ANGLE_0 = 0x00200100,
		GR_WSI_WIN_ROTATION_ANGLE_90 = 0x00200101,
		GR_WSI_WIN_ROTATION_ANGLE_180 = 0x00200102,
		GR_WSI_WIN_ROTATION_ANGLE_270 = 0x00200103,
	} GR_WSI_WIN_ROTATION_ANGLE;


	// ======================================================
	// ======================= FLAGS ========================
	// ======================================================
	typedef enum _GR_WSI_WIN_EXTENDED_DISPLAY_FLAGS {
		GR_WSI_WIN_WINDOWED_VBLANK_WAIT = 0x00000001,
		GR_WSI_WIN_WINDOWED_GET_SCANLINE = 0x00000002,
	} GR_WSI_WIN_EXTENDED_DISPLAY_FLAGS;

	typedef enum _GR_WSI_WIN_IMAGE_CREATE_FLAGS {
		GR_WSI_WIN_IMAGE_CREATE_FULLSCREEN_PRESENT = 0x00000001,
		GR_WSI_WIN_IMAGE_CREATE_STEREO = 0x00000002,
	} GR_WSI_WIN_IMAGE_CREATE_FLAGS;

	typedef enum _GR_WSI_WIN_PRESENT_FLAGS {
		GR_WSI_WIN_PRESENT_FULLSCREEN_DONOTWAIT = 0x00000001,
		GR_WSI_WIN_PRESENT_FULLSCREEN_STEREO = 0x00000002,
	} GR_WSI_WIN_PRESENT_FLAGS;

	typedef enum _GR_WSI_WIN_PRESENT_SUPPORT_FLAGS {
		GR_WSI_WIN_FULLSCREEN_PRESENT_SUPPORTED = 0x00000001,
		GR_WSI_WIN_WINDOWED_PRESENT_SUPPORTED = 0x00000002,
	} GR_WSI_WIN_PRESENT_SUPPORT_FLAGS;


	// ======================================================
	// ==================== STRUCTURES ======================
	// ======================================================
	typedef struct _GR_RGB_FLOAT {
		GR_FLOAT red;
		GR_FLOAT green;
		GR_FLOAT blue;
	} GR_RGB_FLOAT;

	typedef struct _GR_WSI_WIN_DISPLAY_MODE {
		GR_EXTENT2D	extent;
		GR_FORMAT format;
		GR_UINT	refreshRate;
		GR_BOOL	stereo;
		GR_BOOL	crossDisplayPresent;
	} GR_WSI_WIN_DISPLAY_MODE;

	typedef struct _GR_WSI_WIN_DISPLAY_PROPERTIES {
		HMONITOR hMonitor;
		GR_CHAR displayName[GR_MAX_DEVICE_NAME_LEN];
		GR_RECT desktopCoordinates;
		GR_WSI_WIN_ROTATION_ANGLE rotation;
	} GR_WSI_WIN_DISPLAY_PROPERTIES;

	typedef struct _GR_WSI_WIN_EXTENDED_DISPLAY_PROPERTIES {
		GR_WSI_WIN_EXTENDED_DISPLAY_FLAGS extendedProperties;
	} GR_WSI_WIN_EXTENDED_DISPLAY_PROPERTIES;

	typedef struct _GR_WSI_WIN_GAMMA_RAMP {
		GR_RGB_FLOAT scale;
		GR_RGB_FLOAT offset;
		GR_RGB_FLOAT gammaCurve[GR_MAX_GAMMA_RAMP_CONTROL_POINTS];
	} GR_WSI_WIN_GAMMA_RAMP;

	typedef struct _GR_WSI_WIN_GAMMA_RAMP_CAPABILITIES {
		GR_BOOL supportsScaleAndOffset;
		GR_FLOAT minConvertedValue;
		GR_FLOAT maxConvertedValue;
		GR_UINT controlPointCount;
		GR_FLOAT controlPointPositions[GR_MAX_GAMMA_RAMP_CONTROL_POINTS];
	} GR_WSI_WIN_GAMMA_RAMP_CAPABILITIES;

	typedef struct _GR_WSI_WIN_PRESENT_INFO {
		HWND hWndDest;
		GR_IMAGE srcImage;
		GR_WSI_WIN_PRESENT_MODE presentMode;
		GR_UINT presentInterval;
		GR_WSI_WIN_PRESENT_FLAGS flags;
	} GR_WSI_WIN_PRESENT_INFO;

	typedef struct _GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO {
		GR_FORMAT format;
		GR_IMAGE_USAGE_FLAGS usage;
		GR_EXTENT2D extent;
		GR_WSI_WIN_DISPLAY display;
		GR_WSI_WIN_IMAGE_CREATE_FLAGS flags;
	} GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO;

	typedef struct _GR_WSI_WIN_PRESENTABLE_IMAGE_PROPERTIES {
		GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO createInfo;
		GR_GPU_MEMORY mem;
	} GR_WSI_WIN_PRESENTABLE_IMAGE_PROPERTIES;

	typedef struct _GR_WSI_WIN_QUEUE_PROPERTIES {
		GR_WSI_WIN_PRESENT_SUPPORT_FLAGS presentSupport;
	} GR_WSI_WIN_QUEUE_PROPERTIES;


	// ======================================================
	// ==================== FUNCTIONS =======================
	// ======================================================
#define GR_WSI_WINDOWS_EXTENSION_NAME "GR_WSI_WINDOWS"
	
	GR_RESULT grWsiWinGetDisplays(
		_In_ GR_DEVICE device,
		_Inout_ GR_UINT* pDisplayCount,
		_Out_ GR_WSI_WIN_DISPLAY* pDisplayList);

	GR_RESULT grWsiWinGetDisplayModeList(
		_In_ GR_WSI_WIN_DISPLAY display,
		_Inout_ GR_UINT* pDisplayModeCount,
		_Out_ GR_WSI_WIN_DISPLAY_MODE* pDisplayModeList);

	GR_RESULT grWsiWinTakeFullscreenOwnership(
		_In_ GR_WSI_WIN_DISPLAY display,
		_In_ GR_IMAGE image);

	GR_RESULT grWsiWinReleaseFullscreenOwnership(
		_In_ GR_WSI_WIN_DISPLAY display);

	GR_RESULT grWsiWinSetGammaRamp(
		_In_ GR_WSI_WIN_DISPLAY display,
		_In_ const GR_WSI_WIN_GAMMA_RAMP* pGammaRamp);

	GR_RESULT grWsiWinWaitForVerticalBlank(
		_In_ GR_WSI_WIN_DISPLAY display);

	GR_RESULT grWsiWinGetScanLine(
		_In_ GR_WSI_WIN_DISPLAY display,
		_Out_ GR_INT* pScanLine);

	GR_RESULT grWsiWinCreatePresentableImage(
		_In_ GR_DEVICE device,
		_In_ const GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO* pCreateInfo,
		_Out_ GR_IMAGE* pImage,
		_Out_ GR_GPU_MEMORY* pMem);

	GR_RESULT grWsiWinQueuePresent(
		_In_ GR_QUEUE queue,
		_In_ const GR_WSI_WIN_PRESENT_INFO* pPresentInfo);

	GR_RESULT grWsiWinSetMaxQueuedFrames(
		_In_ GR_DEVICE device,
		_In_ GR_UINT maxFrames);


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // MANTLEWSIWINEXT_H_
