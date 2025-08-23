/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: CoreBuild.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: macros function within the GE_Core class
*
*********************************************************/

#pragma once

#include "Logger.h"
#include <cstdlib>
#include <Windows.h>


#define GE_INFO_LOG(x, ...)		GE_CORE::Logger::logger(std::source_location::current(),GE_CORE::loggerPriorites::Info,x, __VA_ARGS__)
#define GE_WARNING_LOG(x, ...)	GE_CORE::Logger::logger(std::source_location::current(),GE_CORE::loggerPriorites::Warning,x, __VA_ARGS__)
#define GE_ERROR_LOG(x, ...)	GE_CORE::Logger::logger(std::source_location::current(),GE_CORE::loggerPriorites::Error,x, __VA_ARGS__)


#ifndef _DEBUG
#define GE_DEBUG 1
#else
#define GE_DEBUG 0
#endif


//the GE_DEBUG mode which communicateds with _DEBUG!
#ifdef GE_DEBUG
#define GE_DEBUG_LOG(x, ...) GE_CORE::Logger::logger(std::source_location::current(),GE_CORE::loggerPriorites::Debug,x, __VA_ARGS__)
#else
#define GE_DEBUG_LOG(x, ...) GE_CORE::Logger::logger(std::source_location::current(),GE_CORE::loggerPriorites::Debug,x, __VA_ARGS__)
#endif

#define GE_ASSERT(condition, msg) \
do { \
		if(!(condition)) \
		{ \
			MessageBoxA(nullptr, msg, "WOAH THERE COWBOY!", MB_OK | MB_ICONERROR);\
			\
			std::terminate();\
		} \
} while(0)
