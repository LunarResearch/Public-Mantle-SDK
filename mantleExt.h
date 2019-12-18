/*

Module Name:

	mantleExt.h

Abstract:

	AMD Mantle extension interface

*/


#ifndef MANTLEEXT_H_
#define MANTLEEXT_H_

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


	GR_HANDLE(GR_PERF_EXPERIMENT);
	GR_HANDLE(GR_PRIVATE_DISPLAY);
	GR_HANDLE(GR_VIRTUAL_DISPLAY);


#define GR_MAX_MSAA_RASTERIZER_SAMPLES 16
#define GR_MAX_PRIVATE_DISPLAYS 4


#define GR_DMA_QUEUE_EXTENSION_NAME "GR_DMA_QUEUE"
#define GR_CONTROL_FLOW_EXTENSION_NAME "GR_CONTROL_FLOW"
#define GR_TIMER_QUEUE_EXTENSION_NAME "GR_TIMER_QUEUE"

#define GR_RESOURCE_STATE_ACCESS_EXTENSION_NAME "GR_RESOURCE_STATE_ACCESS"
#define GR_OBJECT_MIGRATION_EXTENSION_NAME "GR_OBJECT_MIGRATION"
#define GR_REGMEM_ACCESS_EXTENSION_NAME "GR_REGMEM_ACCESS"
#define GR_PIPELINE_USER_DATA_EXTENSION_NAME "GR_PIPELINE_USER_DATA"
#define GR_DEDICATED_COMPUTE_QUEUE_EXTENSION_NAME "GR_DEDICATED_COMPUTE_QUEUE"
#define GR_BINDLESS_RESOURCES_EXTENSION_NAME "GR_BINDLESS_RESOURCES"


	// ======================================================
	// ==================== ENUMERATIONS ====================
	// ======================================================
	typedef enum _GR_EXT_INFO_TYPE {
		GR_EXT_INFO_TYPE_PHYSICAL_GPU_SUPPORTED_AXL_VERSION = 0x00306100,
		// GR_EXT_INFO_TYPE_PERF_EXPERIMENT_PROPERTIES = 0x00306,
		// GR_EXT_INFO_TYPE_GLOBAL_COUNTER_LAYOUT = 0x00306,
		// GR_EXT_INFO_TYPE_THREAD_TRACE_LAYOUT = 0x00306,
		// GR_EXT_INFO_TYPE_SPM_TRACE_LAYOUT = 0x00306,
		// GR_EXT_INFO_TYPE_GPU_MEMORY_VIRTUAL_ADDRESS = 0x00306,
		// GR_EXT_INFO_TYPE_DESCRIPTOR_SET_SLOT_STRIDE = 0x00306,
		// GR_EXT_INFO_TYPE_PHYSICAL_GPU_DISPLAY_CONNECTOR = 0x00306,
		// GR_EXT_INFO_TYPE_PRIVATE_DISPLAY_PROPERTIES = 0x00306,
		// GR_EXT_INFO_TYPE_PRIVATE_DISPLAY_PRESENT_STATS = 0x00306,
		// GR_EXT_INFO_TYPE_PRIVATE_DISPLAY_CONNECTOR_PROPERTIES = 0x00306,
		// GR_EXT_INFO_TYPE_PRIVATE_DISPLAY_MODE = 0x00306,
		// GR_EXT_INFO_TYPE_PRIVATE_DISPLAY_HDCP_STATUS = 0x00306,
		// GR_EXT_INFO_TYPE_PHYSICAL_GPU_VIRTUAL_DISPLAY_PROPERTIES = 0x00306,
		GR_EXT_INFO_TYPE_QUEUE_BORDER_COLOR_PALETTE_PROPERTIES = 0x00306800,
		GR_EXT_INFO_TYPE_QUEUE_CONTROL_FLOW_PROPERTIES = 0x00306801,
	} GR_EXT_INFO_TYPE;

	typedef enum _GR_EXT_BORDER_COLOR_TYPE {
		GR_EXT_BORDER_COLOR_TYPE_PALETTE_ENTRY_0 = 0x0030a000,
	} GR_EXT_BORDER_COLOR_TYPE;

	typedef enum _GR_EXT_PRIVATE_DISPLAY {
		// GR_EXT_PRIVATE_DISPLAY_PRESENT_VSYNC = 0x003,
	} GR_EXT_PRIVATE_DISPLAY;

	typedef enum _GR_EXT_IMAGE_STATE {
		GR_EXT_IMAGE_STATE_GRAPHICS_SHADER_FMASK_LOOKUP = 0x00300100,
		GR_EXT_IMAGE_STATE_COMPUTE_SHADER_FMASK_LOOKUP = 0x00300101,
		GR_EXT_IMAGE_STATE_DATA_TRANSFER_DMA_QUEUE = 0x00300102,
		GR_EXT_IMAGE_STATE_PRESENT_AND_SHADER_WRITE_ONLY = 0x00300103,
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
		GR_EXT_QUEUE_DEDICATED_COMPUTE = 0x00300202,
	} GR_EXT_QUEUE_TYPE;


	// ======================================================
	// ======================= FLAGS ========================
	// ======================================================
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


	// ======================================================
	// ==================== STRUCTURES ======================
	// ======================================================
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


	// ======================================================
	// ===================== FUNCTIONS ======================
	// ======================================================
	GR_UINT32 grGetExtensionLibraryVersion();

	// ======================================================
		// BORDER COLOR PALETTE FUNCTIONS
	// ======================================================
