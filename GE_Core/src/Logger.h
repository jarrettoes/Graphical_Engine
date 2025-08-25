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
* FILE PURPOSE: for logging functionality for the game enigne!
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
#include <cstdlib>
#include <format>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <source_location>
#include <unordered_map>
#include <vector> 
#include <string>

namespace GE_CORE {

	enum class GE_CORE_API loggerPriorites {
		Info, Warning, Error, Debug, profiler
	};

	class GE_CORE_API Logger {
		
		public:
//#############################################################################################################################
// public:
//#############################################################################################################################s
		
		//some constructors and rule of 5 functions
		Logger() = default;
		Logger(const Logger&) = delete;
		void operator = (const Logger&) = delete;

		Logger(const Logger&&) = delete;
		void operator = (const Logger&&) = delete;
		virtual ~ Logger();

        static const std::string get_timestamp() {return timestamp_str(); }
    
		//the main logging function
		template<typename ... Arg>
		static void logger(const std::source_location& file_loc, loggerPriorites priorites,
            const std::string& str, Arg && ...arg);

       
		
		private:
//#############################################################################################################################
// private:
//#############################################################################################################################
        
        static const std::string timestamp_str(); 

	};

	template<typename ...Arg>
	inline void Logger::logger(const std::source_location& file_loc, loggerPriorites priorites,
        const std::string& str, Arg && ...arg)
	{
      
        std::ostringstream priority_tag;

        std::string_view func_name = file_loc.function_name();
        std::string formated_file_loc = std::format("[FILE:{}: FUNCTION:{} LINE:{}]", std::filesystem::path(file_loc.file_name()).filename().string(),
           file_loc.function_name(), file_loc.line());

        //issue with formating for info log but it is what it is for now will revisit
        switch (priorites)
        {
        case loggerPriorites::Info:
            priority_tag << WHITE << timestamp_str() << "\t" << "[INFO]" << "\t";
            break;

        case loggerPriorites::Warning:
            priority_tag << YELLOW << timestamp_str() << "\t" << "[WARN]" << "\t";
            break;

        case loggerPriorites::Error:
            priority_tag << RED << timestamp_str() << "\t" << "[ERROR]" << "\t";
            break;

        case loggerPriorites::Debug:
            priority_tag << MAGENTA << timestamp_str() << "\t" << "[DEBUG]" << "\t";
            break;
    
        default:
            priority_tag << WHITE << timestamp_str() << "\t" << "[INFO]" << "\t";
            break;
        }

        priority_tag << std::vformat(str, std::make_format_args(std::forward<Arg>(arg)...))
                     << "\t\t" << formated_file_loc << std::endl;



        std::clog << priority_tag.str();
	}


}

#endif