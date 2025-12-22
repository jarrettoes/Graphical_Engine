#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <format>
#include <sstream>
#include <chrono>
#include <ctime>
#include <source_location>

enum class logger_priority
{
	INFO, WARNING, ERROR, SUCCESS
};

namespace core
{
	class logger_class
	{	
	public:
		
		logger_class() = default;
		logger_class(logger_class&) = default;
		~logger_class() = default;
		
		logger_class get_logger_instance()
		{
			static logger_class logger;
			return logger;
		}

		//use a varadic template function for logging so we can have as many arguments within the logger as we want
		template<typename ...Args>
		void logger_func(logger_priority priority_type, const std::string& str,  Args&&... arg, const std::source_location& location = std::source_location::current());

	private:

		//a timestamp for the logging system
		std::string logger_timestamp();
	};
	
	template<typename ...Args>
	inline void logger_class::logger_func(logger_priority priority_type, const std::string& str, Args&& ...arg, const std::source_location& location)
	{
		//logger essentails has the logger priority type, and the time stamp
		std::string logger_essentails;
		//for detailing where the logger is coming from
		std::string logger_source_location;
		//for the message
		std::string logger_message;
		
		switch (priority_type)
		{
			case logger_priority::INFO:	logger_essentails = logger_timestamp() + "[INFO]" + " ";
			break;
			case logger_priority::WARNING: logger_essentails = logger_timestamp() + "[WARNING]" + " ";
			break;
			case logger_priority::ERROR: logger_essentails = logger_timestamp() + "[ERROR]" + " ";
			break;
			case logger_priority::SUCCESS: logger_essentails = logger_timestamp() + "[SUCCESS]" + " ";
			break;
			default: logger_essentails = logger_timestamp() + "[INFO]" + " ";
			break;
		}
		
		logger_message = std::vformat(str, std::make_format_args(arg...));

		logger_source_location = std::format("[FILE: {} | FUNCTION: {} | LINE: {}:{}]", location.file_name(), location.function_name(), location.line(), location.column());

		std::string _log = std::format("{}	{}	{}", logger_essentails, logger_message, logger_source_location);

		std::clog << _log << std::endl;
	}
}

#endif