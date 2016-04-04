#include "MsgHelper.h"
#include <Windows.h>

GR_DEVICE Device = GR_NULL_HANDLE;
GR_PHYSICAL_GPU_PROPERTIES pData = {};
HMODULE hModule = 0;

void InitMantle()
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

	GR_APPLICATION_INFO AppInfo{};
	AppInfo.apiVersion = GR_API_VERSION;
	AppInfo.pAppName = "InitMantle";

	GR_UINT GPUCount;
	GR_PHYSICAL_GPU gpus[GR_MAX_PHYSICAL_GPUS];
	MessageHelper(grInitAndEnumerateGpus(&AppInfo, GR_NULL_HANDLE, &GPUCount, gpus));

	GR_SIZE pDataSize = sizeof(GR_PHYSICAL_GPU_PROPERTIES);
	MessageHelper(grGetGpuInfo(gpus[0], GR_INFO_TYPE_PHYSICAL_GPU_PROPERTIES, &pDataSize, &pData));

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
	MessageHelper(grCreateDevice(gpus[0], &DeviceInfo, &Device));
}

int main()
{
	InitMantle();

	if (Result == GR_SUCCESS)
	{
		std::cout << "VendorID: 0x" << pData.vendorId <<
			std::endl << "DeviceID: 0x" << pData.deviceId <<
			std::endl << "GPUName: " << pData.gpuName << std::endl;

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
