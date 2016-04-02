#include "mantle.h"
#include <Windows.h>
#include <iostream>

GR_DEVICE Device = GR_NULL_HANDLE;
GR_PHYSICAL_GPU_PROPERTIES pData = {};
GR_RESULT Result;

void InitMantle()
{
	HMODULE hModule = LoadLibrary("mantle64.dll");

	grInitAndEnumerateGpus = reinterpret_cast<InitAndEnumerateGpus>(
		GetProcAddress(hModule, "grInitAndEnumerateGpus"));
	grGetGpuInfo = reinterpret_cast<GetGpuInfo>(
		GetProcAddress(hModule, "grGetGpuInfo"));
	grCreateDevice = reinterpret_cast<CreateDevice>(
		GetProcAddress(hModule, "grCreateDevice"));
	grDestroyDevice = reinterpret_cast<DestroyDevice>(
		GetProcAddress(hModule, "grDestroyDevice"));

	GR_APPLICATION_INFO AppInfo{};
	AppInfo.apiVersion = GR_API_VERSION;
	AppInfo.pAppName = "InitMantle";

	GR_PHYSICAL_GPU gpus[GR_MAX_PHYSICAL_GPUS]{};
	GR_UINT GPUCount = 0;
	Result = grInitAndEnumerateGpus(&AppInfo, GR_NULL_HANDLE, &GPUCount, gpus);

	GR_SIZE pDataSize = 0;
	Result = grGetGpuInfo(gpus[0], GR_INFO_TYPE_PHYSICAL_GPU_QUEUE_PROPERTIES, &pDataSize, &pData);

	GR_DEVICE_QUEUE_CREATE_INFO QueueInfo{};
	QueueInfo.queueType = GR_QUEUE_UNIVERSAL;
	QueueInfo.queueCount = 1;

	static const GR_CHAR* const ppExtensions[] = { "GR_WSI_WINDOWS" };

	GR_DEVICE_CREATE_INFO DeviceInfo{};
	DeviceInfo.queueRecordCount = 1;
	DeviceInfo.pRequestedQueues = &QueueInfo;
	DeviceInfo.extensionCount = 1;
	DeviceInfo.ppEnabledExtensionNames = ppExtensions;
#if defined(DEBUG) || defined(_DEBUG)
	DeviceInfo.maxValidationLevel = GR_VALIDATION_LEVEL_4;
	DeviceInfo.flags |= GR_DEVICE_CREATE_VALIDATION;
#else
	DeviceInfo.maxValidationLevel = GR_VALIDATION_LEVEL_0;
#endif
	Result = grCreateDevice(gpus[0], &DeviceInfo, &Device);
}

int main()
{
	InitMantle();

	GR_UINT32 VendorID = pData.vendorId;
	GR_UINT32 DeviceID = pData.deviceId;
	GR_CHAR* GPUName = pData.gpuName;

	std::cout << "VendorID: " << VendorID <<
		std::endl << "DeviceID: " << DeviceID <<
		std::endl << "GPUName: " << GPUName << std::endl;

	std::cin.get();
	grDestroyDevice(Device);
	return 0;
}
