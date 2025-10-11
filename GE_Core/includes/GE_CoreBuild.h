#pragma once

#ifndef GE_COREBUILD_H
#define GE_COREBUILD_H

#include "logger.h"

GE_CORE::logger logg_ref = GE_CORE::logger::get_logger_instance();

#define __ENGINE_INFO_LOG()


#endif