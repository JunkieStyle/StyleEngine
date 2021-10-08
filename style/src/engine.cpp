#include "engine.hpp"

#include "SDL2/SDL.h"
#include "log.hpp"

namespace style {

void Engine::Run() {
  if (Initialize()) {
    while (is_running_) {
      window_.PumpEvents();
    }
    Shutdown();
  }
}

// private
Engine& Engine::GetInstance() {
  if (!instance_) {
    instance_ = new Engine();
  }
  return *instance_;
}

bool Engine::Initialize() {
  bool ret = false;
  log_manager_.Initialize();
  this->GetInfo();

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    STYLE_ERROR("Error: {}", SDL_GetError());
  } else {
    SDL_version version;
    SDL_GetVersion(&version);
    STYLE_INFO("SDL : {}.{}.{}", (int32_t)version.major, (int32_t)version.minor,
               (int32_t)version.patch);

    if (window_.Create()) {
      ret = true;
      is_running_ = true;
    }
  }

  if (!ret) {
    STYLE_ERROR("Engine initialization failed. Shutting down ... : {}");
    window_.Shutdown();
  }

  return ret;
}

void Engine::Shutdown() {
  is_running_ = false;

  // managers
  log_manager_.Shutdown();

  window_.Shutdown();
  SDL_Quit();
}

void Engine::GetInfo() {
  STYLE_TRACE("StyleEngine v{}.{}", 0, 1);
#ifdef STYLE_CONFIG_RELEASE
  STYLE_DEBUG("Configuration: release");
#endif
#ifdef STYLE_CONFIG_DEBUG
  STYLE_DEBUG("Configuration: debug");
#endif
#ifdef STYLE_PLATFORM_WINDOWS
  STYLE_WARN("platform: windows");
#endif
#ifdef STYLE_CONFIG_LINUX
  STYLE_WARN("platform: linux");
#endif
#ifdef STYLE_CONFIG_MACOS
  STYLE_WARN("platform: macos");
#endif
}

// singleton
Engine* Engine::instance_ = nullptr;
Engine::Engine() : is_running_(false) {}

}  // namespace style
