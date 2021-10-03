#include "engine.hpp"

#include <iostream>

#include "SDL2/SDL.h"

namespace style {

void GetInfo() {
#ifdef STYLE_CONFIG_DEBUG
  std::cout << "Configuration: DEBUG" << std::endl;
#endif
#ifdef STYLE_CONFIG_RELEASE
  std::cout << "Configuration: RELEASE" << std::endl;
#endif
#ifdef STYLE_PLATFORM_WINDOWS
  std::cout << "platform: windows" << std::endl;
#endif
#ifdef STYLE_CONFIG_LINUX
  std::cout << "platform: linux" << std::endl;
#endif
#ifdef STYLE_CONFIG_MACOS
  std::cout << "platform: macos" << std::endl;
#endif
}

bool Initialize() {
  bool ret = true;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Error: " << SDL_GetError() << std::endl;
    ret = false;
  } else {
    SDL_version version;
    SDL_GetVersion(&version);
    std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "."
              << (int32_t)version.patch << std::endl;
  }

  return ret;
}

void Shutdown() { SDL_Quit(); }
}  // namespace style
