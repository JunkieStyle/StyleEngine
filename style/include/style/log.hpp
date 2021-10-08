#pragma once
#include "spdlog/spdlog.h"

#define STYLE_DEFAULT_LOGGER_NAME "stylelogger"
#ifndef STYLE_CONFIG_RELEASE
#define STYLE_TRACE(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {      \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__); \
  }
#define STYLE_DEBUG(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {      \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->debug(__VA_ARGS__); \
  }
#define STYLE_INFO(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {     \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->info(__VA_ARGS__); \
  }
#define STYLE_WARN(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {     \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__); \
  }
#define STYLE_ERROR(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {      \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->error(__VA_ARGS__); \
  }
#define STYLE_CRITICAL(...)                                        \
  if (spdlog::get(STYLE_DEFAULT_LOGGER_NAME) != nullptr) {         \
    spdlog::get(STYLE_DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__); \
  }
#else
// disable logging for release builds
#define STYLE_TRACE(...) (void)0
#define STYLE_DEBUG(...) (void)0
#define STYLE_INFO(...) (void)0
#define STYLE_WARN(...) (void)0
#define STYLE_ERROR(...) (void)0
#define STYLE_CRITICAL(...) (void)0
#endif
