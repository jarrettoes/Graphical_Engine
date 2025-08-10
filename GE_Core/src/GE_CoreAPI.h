#pragma once


#ifndef GE_CORE_EXPORTS
	#define GE_CORE_API __declspec(dllimport)
#else 
	#define GE_CORE_API __declspec(dllexport)
#endif