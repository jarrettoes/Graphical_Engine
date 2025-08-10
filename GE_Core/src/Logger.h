/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: Logger.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: 
*
*********************************************************/

#pragma once

#ifndef LOGGER_H
#define LOGGER_H

//pre-processors for the color of the text!
#define RED			"\033[31m" 
#define WHITE		"\033[37m" 
#define MAGENTA		"\033[35m"      
#define YELLOW		"\033[33m" 

#include "GE_CoreAPI.h"
#include <iostream>
#include <format>
#include <fstream>

namespace GE_CORE {

	enum class GE_CORE_API loggerPriorites {
		Info, Warning, Error, Debug
	};

	class GE_CORE_API Logger {
		
		public:
//#############################################################################################################################
// public:
//#############################################################################################################################
		
		//some constructors and rule of 5 functions
		Logger();
		Logger(const Logger&) = delete;
		void operator = (const Logger&) = delete;

		Logger(const Logger&&) = delete;
		void operator = (const Logger&&) = delete;
		virtual ~ Logger();

		
		//the main logging function
		template<typename ... Arg>
		static void logger(loggerPriorites priorites, const std::string& str, Arg&& ... arg);
		
		private:
//#############################################################################################################################
// private:
//#############################################################################################################################
		
		static std::string logger_priority_tag(loggerPriorites priorites, const char* FILE_name, int line, 
											   const char* function_name, const std::string& str);
	
	};
	
	template<typename ...Arg>
	inline void Logger::logger(loggerPriorites priorites, const std::string& str, Arg && ...arg)
	{
		std::ostringstream oss;
		oss << logger_priority_tag(priorites, std::vformat(str, std::make_format_arg(std::forward<Arg>(arg)...)));
	}
}

#endif