#include "mantle.h"
#include <iostream>

#pragma comment (lib, "mantle64.lib")

int main()
{
	GR_APPLICATION_INFO AppInfo = {};
	AppInfo.apiVersion = GR_API_VERSION;

	GR_UINT GpuCount = 0;
	GR_PHYSICAL_GPU gpus[GR_MAX_PHYSICAL_GPUS] = {};
	GR_RESULT r1 = grInitAndEnumerateGpus(&AppInfo, GR_NULL_HANDLE, &GpuCount, gpus);

	GR_DEVICE_QUEUE_CREATE_INFO req = {};
	req.queueType = GR_QUEUE_UNIVERSAL;
	req.queueCount = 1;

	static const GR_CHAR* const pNames[] = { "GR_WSI_WINDOWS" };

	GR_DEVICE_CREATE_INFO DeviceInfo = {};
	DeviceInfo.queueRecordCount = 1;
	DeviceInfo.pRequestedQueues = &req;
	DeviceInfo.extensionCount = 1;
	DeviceInfo.ppEnabledExtensionNames = pNames;
#if defined(_DEBUG)
	DeviceInfo.maxValidationLevel = GR_VALIDATION_LEVEL_4;
	DeviceInfo.flags |= GR_DEVICE_CREATE_VALIDATION;
#else
	DeviceInfo.maxValidationLevel = GR_VALIDATION_LEVEL_0;
#endif

	GR_DEVICE device = GR_NULL_HANDLE;
	GR_RESULT r2 = grCreateDevice(gpus[0], &DeviceInfo, &device);

	GR_PHYSICAL_GPU_PROPERTIES prop = {};
	GR_SIZE size = sizeof(GR_PHYSICAL_GPU_PROPERTIES);
	GR_RESULT r3 = grGetGpuInfo(gpus[0], GR_INFO_TYPE_PHYSICAL_GPU_PROPERTIES, &size, &prop);

	std::cout << "VendorID: 0x" << std::hex << prop.vendorId << std::endl;
	std::cout << "DeviceID: 0x" << std::hex << prop.deviceId << std::endl;
	std::cout << "GPU Name: " << prop.gpuName << std::endl;

	grDestroyDevice(device);
	std::cin.get();
	return 0;
}
