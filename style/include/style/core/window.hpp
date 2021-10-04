#pragma once

struct SDL_Window;

namespace style::core {

class Window {
 public:
  Window();
  ~Window();
  bool Create();
  void Shutdown();
  void PumpEvents();

 private:
  SDL_Window* window_;
};

}  // namespace style::core
