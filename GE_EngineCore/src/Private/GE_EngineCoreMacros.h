#pragma once

#include "Private/Logger.h"

#define GE_INFO_LOG(x, ...) GE_EngineCore::Logger::info_log(x, __VA_ARGS__)