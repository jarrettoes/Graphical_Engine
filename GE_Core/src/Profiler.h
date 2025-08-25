
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
#include <format>
#include <unordered_map>

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
			static auto profiler_logger(const std::source_location& soruce_loc, FUNC&&, Arg&& ... arg);

		private:
//#############################################################################################################################
// private:
//#############################################################################################################################


	};
	
	
	template<typename FUNC, typename ...Arg>
	inline auto Profiler::profiler_logger(const std::source_location& soruce_loc, FUNC&& func, Arg&& ...arg)
	{
		//this gets the duration of a function execution to display if the funciton is efficent enough
		auto start_time = std::chrono::high_resolution_clock::now();

		//invoke for the function that we want to see executed to messaure if its optimal or not
		auto result = std::invoke(std::forward<FUNC>(func), 
													    std::make_format_args(std::forward<Arg>(arg)...)); 
		auto end_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> m_duratrion = (end_time - start_time);


		//depending on the duration it should 
		if (duration <= 0.1)
		{
			std::cout << BACK_GREEN << BLACK << GE_CORE::Logger::get_timestamp() << "[PROFILER]" << "\t" 
					  << __FUNCTION__ << "ran for: " << m_duration << "ms" << std::endl; 
		}
		else if (duration  1.0 = < || > 0.1)
		{
			std::cout << BACK_YELLOW << BLACK << GE_CORE::Logger::get_timestamp() << "[PROFILER]" << "\t"
				<< __FUNCTION__ << "ran for: " << m_duration<< "ms" << std::endl;
		}	
		else
		{
			std::cout << BACK_RED << BLACK << GE_CORE::Logger::get_timestamp() << "[PROFILER]" << "\t"
				<< __FUNCTION__ << "ran for: " << m_duration << "ms" << std::endl;
		}

		return std::make_pair(result, m_duration);
	}

}

#endif

