
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

#define BACK_GREEN		"\e[42m"
#define BACK_YELLOW		"\e[43m"
#define BACK_RED		"\e[41m"

#include <iostream>
#include <source_location>
#include <chrono>

namespace GE_CORE
{
	class Profiler
	{
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

			static void profiler_logger(const std::source_location& func_loc);

		private:
//#############################################################################################################################
// private:
//#############################################################################################################################

			static const std::chrono::microseconds elapsed_time_str(); 

	};
}

#endif

