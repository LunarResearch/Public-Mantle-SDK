#include "MsgHelper.h"
#include <Windows.h>

GR_DEVICE Device = GR_NULL_HANDLE;
GR_PHYSICAL_GPU_PROPERTIES pData = {};
HMODULE hModule = 0;

void InitMantleAPI()
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


	//====================== grInitAndEnumerateGpus ======================
	GR_APPLICATION_INFO AppInfo = {};
	AppInfo.pAppName = "MantleInit";
	AppInfo.pEngineName = "MantleEngine";
	AppInfo.apiVersion = GR_API_VERSION;

	GR_UINT GPUCount;
	GR_PHYSICAL_GPU gpus[GR_MAX_PHYSICAL_GPUS];
	std::cout << "Initialization grInitAndEnumerateGpus: " << std::ends;
	MessageHelper(grInitAndEnumerateGpus(&AppInfo, GR_NULL_HANDLE, &GPUCount, gpus));
	//====================================================================


	//=========================== grGetGpuInfo ===========================
	GR_SIZE pDataSize = sizeof(GR_PHYSICAL_GPU_PROPERTIES);
	std::cout << "Initialization grGetGpuInfo:           " << std::ends;
	MessageHelper(grGetGpuInfo(gpus[0], GR_INFO_TYPE_PHYSICAL_GPU_PROPERTIES, &pDataSize, &pData));
	//====================================================================


	//========================== grCreateDevice ==========================
	GR_DEVICE_QUEUE_CREATE_INFO QueueInfo = {};
	QueueInfo.queueCount = 1;
	QueueInfo.queueType = GR_QUEUE_UNIVERSAL;

	GR_CHAR* ppExtensions[] = { "GR_WSI_WINDOWS", "GR_BORDER_COLOR_PALETTE" };

	GR_DEVICE_CREATE_INFO DeviceInfo = {};
	DeviceInfo.queueRecordCount = 1;
	DeviceInfo.pRequestedQueues = &QueueInfo;
	DeviceInfo.extensionCount = 2;
	DeviceInfo.ppEnabledExtensionNames = ppExtensions;
#if defined(DEBUG) || defined(_DEBUG)
	DeviceInfo.maxValidationLevel = GR_VALIDATION_LEVEL_4;
	DeviceInfo.flags |= GR_DEVICE_CREATE_VALIDATION;
#else
	DeviceInfo.maxValidationLevel = GR_VALIDATION_LEVEL_0;
#endif
	std::cout << "Initialization grCreateDevice:         " << std::ends;
	MessageHelper(grCreateDevice(gpus[0], &DeviceInfo, &Device));
	//====================================================================
}

int main()
{
	InitMantleAPI();

	if (Result == GR_SUCCESS)
	{
		std::cout << "VendorID: 0x" << std::hex << pData.vendorId <<
			std::endl << "DeviceID: 0x" << std::hex << pData.deviceId <<
			std::endl << "GPU Name: " << pData.gpuName << std::endl;

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
