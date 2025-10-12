/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
* FILE TITLE: 
*
* FILE AUTOHOR: 
*
* FILE PURPOSE: 
*
************************************************************************************************************/

#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <GE_Core.h>
#include <iostream>
#include <cstdlib>
#include <format>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <source_location>
#include <string>

//colors for logging
#define RED			"\033[31m" 
#define WHITE		"\033[37m" 
#define MAGENTA		"\033[35m"      
#define YELLOW		"\033[33m" 
#define GREEN		"\033[32m"


namespace GE_CORE
{
	enum class GE_CORE_API logger_priorites
	{
		info, warning, error, debug
	};

	class GE_CORE_API logger
	{
		public:

		//constructors
		logger() = default;
		logger(const logger&) = delete;
		logger& operator=(const logger&) = delete;
		~logger();
		//constructors

		//the main logger function
		template<typename ... Arg> //use a varaidac template for the log_message function
		static void log_message(const std::source_location& message_loc, logger_priorites priority, const std::string_view& msg, Arg&& ... arg);


		//instance getter function
		/*logger& get_log_instance()
		{
			static logger logger_instance;
			return logger_instance;
		}*/

		private:

		//to trim up the soruce_file location function name getter from void __cdecl GE_NAMESPACE::CLASS::function(void) to simply function()
		static const std::string_view clear_function_name(std::string_view function_name)
		{
			if(auto pos = function_name.find_last_of(":"); pos != std::string_view::npos) //find the last of that : within GE_NAMESPACE::CLASS::!
				return function_name.substr(pos + 1); //after that find the next ":" and do what we need to do
			return function_name;
		}
	};
	
	template<typename ...Arg>
	inline void logger::log_message(const std::source_location& message_loc, logger_priorites priority, const std::string_view& msg, Arg&& ...arg)
	{
		//a ostringstream for the soruce_location description
		std::string message_location_str = std::format("[ FILE: {} | FUNCTION: {} | LINE: {} ]",
			std::filesystem::path(message_loc.file_name()).filename().string(), clear_function_name(message_loc.function_name()), message_loc.line());
		
		std::ostringstream std_tag;

		switch (priority)
		{
			case logger_priorites::info:
				std_tag << WHITE << "[INFO]" << "\t";
				break;

			case logger_priorites::warning:
				std_tag << YELLOW << "[WARN]" << "\t";
				break;

			case logger_priorites::error:
				std_tag << RED << "[ERROR]" << "\t";
				break;

			case logger_priorites::debug:
				std_tag << MAGENTA << "[DEBUG]" << "\t";
				break;

			default:
				std_tag << WHITE << "[INFO]" << "\t";
				break;
		}

		//to format the msg and any potential arguments!
		std_tag << std::vformat(msg, std::make_format_args(std::forward<Arg>(arg)...)) << "\t\t" << message_location_str << std::endl;
		
		std::clog << std_tag.str();
	}
}

#endif