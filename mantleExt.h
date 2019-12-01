#pragma once
#ifndef MANTLEEXT_H_
#define MANTLEEXT_H_

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif


	GR_HANDLE(GR_DISPLAY);


#define GR_MAX_PRIVATE_DISPLAYS 16


	// ======================================================
	// ==================== ENUMERATIONS ====================
	// ======================================================
	typedef enum _GR_EXT_INFO_TYPE {
		GR_EXT_INFO_TYPE_PHYSICAL_GPU_SUPPORTED_AXL_VERSION = 0x00306100,
		GR_EXT_INFO_TYPE_QUEUE_BORDER_COLOR_PALETTE_PROPERTIES = 0x00306800,
		GR_EXT_INFO_TYPE_QUEUE_CONTROL_FLOW_PROPERTIES = 0x00306801,
	} GR_EXT_INFO_TYPE;

	typedef enum _GR_EXT_BORDER_COLOR_TYPE {
		GR_EXT_BORDER_COLOR_TYPE_PALETTE_ENTRY_0 = 0x0030a000,
	} GR_EXT_BORDER_COLOR_TYPE;

	typedef enum _GR_EXT_IMAGE_STATE {
		GR_EXT_IMAGE_STATE_GRAPHICS_SHADER_FMASK_LOOKUP = 0x00300100,
		GR_EXT_IMAGE_STATE_COMPUTE_SHADER_FMASK_LOOKUP = 0x00300101,
		GR_EXT_IMAGE_STATE_DATA_TRANSFER_DMA_QUEUE = 0x00300102,
	} GR_EXT_IMAGE_STATE;

	typedef enum _GR_EXT_MEMORY_STATE {
		GR_EXT_MEMORY_STATE_COPY_OCCLUSION_DATA = 0x00300000,
		GR_EXT_MEMORY_STATE_CMD_CONTROL = 0x00300001,
	} GR_EXT_MEMORY_STATE;

	typedef enum _GR_EXT_OCCLUSION_CONDITION {
		GR_EXT_OCCLUSION_CONDITION_VISIBLE = 0x00300300,
		GR_EXT_OCCLUSION_CONDITION_INVISIBLE = 0x00300301,
	} GR_EXT_OCCLUSION_CONDITION;

	typedef enum _GR_EXT_QUEUE_TYPE {
		GR_EXT_QUEUE_DMA = 0x00300200,
		GR_EXT_QUEUE_TIMER = 0x00300201,
	} GR_EXT_QUEUE_TYPE;


	// ==================== FLAGS ====================
	typedef enum _GR_EXT_CONTROL_FLOW_FEATURE_FLAGS {
		GR_EXT_CONTROL_FLOW_OCCLUSION_PREDICATION = 0x00000001,
		GR_EXT_CONTROL_FLOW_MEMORY_PREDICATION = 0x00000002,
		GR_EXT_CONTROL_FLOW_CONDITIONAL_EXECUTION = 0x00000004,
		GR_EXT_CONTROL_FLOW_LOOP_EXECUTION = 0x00000008,
	} GR_EXT_CONTROL_FLOW_FEATURE_FLAGS;

	typedef enum _GR_EXT_ACCESS_CLIENT {
		GR_EXT_ACCESS_DEFAULT = 0x00000000,
		GR_EXT_ACCESS_CPU = 0x01000000,
		GR_EXT_ACCESS_UNIVERSAL_QUEUE = 0x02000000,
		GR_EXT_ACCESS_COMPUTE_QUEUE = 0x04000000,
		GR_EXT_ACCESS_DMA_QUEUE = 0x08000000,
	} GR_EXT_ACCESS_CLIENT;


	// ==================== STRUCTURES ====================
	typedef struct _GR_PHYSICAL_GPU_SUPPORTED_AXL_VERSION {
		GR_UINT32 minVersion;
		GR_UINT32 maxVersion;
	} GR_PHYSICAL_GPU_SUPPORTED_AXL_VERSION;

	typedef struct _GR_BORDER_COLOR_PALETTE_PROPERTIES {
		GR_UINT maxPaletteSize;
	} GR_BORDER_COLOR_PALETTE_PROPERTIES;

	typedef struct _GR_BORDER_COLOR_PALETTE_CREATE_INFO {
		GR_UINT paletteSize;
	} GR_BORDER_COLOR_PALETTE_CREATE_INFO;

	typedef struct _GR_MSAA_QUAD_SAMPLE_PATTERN {
		GR_OFFSET2D topLeft[GR_MAX_MSAA_RASTERIZER_SAMPLES];
		GR_OFFSET2D topRight[GR_MAX_MSAA_RASTERIZER_SAMPLES];
		GR_OFFSET2D bottomLeft[GR_MAX_MSAA_RASTERIZER_SAMPLES];
		GR_OFFSET2D bottomRight[GR_MAX_MSAA_RASTERIZER_SAMPLES];
	} GR_MSAA_QUAD_SAMPLE_PATTERN;

	typedef struct _GR_ADVANCED_MSAA_STATE_CREATE_INFO {
		GR_UINT coverageSamples;
		GR_UINT pixelShaderSamples;
		GR_UINT depthStencilSamples;
		GR_UINT colorTargetSamples;
		GR_SAMPLE_MASK sampleMask;
		GR_UINT sampleClusters;
		GR_UINT alphaToCoverageSamples;
		GR_BOOL disableAlphaToCoverageDither;
		GR_BOOL customSamplePatternEnable;
		GR_MSAA_QUAD_SAMPLE_PATTERN customSamplePattern;
	} GR_ADVANCED_MSAA_STATE_CREATE_INFO;

	typedef struct _GR_FMASK_IMAGE_VIEW_CREATE_INFO {
		GR_IMAGE image;
		GR_UINT baseArraySlice;
		GR_UINT arraySize;
	} GR_FMASK_IMAGE_VIEW_CREATE_INFO;

	typedef struct _GR_QUEUE_CONTROL_FLOW_PROPERTIES {
		GR_UINT maxNestingLimit;
		GR_EXT_CONTROL_FLOW_FEATURE_FLAGS controlFlowOperations;
	} GR_QUEUE_CONTROL_FLOW_PROPERTIES;

	typedef struct _GR_GPU_TIMESTAMP_CALIBRATION {
		GR_UINT64 gpuTimestamp;
		union {
			GR_UINT64 cpuWinPerfCounter;
			GR_BYTE _padding[16];
		};
	} GR_GPU_TIMESTAMP_CALIBRATION;

	typedef struct _GR_PERF_EXPERIMENT_CREATE_INFO {

	} GR_PERF_EXPERIMENT_CREATE_INFO;

	typedef struct _GR_PRIVATE_DISPLAY_IMAGE_CREATE_INFO {
		// display
	} GR_PRIVATE_DISPLAY_IMAGE_CREATE_INFO;

	typedef struct _GR_VIRTUAL_DISPLAY_CREATE_INFO {

	} GR_VIRTUAL_DISPLAY_CREATE_INFO;

	typedef struct _GR_ENABLE_PRIVATE_DISPLAY_CREATE_INFO {

	} GR_ENABLE_PRIVATE_DISPLAY_CREATE_INFO;

	typedef struct _GR_PRIVATE_DISPALY_SCANLINE_CREATE_INFO {

	} GR_PRIVATE_DISPALY_SCANLINE_CREATE_INFO;

	typedef struct _GR_OPEN_EXTERNAL_SHARED_PRIVATE_DISPLAY_IMAGE_CREATE_INFO {
		// display;
		// externalImage;
	} GR_OPEN_EXTERNAL_SHARED_PRIVATE_DISPLAY_IMAGE_CREATE_INFO;

	typedef struct _GR_PRIVATE_DISPLAY_PRESENT_CREATE_INFO {
		// srcImage;
		// presentDoneFence;
	} GR_PRIVATE_DISPLAY_PRESENT_CREATE_INFO;


	// ==================== FUNCTIONS ====================
	GR_UINT32 grGetExtensionLibraryVersion();

	GR_RESULT grCreateBorderColorPalette(
		GR_DEVICE device,
		const GR_BORDER_COLOR_PALETTE_CREATE_INFO* pCreateInfo,
		GR_BORDER_COLOR_PALETTE* pPalette);

	GR_RESULT grUpdateBorderColorPalette(
		GR_BORDER_COLOR_PALETTE palette,
		GR_UINT firstEntry,
		GR_UINT entryCount,
		const GR_FLOAT* pEntries);

	GR_VOID grCmdBindBorderColorPalette(
		GR_CMD_BUFFER cmdBuffer,
		GR_PIPELINE_BIND_POINT pipelineBindPoint,
		GR_BORDER_COLOR_PALETTE palette);

	GR_RESULT grCreateAdvancedMsaaState(
		GR_DEVICE device,
		const GR_ADVANCED_MSAA_STATE_CREATE_INFO* pCreateInfo,
		GR_MSAA_STATE_OBJECT* pState);

	GR_RESULT grCreateFmaskImageView(
		GR_DEVICE device,
		const GR_FMASK_IMAGE_VIEW_CREATE_INFO* pCreateInfo,
		GR_IMAGE_VIEW* pView);

	GR_RESULT grCmdCopyOcclusionData(
		GR_CMD_BUFFER cmdBuffer,
		GR_QUERY_POOL queryPool,
		GR_UINT startQuery,
		GR_UINT queryCount,
		GR_GPU_MEMORY destMem,
		GR_GPU_SIZE destOffset,
		GR_BOOL accumulateData);

	GR_VOID grCmdSetOcclusionPredication(
		GR_CMD_BUFFER cmdBuffer,
		GR_QUERY_POOL queryPool,
		GR_UINT slot,
		GR_EXT_OCCLUSION_CONDITION condition,
		GR_BOOL waitResults,
		GR_BOOL accumulateData);

	GR_VOID grCmdResetOcclusionPredication(
		GR_CMD_BUFFER cmdBuffer);

	GR_VOID grCmdSetMemoryPredication(
		GR_CMD_BUFFER cmdBuffer,
		GR_GPU_MEMORY mem,
		GR_GPU_SIZE offset);

	GR_VOID grCmdResetMemoryPredication(
		GR_CMD_BUFFER cmdBuffer);

	GR_VOID grCmdIf(
		GR_CMD_BUFFER cmdBuffer,
		GR_GPU_MEMORY srcMem,
		GR_GPU_SIZE srcOffset,
		GR_UINT64 data,
		GR_UINT64 mask,
		GR_COMPARE_FUNC func);

	GR_VOID grCmdElse(
		GR_CMD_BUFFER cmdBuffer);

	GR_VOID grCmdEndIf(
		GR_CMD_BUFFER cmdBuffer);

	GR_VOID grCmdWhile(
		GR_CMD_BUFFER cmdBuffer,
		GR_GPU_MEMORY srcMem,
		GR_GPU_SIZE srcOffset,
		GR_UINT64 data,
		GR_UINT64 mask,
		GR_COMPARE_FUNC func);

	GR_VOID grCmdEndWhile(
		GR_CMD_BUFFER cmdBuffer);

	GR_RESULT grQueueDelay(
		GR_QUEUE queue,
		GR_FLOAT delay);

	GR_RESULT grCalibrateGpuTimestamp(
		GR_DEVICE device,
		GR_GPU_TIMESTAMP_CALIBRATION* pCalibrationData);


	// From new API version 10.1.9.xxx
	// Mantle Programming Guide (Revision 1.0; March 6, 2015) is maximum for API version 10.1.9.45

	GR_RESULT grAddEmulatedPrivateDisplay(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3);

	GR_RESULT grAddPerfExperimentCounter(
		GR_PERF_EXPERIMENT perfExperiment,
		__int64 a2);

	GR_RESULT grAddPerfExperimentTrace(
		GR_PERF_EXPERIMENT perfExperiment,
		__int64 a2);

	GR_RESULT grBlankPrivateDisplay(
		GR_DISPLAY display);

	GR_RESULT grCmdBeginPerfExperiment(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2);

	GR_RESULT grCmdBindUserData(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		__int64 a3,
		GR_SIZE* pDataSize,
		GR_VOID* pData);

	GR_RESULT grCmdCopyRegisterToMemory(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		__int64 a3,
		__int64 a4);

	GR_RESULT grCmdDispatchOffset(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		unsigned int a3,
		unsigned int a4,
		int a5,
		int a6,
		int a7);

	GR_RESULT grCmdDispatchOffsetIndirect(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2,
		__int64 a3);

	GR_RESULT grCmdEndPerfExperiment(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2);

	GR_RESULT grCmdInsertTraceMarker(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		unsigned int a3);

	GR_RESULT grCmdWaitMemoryValue(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2,
		__int64 a3,
		unsigned int a4,
		int a5,
		int a6);

	GR_RESULT grCmdWaitRegisterValue(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		unsigned int a3,
		unsigned int a4,
		int a5);

	GR_RESULT grCreateFmaskImageView(
		GR_DEVICE device,
		const GR_FMASK_IMAGE_VIEW_CREATE_INFO* pCreateInfo,
		GR_IMAGE_VIEW* pImageView);

	GR_RESULT grCreatePerfExperiment(
		GR_DEVICE device,
		const GR_PERF_EXPERIMENT_CREATE_INFO* pCreateInfo,
		GR_PERF_EXPERIMENT* pPerfExperiment);

	GR_RESULT grCreatePrivateDisplayImage(
		GR_DEVICE device,
		const GR_PRIVATE_DISPLAY_IMAGE_CREATE_INFO* pCreateInfo,
		GR_IMAGE* pImage,
		GR_GPU_MEMORY* pMem);

	GR_RESULT grCreateVirtualDisplay(
		GR_DEVICE device,
		const GR_VIRTUAL_DISPLAY_CREATE_INFO* pCreateInfo,
		GR_DISPLAY* display);

	GR_RESULT grDestroyVirtualDisplay(
		GR_DEVICE device,
		GR_DISPLAY display);

	GR_RESULT grDisablePrivateDisplay(
		GR_DISPLAY display);

	GR_RESULT grEnablePrivateDisplay(
		GR_DISPLAY display,
		const GR_ENABLE_PRIVATE_DISPLAY_CREATE_INFO* pEnableInfo);

	GR_RESULT grEnablePrivateDisplayAudio(
		GR_DISPLAY display,
		unsigned int a2);

	GR_RESULT grFinalizePerfExperiment(
		GR_PERF_EXPERIMENT perfExperiment);

	GR_RESULT grGetPrivateDisplayScanLine(
		GR_DISPLAY display,
		const GR_PRIVATE_DISPALY_SCANLINE_CREATE_INFO* pScanLine);

	GR_RESULT grGetPrivateDisplays(
		GR_DEVICE device,
		GR_UINT* pDisplayCount,
		GR_DISPLAY displays[GR_MAX_PRIVATE_DISPLAYS]);

	GR_RESULT grGetVirtualDisplayProperties(
		GR_DEVICE device,
		unsigned int a2,
		__int64 a3);

	GR_RESULT grOpenExternalSharedPrivateDisplayImage(
		GR_DEVICE device,
		const GR_OPEN_EXTERNAL_SHARED_PRIVATE_DISPLAY_IMAGE_CREATE_INFO* pOpenInfo);

	GR_RESULT grPrivateDisplayPresent(
		GR_DEVICE device,
		const GR_PRIVATE_DISPLAY_PRESENT_CREATE_INFO* pPresentInfo);

	/*
	grQueueDelayAfterVsync
	grQueueMigrateObjects
	grQueueSetExecutionPriority
	grRegisterPowerEvent
	grRegisterPrivateDisplayEvent
	grRemoveEmulatedPrivateDisplay
	grSetEventAfterVsync
	grSetPowerDefaultPerformance
	grSetPowerProfile
	grSetPowerRegions
	grSetPrivateDisplayPowerMode
	grSetPrivateDisplaySettings
	grWinOpenExternalSharedImage
	grWinOpenExternalSharedMemory
	grWinOpenExternalSharedQueueSemaphore
	*/

#ifdef __cplusplus
}
#endif
#endif
