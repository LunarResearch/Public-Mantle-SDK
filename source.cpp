#include "MsgHelper.h"
#include <Windows.h>

GR_DEVICE Device = GR_NULL_HANDLE;
GR_GPU_MEMORY GPUMemory = GR_NULL_HANDLE;
GR_BASE_OBJECT BaseObject = GR_NULL_HANDLE;
GR_OBJECT Object = GR_NULL_HANDLE;
GR_CMD_BUFFER CmdBuffer = GR_NULL_HANDLE;
GR_EVENT Event = GR_NULL_HANDLE;

GR_PHYSICAL_GPU_PROPERTIES GPUProperties = {};
HMODULE hModule = 0;

GR_GPU_MEMORY GetMatchingMemObjectAndOffset(GR_MEMORY_REQUIREMENTS* mem, GR_GPU_SIZE* size)
{
	GR_GPU_MEMORY val = 0;
	memset(mem, (GR_INT)val, (GR_SIZE)size);
	return val;
}

void LoadFunctions()
{
	hModule = LoadLibrary("mantle64.dll"); // or mantle32.dll for 32 bit app

	grInitAndEnumerateGpus = reinterpret_cast<InitAndEnumerateGpus>(
		GetProcAddress(hModule, "grInitAndEnumerateGpus"));
	grGetGpuInfo = reinterpret_cast<GetGpuInfo>(
		GetProcAddress(hModule, "grGetGpuInfo"));
	grCreateDevice = reinterpret_cast<CreateDevice>(
		GetProcAddress(hModule, "grCreateDevice"));
	grDestroyDevice = reinterpret_cast<DestroyDevice>(
		GetProcAddress(hModule, "grDestroyDevice"));
	grGetMemoryHeapCount = reinterpret_cast<GetMemoryHeapCount>(
		GetProcAddress(hModule, "grGetMemoryHeapCount"));
	grGetMemoryHeapInfo = reinterpret_cast<GetMemoryHeapInfo>(
		GetProcAddress(hModule, "grGetMemoryHeapInfo"));
	grAllocMemory = reinterpret_cast<AllocMemory>(
		GetProcAddress(hModule, "grAllocMemory"));
	grGetObjectInfo = reinterpret_cast<GetObjectInfo>(
		GetProcAddress(hModule, "grGetObjectInfo"));
	grCreateCommandBuffer = reinterpret_cast<CreateCommandBuffer>(
		GetProcAddress(hModule, "grCreateCommandBuffer"));
	grBeginCommandBuffer = reinterpret_cast<BeginCommandBuffer>(
		GetProcAddress(hModule, "grBeginCommandBuffer"));
	grCmdSetEvent = reinterpret_cast<CmdSetEvent>(
		GetProcAddress(hModule, "grCmdSetEvent"));
	grEndCommandBuffer = reinterpret_cast<EndCommandBuffer>(
		GetProcAddress(hModule, "grEndCommandBuffer"));
}

