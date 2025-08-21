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


#define GE_INFO_LOG(x, ...)		GE_CORE::Logger::logger(GE_CORE::loggerPriorites::Info,		x, __VA_ARGS__, std::source_location::current())
#define GE_WARNING_LOG(x, ...)	GE_CORE::Logger::logger(GE_CORE::loggerPriorites::Warning,	x, __VA_ARGS__, std::source_location::current())
#define GE_ERROR_LOG(x, ...)	GE_CORE::Logger::logger(GE_CORE::loggerPriorites::Error,	x, __VA_ARGS__, std::source_location::current())


#ifndef _DEBUG
	#define GE_DEBUG 1
#else
	#define GE_DEBUG 0
#endif


//the GE_DEBUG mode which communicateds with _DEBUG!
#ifdef GE_DEBUG
	#define GE_DEBUG_LOG(x, ...) GE_CORE::Logger::logger(GE_CORE::loggerPriorites::Debug, x, __VA_ARGS__, std::source_location::current())
#else
	#define GE_DEBUG_LOG(x, ...) GE_CORE::Logger::logger(GE_CORE::loggerPriories::Debug, x, __VA_ARGS__, std::source_location::current())
#endif

#define GE_ASSERT(expr, msg, ...)