#define GR_BORDER_COLOR_PALETTE_EXTENSION_NAME "GR_BORDER_COLOR_PALETTE"
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

	// ======================================================
		// ADVANCED MSAA FUNCTIONS
	// ======================================================
#define GR_ADVANCED_MSAA_EXTENSION_NAME "GR_ADVANCED_MSAA"
	GR_RESULT grCreateAdvancedMsaaState(
		GR_DEVICE device,
		const GR_ADVANCED_MSAA_STATE_CREATE_INFO* pCreateInfo,
		GR_MSAA_STATE_OBJECT* pState);

	GR_RESULT grCreateFmaskImageView(
		GR_DEVICE device,
		const GR_FMASK_IMAGE_VIEW_CREATE_INFO* pCreateInfo,
		GR_IMAGE_VIEW* pView);

	// ======================================================
		// OCCLUSION DATA FUNCTIONS
	// ======================================================
#define GR_COPY_OCCLUSION_DATA_EXTENSION_NAME "GR_COPY_OCCLUSION_DATA"
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

	// ======================================================
		// 
	// ======================================================
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

#define GR_GPU_TIMESTAMP_CALIBRATION_EXTENSION_NAME "GR_GPU_TIMESTAMP_CALIBRATION"
	GR_RESULT grCalibrateGpuTimestamp(
		GR_DEVICE device,
		GR_GPU_TIMESTAMP_CALIBRATION* pCalibrationData);


	// ======================================================
	// From new API version 10.1.9.xxx
	// 
	// Mantle Programming Guide (Revision 1.0; March 6, 2015)
	// is maximum for API version 10.1.9.45
	// ======================================================

	// ======================================================
		// PRIVATE DISPLAY
	// ======================================================
	typedef struct _GR_ADD_EMULATE_PRIVATE_DISPALY_CREATE_INFO {
		// pDisplayId;
	} GR_ADD_EMULATE_PRIVATE_DISPALY_CREATE_INFO;

	typedef struct _GR_PRIVATE_DISPLAY_IMAGE_CREATE_INFO {
		GR_PRIVATE_DISPLAY display;
	} GR_PRIVATE_DISPLAY_IMAGE_CREATE_INFO;

	typedef struct _GR_ENABLE_PRIVATE_DISPLAY_CREATE_INFO {
		// 
	} GR_ENABLE_PRIVATE_DISPLAY_CREATE_INFO;

	typedef struct _GR_OPEN_EXTERNAL_SHARED_PRIVATE_DISPLAY_IMAGE_CREATE_INFO {
		// display;
		// externalImage;
	} GR_OPEN_EXTERNAL_SHARED_PRIVATE_DISPLAY_IMAGE_CREATE_INFO;

	typedef struct _GR_EXT_PRIVATE_DISPLAY_PRESENT_INFO {
		GR_IMAGE srcImage;
		GR_FENCE presentDoneFence;
		GR_EXT_PRIVATE_DISPLAY display;
	} GR_EXT_PRIVATE_DISPLAY_PRESENT_INFO;


