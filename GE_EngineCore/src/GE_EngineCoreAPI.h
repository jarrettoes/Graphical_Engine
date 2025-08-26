#pragma once

#ifndef GE_ENGINECORE_EXPORTS
	#define GE_ENGINECORE_API	__declspec(dllimport)
#else
	#define GE_ENGINECORE_API	__declspec(dllexport)
#endif