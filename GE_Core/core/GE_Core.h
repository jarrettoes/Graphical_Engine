/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
* FILE TITLE:
*
* FILE AUTOHOR:
*
* FILE PURPOSE:
*
************************************************************************************************************/

#pragma once

//doing dynamic linked libraries (DLL) for this project! DLL should be the best fit instead of Static Libaries when it comes to compilation
#ifndef GE_CORE_EXPORTS
	#define GE_CORE_API __declspec(dllexport)
#else
	#define GE_CORE_API __declspec(dllimport)
#endif