#define GR_PRIVATE_DISPLAY_EXTENSION_NAME "GR_PRIVATE_DISPLAY"
	GR_RESULT grGetPrivateDisplays(
		_In_ GR_DEVICE device,
		_Inout_ GR_UINT* pDisplayCount,
		_Out_ GR_PRIVATE_DISPLAY displays[GR_MAX_PRIVATE_DISPLAYS]);

	GR_RESULT grCreatePrivateDisplayImage(
		_In_ GR_DEVICE device,
		_In_ const GR_PRIVATE_DISPLAY_IMAGE_CREATE_INFO* pCreateInfo,
		_Out_ GR_IMAGE* pImage,
		_Out_ GR_GPU_MEMORY* pMem);

	GR_RESULT grRemoveEmulatedPrivateDisplay(
		GR_DEVICE device,
		unsigned int a2);

	GR_RESULT grBlankPrivateDisplay(
		GR_PRIVATE_DISPLAY display);

	GR_RESULT grDisablePrivateDisplay(
		GR_PRIVATE_DISPLAY display);

	GR_RESULT grEnablePrivateDisplay(
		GR_PRIVATE_DISPLAY display,
		const GR_ENABLE_PRIVATE_DISPLAY_CREATE_INFO* pEnableInfo);

	GR_RESULT grEnablePrivateDisplayAudio(
		GR_PRIVATE_DISPLAY display,
		unsigned int a2);

	GR_RESULT grGetPrivateDisplayScanLine(
		_In_ GR_PRIVATE_DISPLAY display,
		_Out_ GR_INT* pScanLine);

	GR_RESULT grAddEmulatedPrivateDisplay(
		GR_DEVICE device,
		const GR_ADD_EMULATE_PRIVATE_DISPALY_CREATE_INFO* pEmulateInfo,
		GR_UINT* pTargetId);

	GR_RESULT grOpenExternalSharedPrivateDisplayImage(
		GR_DEVICE device,
		const GR_OPEN_EXTERNAL_SHARED_PRIVATE_DISPLAY_IMAGE_CREATE_INFO* pOpenInfo);

	GR_RESULT grPrivateDisplayPresent(
		GR_DEVICE device,
		const GR_EXT_PRIVATE_DISPLAY_PRESENT_INFO* pPresentInfo);

	GR_RESULT grRegisterPrivateDisplayEvent(
		GR_DEVICE device,
		__int64 a2);

	GR_RESULT grSetPrivateDisplayPowerMode(
		GR_PRIVATE_DISPLAY display,
		unsigned int a2);

	GR_RESULT grSetPrivateDisplaySettings(
		GR_PRIVATE_DISPLAY display,
		unsigned int a2,
		__int64 a3,
		__int64 a4);

	
	// ======================================================
		// VIRTUAL DISPLAY
	// ======================================================
	typedef struct _GR_VIRTUAL_DISPLAY_CREATE_INFO {
		// 
	} GR_VIRTUAL_DISPLAY_CREATE_INFO;

	typedef struct _GR_VIRTUAL_DISPLAY_PROPERTIES {
		// 
	} GR_VIRTUAL_DISPLAY_PROPERTIES;


#define GR_VIRTUAL_DISPLAY_EXTENSION_NAME "GR_VIRTUAL_DISPLAY"
	GR_RESULT grCreateVirtualDisplay(
		GR_DEVICE device,
		const GR_VIRTUAL_DISPLAY_CREATE_INFO* pCreateInfo,
		GR_VIRTUAL_DISPLAY* display);

	GR_RESULT grDestroyVirtualDisplay(
		GR_DEVICE device,
		GR_VIRTUAL_DISPLAY display);

	GR_RESULT grGetVirtualDisplayProperties(
		GR_DEVICE device,
		GR_EXT_INFO_TYPE infoType,
		GR_VOID* pData);


	// ======================================================
		// PERF EXPERIMENT FUNCTIONS
	// ======================================================
	typedef struct _GR_PERF_EXPERIMENT_CREATE_INFO {
		// 
	} GR_PERF_EXPERIMENT_CREATE_INFO;