void InitMantleAPI()
{
	//====================== grInitAndEnumerateGpus ======================
	GR_APPLICATION_INFO AppInfo = {};
	AppInfo.apiVersion = GR_API_VERSION;

	GR_UINT GPUCount = 0;
	GR_PHYSICAL_GPU gpus[GR_MAX_PHYSICAL_GPUS] = {};
	std::cout << "Initialization grInitAndEnumerateGpus: " << std::ends;
	MessageHelper(grInitAndEnumerateGpus(&AppInfo, NULL, &GPUCount, gpus));
	//====================================================================


	//=========================== grGetGpuInfo ===========================
	GR_SIZE pSizeGpuInfo = sizeof(GR_PHYSICAL_GPU_PROPERTIES);
	std::cout << "Initialization grGetGpuInfo:           " << std::ends;
	MessageHelper(grGetGpuInfo(gpus[0],
		GR_INFO_TYPE_PHYSICAL_GPU_PROPERTIES, &pSizeGpuInfo, &GPUProperties));
	//====================================================================


	//========================== grCreateDevice ==========================
	GR_DEVICE_QUEUE_CREATE_INFO QueueCreateInfo = {};
	QueueCreateInfo.queueType = GR_QUEUE_UNIVERSAL;
	QueueCreateInfo.queueCount = 1;

	static const GR_CHAR* const ppExtensions[] = { "GR_WSI_WINDOWS" };

	GR_DEVICE_CREATE_INFO DeviceCreateInfo = {};
	DeviceCreateInfo.queueRecordCount = 1;
	DeviceCreateInfo.pRequestedQueues = &QueueCreateInfo;
	DeviceCreateInfo.extensionCount = 1;
	DeviceCreateInfo.ppEnabledExtensionNames = ppExtensions;
#if defined(DEBUG) || defined(_DEBUG)
	DeviceCreateInfo.maxValidationLevel = GR_VALIDATION_LEVEL_4;
	DeviceCreateInfo.flags |= GR_DEVICE_CREATE_VALIDATION;
#else
	DeviceCreateInfo.maxValidationLevel = GR_VALIDATION_LEVEL_0;
#endif
	std::cout << "Initialization grCreateDevice:         " << std::ends;
	MessageHelper(grCreateDevice(gpus[0], &DeviceCreateInfo, &Device));
	//====================================================================


	//======================= grGetMemoryHeapCount =======================
	GR_UINT HeapCount = 0;
	std::cout << "Initialization grGetMemoryHeapCount:   " << std::ends;
	MessageHelper(grGetMemoryHeapCount(Device, &HeapCount));
	//====================================================================


	//======================= grGetMemoryHeapInfo ========================
	GR_MEMORY_HEAP_PROPERTIES* pHeapInfo = new GR_MEMORY_HEAP_PROPERTIES[HeapCount];
	for (GR_UINT i = 0; i < HeapCount; i++)
	{
		GR_SIZE pSizeHeapInfo = sizeof(GR_MEMORY_HEAP_PROPERTIES);
		std::cout << "Initialization grGetMemoryHeapInfo:    " << std::ends;
		MessageHelper(grGetMemoryHeapInfo(Device, i,
			GR_INFO_TYPE_MEMORY_HEAP_PROPERTIES, &pSizeHeapInfo, &pHeapInfo[i]));
	}
	//====================================================================


	//========================== grAllocMemory ===========================
	GR_UINT firstHeapChoiceId = 0;
	GR_UINT64 gpuPageSize = 1024;
	GR_UINT64 numPages = 1024;
	GR_MEMORY_ALLOC_INFO MemoryAllocInfo = {};
	MemoryAllocInfo.size = gpuPageSize * numPages;
	MemoryAllocInfo.alignment = 0;
	MemoryAllocInfo.memPriority = GR_MEMORY_PRIORITY_NORMAL;
	MemoryAllocInfo.heapCount = 1;
	MemoryAllocInfo.heaps[0] = firstHeapChoiceId;
	std::cout << "Initialization grAllocMemory:          " << std::ends;
	MessageHelper(grAllocMemory(Device, &MemoryAllocInfo, &GPUMemory));
	//====================================================================


	//========================= grGetObjectInfo ==========================
	GR_MEMORY_REQUIREMENTS MemoryRequirements = {};
	GR_SIZE pSizeObjectInfo = sizeof(GR_MEMORY_REQUIREMENTS);
	std::cout << "Initialization grGetObjectInfo:        " << std::ends;
	MessageHelper(grGetObjectInfo(BaseObject,
		GR_INFO_TYPE_MEMORY_REQUIREMENTS, &pSizeObjectInfo, &MemoryRequirements));
	//====================================================================


	//========================== grCreateDevice ==========================
	if (MemoryRequirements.size > 0)
	{
		GR_GPU_SIZE BindOffset = 0;
		GR_GPU_MEMORY GPUMemoryBind = GetMatchingMemObjectAndOffset(&MemoryRequirements, &BindOffset);
		std::cout << "Initialization grBindObjectMemory:     " << std::ends;
		MessageHelper(grBindObjectMemory(Object, GPUMemoryBind, BindOffset));
	}
	//====================================================================


	//====================== grCreateCommandBuffer =======================
	GR_CMD_BUFFER_CREATE_INFO CmdBufferCreateInfo = {};
	CmdBufferCreateInfo.queueType = GR_QUEUE_COMPUTE;
	std::cout << "Initialization grCreateCommandBuffer:  " << std::ends;
	MessageHelper(grCreateCommandBuffer(Device, &CmdBufferCreateInfo, &CmdBuffer));
	//====================================================================


	//======================= grBeginCommandBuffer =======================
	std::cout << "Initialization grBeginCommandBuffer:   " << std::ends;
	MessageHelper(grBeginCommandBuffer(CmdBuffer, GR_CMD_BUFFER_OPTIMIZE_ONE_TIME_SUBMIT));
	//====================================================================


	//========================== grCmdSetEvent ===========================
	//std::cout << "Initialization grCmdSetEvent:          " << std::ends;
	grCmdSetEvent(CmdBuffer, Event);
	//====================================================================


	//======================== grEndCommandBuffer ========================
	std::cout << "Initialization grEndCommandBuffer:     " << std::ends;
	MessageHelper(grEndCommandBuffer(CmdBuffer));
	//====================================================================
}

int main()
{
	LoadFunctions();
	InitMantleAPI();

	if (Result == GR_SUCCESS)
	{
		std::cout << "VendorID: 0x" << std::hex << GPUProperties.vendorId <<
			std::endl << "DeviceID: 0x" << std::hex << GPUProperties.deviceId <<
			std::endl << "GPU Name: " << GPUProperties.gpuName << std::endl;

		std::cin.get();
		grDestroyDevice(Device);
		FreeLibrary(hModule);
		return 0;
	}

	else
	{
		std::cin.get();
		FreeLibrary(hModule);
		std::exit(-1);
	}
}
