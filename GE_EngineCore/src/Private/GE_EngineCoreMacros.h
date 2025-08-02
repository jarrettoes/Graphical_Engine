#pragma once

#include "Private/Logger.h"

#define GE_INIT_LOG() GE_EngineCore::Logger::initalize_logs();
#define GE_INFO_LOG(x, ...) GE_EngineCore::Logger::info_log(x, __VA_ARGS__);
#define GE_WARN_LOG(x, ...) GE_EngineCore::Logger::warning_log(x, __VA_ARGS__);
#define GE_ERROR_LOG(x, ...) GE_EngineCore::Logger::error_log(x, __VA_ARGS__);
#define GE_DEBUG_LOG(x, ...) GE_EngineCore::Logger::debug_log(x, __VA_ARGS__);