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


#ifndef INIT_DEBUG 
	#define GE_DEBUG 1
#else 
	#define GE_DEBUG 0
#endif

#define GE_INFO_LOG(x, ...)
#define GE_WARNING_LOG(x, ...)
#define GE_ERROR_LOG(x, ...)

#define GE_DEBUG

