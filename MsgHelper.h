#ifndef MSGHELPER_H_
#define MSGHELPER_H_ 1

#pragma once

#include "mantle.h"
#include <iostream>

GR_RESULT Result;

void ErrorCheck(GR_RESULT Check)
{
	switch (Check)
	{
	case GR_SUCCESS:
		std::cout << "GR_SUCCESS" << std::endl;
		break;
	case GR_UNSUPPORTED:
		std::cout << "GR_UNSUPPORTED" << std::endl;
		break;
	case GR_NOT_READY:
		std::cout << "GR_NOT_READY" << std::endl;
		break;
	case GR_TIMEOUT:
		std::cout << "GR_TIMEOUT" << std::endl;
		break;
	case GR_EVENT_SET:
		std::cout << "GR_EVENT_SET" << std::endl;
		break;
	case GR_EVENT_RESET:
		std::cout << "GR_EVENT_RESET" << std::endl;
		break;
	case GR_ERROR_UNKNOWN:
		std::cout << "GR_ERROR_UNKNOWN" << std::endl;
		break;
	case GR_ERROR_UNAVAILABLE:
		std::cout << "GR_ERROR_UNAVAILABLE" << std::endl;
		break;
	case GR_ERROR_INITIALIZATION_FAILED:
		std::cout << "GR_ERROR_INITIALIZATION_FAILED" << std::endl;
		break;
	case GR_ERROR_OUT_OF_MEMORY:
		std::cout << "GR_ERROR_OUT_OF_MEMORY" << std::endl;
		break;
	case GR_ERROR_OUT_OF_GPU_MEMORY:
		std::cout << "GR_ERROR_OUT_OF_GPU_MEMORY" << std::endl;
		break;
	case GR_ERROR_DEVICE_ALREADY_CREATED:
		std::cout << "GR_ERROR_DEVICE_ALREADY_CREATED" << std::endl;
		break;
	case GR_ERROR_DEVICE_LOST:
		std::cout << "GR_ERROR_DEVICE_LOST" << std::endl;
		break;
	case GR_ERROR_INVALID_POINTER:
		std::cout << "GR_ERROR_INVALID_POINTER" << std::endl;
		break;
	case GR_ERROR_INVALID_VALUE:
		std::cout << "GR_ERROR_INVALID_VALUE" << std::endl;
		break;
	case GR_ERROR_INVALID_HANDLE:
		std::cout << "GR_ERROR_INVALID_HANDLE" << std::endl;
		break;
	case GR_ERROR_INVALID_ORDINAL:
		std::cout << "GR_ERROR_INVALID_ORDINAL" << std::endl;
		break;
	case GR_ERROR_INVALID_MEMORY_SIZE:
		std::cout << "GR_ERROR_INVALID_MEMORY_SIZE" << std::endl;
		break;
	case GR_ERROR_INVALID_EXTENSION:
		std::cout << "GR_ERROR_INVALID_EXTENSION" << std::endl;
		break;
	case GR_ERROR_INVALID_FLAGS:
		std::cout << "GR_ERROR_INVALID_FLAGS" << std::endl;
		break;
	case GR_ERROR_INVALID_ALIGNMENT:
		std::cout << "GR_ERROR_INVALID_ALIGNMENT" << std::endl;
		break;
	case GR_ERROR_INVALID_FORMAT:
		std::cout << "GR_ERROR_INVALID_FORMAT" << std::endl;
		break;
	case GR_ERROR_INVALID_IMAGE:
		std::cout << "GR_ERROR_INVALID_IMAGE" << std::endl;
		break;
	case GR_ERROR_INVALID_DESCRIPTOR_SET_DATA:
		std::cout << "GR_ERROR_INVALID_DESCRIPTOR_SET_DATA" << std::endl;
		break;
	case GR_ERROR_INVALID_QUEUE_TYPE:
		std::cout << "GR_ERROR_INVALID_QUEUE_TYPE" << std::endl;
		break;
	case GR_ERROR_INVALID_OBJECT_TYPE:
		std::cout << "GR_ERROR_INVALID_OBJECT_TYPE" << std::endl;
		break;
	case GR_ERROR_UNSUPPORTED_SHADER_IL_VERSION:
		std::cout << "GR_ERROR_UNSUPPORTED_SHADER_IL_VERSION" << std::endl;
		break;
	case GR_ERROR_BAD_SHADER_CODE:
		std::cout << "GR_ERROR_BAD_SHADER_CODE" << std::endl;
		break;
	case GR_ERROR_BAD_PIPELINE_DATA:
		std::cout << "GR_ERROR_BAD_PIPELINE_DATA" << std::endl;
		break;
	case GR_ERROR_TOO_MANY_MEMORY_REFERENCES:
		std::cout << "GR_ERROR_TOO_MANY_MEMORY_REFERENCES" << std::endl;
		break;
	case GR_ERROR_NOT_MAPPABLE:
		std::cout << "GR_ERROR_NOT_MAPPABLE" << std::endl;
		break;
	case GR_ERROR_MEMORY_MAP_FAILED:
		std::cout << "GR_ERROR_MEMORY_MAP_FAILED" << std::endl;
		break;
	case GR_ERROR_MEMORY_UNMAP_FAILED:
		std::cout << "GR_ERROR_MEMORY_UNMAP_FAILED" << std::endl;
		break;
	case GR_ERROR_INCOMPATIBLE_DEVICE:
		std::cout << "GR_ERROR_INCOMPATIBLE_DEVICE" << std::endl;
		break;
	case GR_ERROR_INCOMPATIBLE_DRIVER:
		std::cout << "GR_ERROR_INCOMPATIBLE_DRIVER" << std::endl;
		break;
	case GR_ERROR_INCOMPLETE_COMMAND_BUFFER:
		std::cout << "GR_ERROR_INCOMPLETE_COMMAND_BUFFER" << std::endl;
		break;
	case GR_ERROR_BUILDING_COMMAND_BUFFER:
		std::cout << "GR_ERROR_BUILDING_COMMAND_BUFFER" << std::endl;
		break;
	case GR_ERROR_MEMORY_NOT_BOUND:
		std::cout << "GR_ERROR_MEMORY_NOT_BOUND" << std::endl;
		break;
	case GR_ERROR_INCOMPATIBLE_QUEUE:
		std::cout << "GR_ERROR_INCOMPATIBLE_QUEUE" << std::endl;
		break;
	case GR_ERROR_NOT_SHAREABLE:
		std::cout << "GR_ERROR_NOT_SHAREABLE" << std::endl;
		break;
	case GR_WSI_WIN_PRESENT_OCCLUDED:
		std::cout << "GR_WSI_WIN_PRESENT_OCCLUDED" << std::endl;
		break;
	case GR_WSI_WIN_ERROR_FULLSCREEN_UNAVAILABLE:
		std::cout << "GR_WSI_WIN_ERROR_FULLSCREEN_UNAVAILABLE" << std::endl;
		break;
	case GR_WSI_WIN_ERROR_DISPLAY_REMOVED:
		std::cout << "GR_WSI_WIN_ERROR_DISPLAY_REMOVED" << std::endl;
		break;
	case GR_WSI_WIN_ERROR_INCOMPATIBLE_DISPLAY_MODE:
		std::cout << "GR_WSI_WIN_ERROR_INCOMPATIBLE_DISPLAY_MODE" << std::endl;
		break;
	case GR_WSI_WIN_ERROR_MULTI_DEVICE_PRESENT_FAILED:
		std::cout << "GR_WSI_WIN_ERROR_MULTI_DEVICE_PRESENT_FAILED" << std::endl;
		break;
	case GR_WSI_WIN_ERROR_BLT_PRESENT_UNAVAILABLE:
		std::cout << "GR_WSI_WIN_ERROR_BLT_PRESENT_UNAVAILABLE" << std::endl;
		break;
	default:
		break;
	}

	Result = Check;
}

#endif
