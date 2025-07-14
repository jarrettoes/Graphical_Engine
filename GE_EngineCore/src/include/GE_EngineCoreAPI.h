#pragma once

#ifdef GE_ENGINECORE_EXPORTS
	#define GE_ENGINECORE_API __declspec(dllexport)
#else
	#define GE_ENGINECORE_API __declspec(dllimport)
#endif // GE_ENGINECORE_EXPORT
