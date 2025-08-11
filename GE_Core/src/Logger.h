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
#pragma warning(disable : 4996) // to take care of localtime_s due to depcrication

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
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

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
		static void logger(loggerPriorites priorites, const char* FILE_name, int line,
			const char* function_name, const std::string& str, Arg && ...arg);
		
		private:
//#############################################################################################################################
// private:
//#############################################################################################################################
	
	};
	
	template<typename ...Arg>
	inline void Logger::logger(loggerPriorites priorites, const char* FILE_name, int line,
												const char* function_name, const std::string& str, Arg && ...arg)
	{
        // for the time portion.
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm tm_buf;
#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&tm_buf, &now_c); //localtime_s is depricated 
#else
        localtime_r(&now_c, &tm_buf); //believe localtime_r is aswell!
#endif
        std::ostringstream oss;
        oss << std::put_time(&tm_buf, "[%F_%T]: ");
        std::string formatted_time = oss.str();

        std::ostringstream priority_tag;

        switch (priorites)
        {
        case loggerPriorites::Info:
            priority_tag << WHITE << "[INFO]" << formatted_time;
            break;

        case loggerPriorites::Warning:
            priority_tag << YELLOW << "[WARNING]" << formatted_time;
            break;

        case loggerPriorites::Error:
            priority_tag << RED << "[ERROR]" << formatted_time;
            break;

        case loggerPriorites::Debug:
            priority_tag << MAGENTA << "[DEBUG]" << formatted_time;
            break;

        default:
            priority_tag << WHITE << "[INFO]" << formatted_time;
            break;
        }

        priority_tag << FILE_name << " on " << line << " at " << function_name << std::vformat(str, std::make_format_args(std::forward<Arg>(arg)...)) << std::endl;

        return priority_tag.str();
	}
}

#endif