#define GR_PERF_PROFILE_EXTENSION_NAME "GR_PERF_PROFILE"
	GR_RESULT grCreatePerfExperiment(
		GR_DEVICE device,
		const GR_PERF_EXPERIMENT_CREATE_INFO* pCreateInfo,
		GR_PERF_EXPERIMENT* pPerfExperiment);

	GR_RESULT grAddPerfExperimentCounter(
		GR_PERF_EXPERIMENT perfExperiment,
		__int64 a2);
	
	GR_RESULT grAddPerfExperimentTrace(
		GR_PERF_EXPERIMENT perfExperiment,
		__int64 a2);

	GR_VOID grCmdBeginPerfExperiment(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2);

	GR_VOID grCmdEndPerfExperiment(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2);

	GR_RESULT grFinalizePerfExperiment(
		GR_PERF_EXPERIMENT perfExperiment);

	
	// ======================================================
		// 
	// ======================================================

	/*Private display doesn't have V-sync enabled when grQueueDelayAfterVsync is called.
	This behavior could be still valid if a following grPrivateDisplayPresent with GR_EXT_PRIVATE_DISPLAY_PRESENT_VSYNC enables V-sync,
	however it is time sensitive and the result might be undefined.*/
	GR_RESULT grQueueDelayAfterVsync(
		GR_QUEUE queue,
		__int64 a2,
		unsigned int a3);

	GR_RESULT grSetEventAfterVsync(
		__int64 display,
		__int64 a2,
		unsigned int a3,
		unsigned int a4);

	GR_RESULT grQueueMigrateObjects(
		GR_QUEUE queue,
		unsigned int a2,
		__int64 a3,
		__int64 a4);

#define GR_QUEUE_PRIORITY_EXTENSION_NAME "GR_QUEUE_PRIORITY"
	GR_RESULT grQueueSetExecutionPriority(
		GR_QUEUE queue,
		unsigned int a2);


	// ======================================================
		// POWER PROFILE FUNCTIONS
	// ======================================================
#define GR_POWER_PROFILE_EXTENSION_NAME "GR_POWER_PROFILE"
	GR_RESULT grSetPowerProfile(
		GR_DEVICE device,
		unsigned int a2);

	GR_RESULT grRegisterPowerEvent(
		GR_DEVICE device,
		__int64 a2);

	GR_RESULT grSetPowerDefaultPerformance(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3);

	GR_RESULT grSetPowerRegions(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3);


	// ======================================================
		// WIN EXTERNAL SHARED RESOURCE FUNCTIONS
	// ======================================================
#define GR_WIN_EXTERNAL_SHARED_RESOURCE_EXTENSION_NAME "GR_WIN_EXTERNAL_SHARED_RESOURCE"
	GR_RESULT grWinAllocMemory(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3,
		__int64 a4,
		__int64 a5);

	GR_RESULT grWinOpenExternalSharedImage(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3,
		__int64 a4);

	GR_RESULT grWinOpenExternalSharedMemory(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3);

	GR_RESULT grWinOpenExternalSharedQueueSemaphore(
		GR_DEVICE device,
		__int64 a2,
		__int64 a3);


	// ======================================================
		// COMMAND BUFFER BUILDING EXTENSION FUNCTIONS
	// ======================================================
	GR_VOID grCmdBindUserData(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		__int64 a3,
		GR_SIZE* pDataSize,
		GR_VOID* pData);

	GR_VOID grCmdCopyRegisterToMemory(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		__int64 a3,
		__int64 a4);

#define GR_DISPATCH_OFFSET_EXTENSION_NAME "GR_DISPATCH_OFFSET"
	GR_VOID grCmdDispatchOffset(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		unsigned int a3,
		unsigned int a4,
		int a5,
		int a6,
		int a7);

	GR_VOID grCmdDispatchOffsetIndirect(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2,
		__int64 a3);

	GR_VOID grCmdInsertTraceMarker(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		unsigned int a3);

	GR_VOID grCmdWaitMemoryValue(
		GR_CMD_BUFFER cmdBuffer,
		__int64 a2,
		__int64 a3,
		unsigned int a4,
		int a5,
		int a6);

	GR_VOID grCmdWaitRegisterValue(
		GR_CMD_BUFFER cmdBuffer,
		unsigned int a2,
		unsigned int a3,
		unsigned int a4,
		int a5);


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // MANTLEEXT_H_
