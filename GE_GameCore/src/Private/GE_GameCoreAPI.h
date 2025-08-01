#pragma once

#ifdef GE_GAMECORE_EXPORTS
	#define GE_GAMECORE_API __declspec(dllexport)
#else
	#define GE_GAMECORE_API __declspec(dllimport)
#endif // GE_GAMECORE_EXPORTS
