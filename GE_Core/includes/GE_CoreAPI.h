/********************************************************************************************
*
* Graphical Engine
*
* GE_CoreAPI.h: the header for setting up the GE_CORE API and the dynamic linked libaries dll
*
*********************************************************************************************/

#pragma once

#ifndef GE_CORE_EXPORTS
	#define GE_CORE_API __declspec(dllimport)
#else 
	#define GE_CORE_API __declspec(dllexport)
#endif