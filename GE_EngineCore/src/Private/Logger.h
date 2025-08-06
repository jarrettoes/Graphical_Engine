
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
* FILE PURPOSE: To create a logging system for the engine
* 
* (WILL INCLUDE SOME FILE LOGIC FOR)
*
*********************************************************/

#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include "Private/GE_EngineCoreAPI.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <utility>

#define RED			"\033[31m" 
#define WHITE		"\033[37m" 
#define MAGENTA		"\033[35m"      
#define YELLOW		"\033[33m" 

namespace GE_EngineCore
{

	//types of logging that we'll use for info, warning, error, and debug within the engine
	enum class GE_ENGINECORE_API loggerPriority : uint8_t
	{ Info, Warning, Error, Debug };

	class GE_ENGINECORE_API Logger
	{
		public:

//******************************************************************************************************************************************
// public: should have its constructor and deconstructor. should have the main logs: INFO, WARNING, ERROR, DEBUG. in terms for popups that
// would be in the public as well but its only the window class for every critical software errors rather than programming errors that the 
// main logs will handle
//******************************************************************************************************************************************

			Logger() = default;
			Logger(const Logger&) = delete;
			void operator = (const Logger&) = delete;
		
			Logger(const Logger&&) = delete;
			void operator = (const Logger&&) = delete;
			virtual ~Logger();

			//for initalizing and clearing the current logs.
			static void initalize_logs();
			static void clear_logs();

			//individual logs
			template<typename ...Arg>
			static void info_log(std::string fmt, Arg&& ... arg);
			template<typename ...Arg>
			static void warning_log(std::string fmt, Arg&& ... arg);
			template<typename ...Arg>
			static void error_log(std::string fmt, Arg&& ... arg);
			template<typename ...Arg>
			static void debug_log(std::string fmt, Arg&& ... arg);
		

			/*for popup messages within the engine!*/
			static void warning_popup(HRESULT hres, const std::string& str);
			static void error_popup(HRESULT hres, const std::string& str);


			//get the instace for our individual logger functions
			Logger& get_logInstance()
			{
				static Logger loggerInstance;
				return loggerInstance; 
			}

		private:

//*********************************************************************************************************************************************
// private: will have the main log function to handle any sort of logging that each of the indivudal function. so really the private will have
//		    backend functions for the main functions and even more backend functions for other backend functions
//*********************************************************************************************************************************************

			//the main logging function
			template<typename ... Arg>
			static void logger(loggerPriority priority, std::string log_msg, Arg&& ... arg);

			//all these backned functions will be included within the main logger function!
			static std::string handle_priority_tag(loggerPriority priority, std::string msg);
			static std::string handle_priority_color(loggerPriority priority);
			static std::string handle_time_stamp(); 
		
			static std::wstring w_char_convert(std::string str)
			{
				std::wstring string(str.begin() , str.end());
				return string;
			}

			static bool b_retain_logs;
			static bool b_init_logs;
	};

	template<typename ...Arg>
	inline void Logger::info_log(std::string fmt, Arg && ...arg)
	{
		logger(loggerPriority::Info, fmt, arg...);
	}
	template<typename ...Arg>
	inline void Logger::warning_log(std::string fmt, Arg && ...arg)
	{
		logger(loggerPriority::Warning, fmt, arg...);
	}
	template<typename ...Arg>
	inline void Logger::error_log(std::string fmt, Arg && ...arg)
	{
		logger(loggerPriority::Error, fmt, arg...);
	}
	template<typename ...Arg>
	inline void Logger::debug_log(std::string fmt, Arg && ...arg)
	{
		logger(loggerPriority::Debug, fmt, arg...);
	}

	template<typename ...Arg>
	inline void Logger::logger(loggerPriority priority, std::string log_msg, Arg && ...arg)
	{
		//combine the helper functions!
		std::stringstream ss; 
		std::cout << handle_priority_tag(priority, log_msg);
		((ss << std::forward<Arg>(arg)), ...); // Fold expression here

		ss << std::endl;

		std::cout << ss.str();
	}
}

//*********************************************************************************************************************************************
// macors: these are the logging macros for the engine!
//*********************************************************************************************************************************************

#define GE_INFO_LOG(x, ...) GE_EngineCore::Logger::info_log(x, ##__VA_ARGS__)
#define GE_WARN_LOG(x, ...) GE_EngineCore::Logger::warning_log(x, ##__VA_ARGS__)
#define GE_ERROR_LOG(x, ...) GE_EngineCore::Logger::error_log(x, ##__VA_ARGS__)
#define GE_DEBUG_LOG(x, ...) GE_EngineCore::Logger::debug_log(x, ##__VA_ARGS__)

#endif