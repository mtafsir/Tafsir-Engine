#pragma once

#ifdef TE_PLATFORM_WINDOWS
	#ifdef TE_BUILD_DLL
		#define T_Engine_API __declspec(dllexport)
	#else
		#define T_Engine_API __declspec(dllimport)
	#endif

#else
	#error T_Engine on supports Window!
#endif