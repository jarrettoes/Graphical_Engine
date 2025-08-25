
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: Profiler.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: the profiler will profile a functions execution to see if its optimal or not.
*				simply for debuging purposes to increase effiency if need be!
*
*********************************************************/

#pragma once

#ifndef PROFILER_H
#define PROFILER_H

#define BACK_GREEN		"\033[42m"
#define BACK_YELLOW		"\033[43m"
#define BACK_RED		"\033[41m"
#define BLACK			"\033[30m"
#define RESET			"\033[0m"

#include "GE_CoreAPI.h"
#include <iostream>
#include <source_location>
#include <chrono>

namespace GE_CORE {
	
	class GE_CORE_API Profiler {
		public:
//#############################################################################################################################
// public:
//#############################################################################################################################

			Profiler() = default;
			Profiler(const Profiler&) = delete;
			void operator = (const Profiler&) = delete;

			Profiler(const Profiler&&) = delete;
			void operator = (const Profiler&&) = delete;
			virtual ~Profiler();

			template<typename FUNC, typename... Arg>
			static void profiler_logger(FUNC&&, Arg&& ... arg);

		private:
//#############################################################################################################################
// private:
//#############################################################################################################################

			static const long long elapsed_time_str(); 

	};
	
	
	template<typename FUNC, typename ...Arg>
	inline void Profiler::profiler_logger(FUNC&&, Arg&& ...arg)
	{
		std::invoke
		return std::chrono::seconds();
	}

}

#endif

