#pragma once

#ifndef CORE_MACROS_H
#define CORE_MACROS_H

#include "logger.h"

core::logger_class logger;

#define ENGINE_INFO_LOG(x, ...) logger.get_logger_instance().logger_func(logger_priority::INFO, x, ##__VA_ARGS__##, std::source_location::current());
#define ENGINE_WARN_LOG(x, ...) logger.get_logger_instance().logger_func(logger_priority::WARNING, x, ##__VA_ARGS__##, std::source_location::current());
#define ENGINE_ERROR_LOG(x, ...) logger.get_logger_instance().logger_func(logger_priority::ERROR, x, ##__VA_ARGS__##, std::source_location::current());
#define ENGINE_SUCCESS_LOG(x, ...) logger.get_logger_instance().logger_func(logger_priority::SUCCESS, x, ##__VA_ARGS__##, std::source_location::current());

#endif