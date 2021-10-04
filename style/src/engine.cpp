#include "engine.hpp"

#include <iostream>

#include "SDL2/SDL.h"

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

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Error: " << SDL_GetError() << std::endl;
  } else {
    SDL_version version;
    SDL_GetVersion(&version);
    std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "."
              << (int32_t)version.patch << std::endl;

    if (window_.Create()) {
      ret = true;
      is_running_ = true;
    }
  }

  if (!ret) {
    std::cout << "Engine initialization failed. Shutting down ... " << std::endl;
    window_.Shutdown();
  }

  return ret;
}

void Engine::Shutdown() {
  is_running_ = false;
  window_.Shutdown();
  SDL_Quit();
}

void Engine::GetInfo() {
#ifdef style_config_debug
  std::cout << "configuration: debug" << std::endl;
#endif
#ifdef style_config_release
  std::cout << "configuration: release" << std::endl;
#endif
#ifdef style_platform_windows
  std::cout << "platform: windows" << std::endl;
#endif
#ifdef style_config_linux
  std::cout << "platform: linux" << std::endl;
#endif
#ifdef style_config_macos
  std::cout << "platform: macos" << std::endl;
#endif
}

// singleton
Engine* Engine::instance_ = nullptr;
Engine::Engine() : is_running_(false) { GetInfo(); }

}  // namespace style
