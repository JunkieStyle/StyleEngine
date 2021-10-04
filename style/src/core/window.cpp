#include "core/window.hpp"

#include <iostream>

#include "SDL2/SDL.h"
#include "engine.hpp"

namespace style::core {

Window::Window() : window_(nullptr) {}

Window::~Window() {
  if (window_) {
    Shutdown();
  }
}

bool Window::Create() {
  bool ret = true;
  window_ =
      SDL_CreateWindow("Style Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (!window_) {
    std::cout << SDL_GetError() << std::endl;
    ret = false;
  }
  return ret;
}

void Window::Shutdown() {
  SDL_DestroyWindow(window_);
  window_ = nullptr;
}

void Window::PumpEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        Engine::GetInstance().Quit();
        break;

      default:
        break;
    }
  }
}

}  // namespace style::core
