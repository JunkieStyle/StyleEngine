#include "managers/logmanager.hpp"

#include <memory>
#include <vector>

#include "log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace style::managers {

void LogManager::Initialize() {
  auto console_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
  console_sink->set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %v%$");

  std::vector<spdlog::sink_ptr> sinks{console_sink};
  auto logger =
      std::make_shared<spdlog::logger>(STYLE_DEFAULT_LOGGER_NAME, sinks.begin(), sinks.end());
  logger->set_level(spdlog::level::trace);
  logger->flush_on(spdlog::level::trace);
  spdlog::register_logger(logger);
}

void LogManager::Shutdown() { spdlog::shutdown(); }

}  // namespace style::managers
