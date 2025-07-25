#pragma once

#ifdef GE_GRAPHICS_EXPORTS
	#define GE_GRAPHICS_API __declspec(dllexport)
#else
	#define GE_GRAPHICS_API __declspec(dllimport)
#endif // GE_GRAPHICS_EXPORT