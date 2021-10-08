#pragma once
#include "spdlog/spdlog.h"

#define STYLE_DEFAULT_LOGGER_NAME "stylelogger"
#ifndef STYLE_CONFIG_RELEASE
#define STYLE_TRACE(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {      \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__); \
  }
#else
#define STYLE_TRACE(...) (void)0
#endif
