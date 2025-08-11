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

using namespace GE_CORE;


#define GE_INFO_LOG(x, ...) Logger::logger(loggerPriorites::Info, __FILE__ , __LINE__, __FUNCTION__, x, ##__VA_ARGS__);
#define GE_WARNING_LOG(x, ...) Logger::logger(loggerPriorites::Info, __FILE__ , __LINE__, __FUNCTION__, x, ##__VA_ARGS__);
#define GE_ERROR_LOG(x, ...) Logger::logger(loggerPriorites::Info, __FILE__ , __LINE__, __FUNCTION__, x, ##__VA_ARGS__);


