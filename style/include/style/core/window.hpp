#pragma once

struct SDL_Window;
using SDL_GLContext = void*;

namespace style::core {

class Window {
 public:
  Window();
  ~Window();
  bool Create();
  void Shutdown();
  void PumpEvents();
  void BeginRender();
  void EndRender();

 private:
  SDL_Window* window_;
  SDL_GLContext gl_context_;
};

}  // namespace style::core
