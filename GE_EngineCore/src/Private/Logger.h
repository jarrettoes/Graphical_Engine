
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: 
*
* FILE AUTOHOR:
*
* FILE PURPOSE: 
*
*********************************************************/

#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include "Private/GE_EngineCoreAPI.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <unordered_map>

namespace GE_EngineCore
{

	//types of logging that we'll use for info, warning, error, and debug within the engine
	enum class GE_ENGINECORE_API loggerPriority : uint8_t
	{ Info, Warning, Error, Debug };

	class GE_ENGINECORE_API Logger
	{
		public:

			Logger() = default;
			~Logger();

			static void initalize_logs();
			static void clear_logs();

			template<typename ... args>
			static void log(loggerPriority priority, std::string str, args&&... arg);
			// the template<typename .. args> will be used for multiple argument if need when logging! will keep for potenital future implmentations
			template<typename ... args>
			static void info_log(std::string str, args&&... arg);
			
			template<typename ... args>
			static void warning_log(std::string str, args&&... arg);

			template<typename ... args>
			static void error_log(std::string str, args&&... arg);

			template<typename ... args>
			static void debug_log(std::string str, args&&... arg);


			/*for popup messages within the engine!*/
			static void warning_popup(HRESULT hres, const std::string& str);
			static void error_popup(HRESULT hres, const std::string& str);

			bool check_intializeLogs() {return b_initltize_logs;}

			Logger& get_logInstance()
			{
				static Logger loggerInstance;
				return loggerInstance; 
			}

		private:

			static std::wstring w_char_convert(std::string str)
			{
				std::wstring string(str.begin() , str.end());
				return string;
			}

			static std::string handle_timestamp();

			static bool b_retain_logs; 
			static bool b_initltize_logs;
	};

	template<typename ...args>
	inline void Logger::log(loggerPriority priority, std::string str)
	{
		if (!b_initltize_logs)
		{
			std::cout << "[CRITICAL]" << "[" << handle_timestamp() << "]: " << "GE_LOGS failed to intialize" << std::endl; 
			return;
		}

		HANDLE color_console = GetStdHandle(STD_OUTPUT_HANDLE);

		std::string formated_argument = std::make_wformat_args(arg);
		//switch case for each priority; 
		switch (priority)
		{
			case loggerPriority::Info:
			{
				std::cout << "[INFO]" << "[" << handle_timestamp() << "]: " << formated_argument << std::endl;
				
			}break; 
			case loggerPriority::Warning:
			{
				std::cout << "[WARNING]" << "[" << handle_timestamp() << "]: " << formated_argument << std::endl;
			}break;
			case loggerPriority::Error:
			{
				std::cout << "[ERROR]" << "[" << handle_timestamp() << "]: " << formated_argument << std::endl;
			}break;
			case loggerPriority::Debug:
			{
				std::cout << "[DEBUG]" << "[" << handle_timestamp() << "]: " << formated_argument << std::endl;
			}break;			
		}
	}

	template<typename ...args>
	inline void Logger::info_log(std::string str, args && ...arg)
	{

	}

	template<typename ...args>
	inline void Logger::warning_log(std::string str, args && ...arg)
	{

	}

	template<typename ...args>
	inline void Logger::error_log(std::string str, args && ...arg)
	{

	}

	template<typename ...args>
	inline void Logger::debug_log(std::string str, args && ...arg)
	{

	}

}


#endif