
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

#include "GE_CoreAPI.h"
#include <iostream>
#include <source_location>
#include <chrono>
#include <format>
#include <unordered_map>
#include "Logger.h"
#include <filesystem>

namespace GE_CORE {
	enum class GE_CORE_API Profile_category {
		Optimal, Mediocre, Needs_Work
	};
	
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

			template<typename FUNC, typename ...Arg>
			static auto profiler_logger(const std::source_location& file_loc, FUNC&& func, Arg&& ... arg);

		private:
//#############################################################################################################################
// private:
//#############################################################################################################################

		static Profile_category prof_cat; 

	};
	
	
	template<typename FUNC, typename ...Arg>
	inline auto Profiler::profiler_logger(const std::source_location& file_loc, FUNC&& func,  Arg&& ... arg)
	{
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm tm_buf;
#if defined(_WIN32) || defined(_WIN64)
		localtime_s(&tm_buf, &now_c); //localtime_s is depricated 
#else
		localtime_r(&now_c, &tm_buf); //believe localtime_r is aswell!
#endif
		std::ostringstream oss;
		oss << std::put_time(&tm_buf, "%m/%d/%Y %H:%M:%S: ");
		std::string formatted_time = oss.str();

		//this gets the duration of a function execution to display if the funciton is efficent enough
		auto start_time = std::chrono::high_resolution_clock::now();

		//invoke for the function that we want to see executed to messaure if its optimal or not
		auto result = std::invoke(std::forward<FUNC>(func), std::forward<Arg>(arg)...);
		auto end_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> m_duration = (end_time - start_time);

		std::ostringstream ss;

		//depending on the duration it should 
		if (m_duration.count() < 0.1)								ss << GREEN << formatted_time << "\t" << "[PROFILER]" << "\t";
		if (m_duration.count() <= 1.0 && m_duration.count() >= 0.1)	ss << YELLOW << formatted_time << "\t" << "[PROFILER]" << "\t";
		if (m_duration.count() > 1.0)								ss << RED << formatted_time << "\t" << "[PROFILER]" << "\t";

		std::string formated_file_loc = std::format("[FILE:{},  FUNCTION CALLED IN: {},  LINE:{}]", std::filesystem::path(file_loc.file_name()).filename().string(),
			file_loc.function_name(), file_loc.line());

		
		ss << file_loc.function_name() << " ran for: " << m_duration.count() << "ms" << "\t\t" << formated_file_loc << std::endl;
		std::clog << ss.str(); 

		return result;
	}

}

#endif

