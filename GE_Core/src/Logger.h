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
#include "CoreBuild.h"
#include <iostream>
#include <format>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <print>
#include <Windows.h>
#include <filesystem>
#include <source_location>

namespace GE_CORE {

	enum class GE_CORE_API loggerPriorites {
		Info, Warning, Error, Debug
	};

    enum class GE_CORE_API assertAction {
        Abort, Break, Ignore
    };

	class GE_CORE_API Logger {
		
		public:
//#############################################################################################################################
// public:
//#############################################################################################################################
		
		//some constructors and rule of 5 functions
		Logger() = default;
		Logger(const Logger&) = delete;
		void operator = (const Logger&) = delete;

		Logger(const Logger&&) = delete;
		void operator = (const Logger&&) = delete;
		virtual ~ Logger();

		//the main logging function
		template<typename ... Arg>
		static void logger(loggerPriorites priorites, const std::string& str,  Arg && ...arg,
                            const std::source_location& file_loc = std::source_location::current());


		
		private:
//#############################################################################################################################
// private:
//#############################################################################################################################
        
	};

	template<typename ...Arg>
	inline void Logger::logger(loggerPriorites priorites, const std::string& str, Arg && ...arg, 
                                const std::source_location& file_loc)
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
        oss << std::put_time(&tm_buf, "[%m-%d-%y %H:%M:%S]:\t");
        std::string formatted_time = oss.str();

        std::ostringstream priority_tag;


        //issue with formating for info log but it is what it is for now will revisit
        switch (priorites)
        {
        case loggerPriorites::Info:
            priority_tag << WHITE << std::format("{:<9}", "[INFO]") << formatted_time;
            break;

        case loggerPriorites::Warning:
            priority_tag << YELLOW << std::format("{:<9}", "[WARNING]") << formatted_time;
            break;

        case loggerPriorites::Error:
            priority_tag << RED << std::format("{:<9}", "[ERROR]") << formatted_time;
            break;

        case loggerPriorites::Debug:
            priority_tag << MAGENTA << std::format("{:<9}", "[DEBUG]") << formatted_time;
            break;

        default:
            priority_tag << WHITE << std::format("{:<9}", "[INFO]") << formatted_time;
            break;
        }

        priority_tag << std::vformat(str, std::make_format_args(std::forward<Arg>(arg)...))
                     << "\t\t" << std::format("[LOCATION]: {}:{}:{}", std::filesystem::path(file_loc.file_name()).filename().string(),
                                     file_loc.function_name(), file_loc.line()) << std::endl;

        std::cout << priority_tag.str();
	}

}

#endif