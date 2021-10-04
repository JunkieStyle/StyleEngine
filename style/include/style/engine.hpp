#pragma once
#include "core/window.hpp"

namespace style {

class Engine {
 public:
  static Engine& GetInstance();
  ~Engine() {}
  void Run();
  void inline Quit() { is_running_ = false; }

 private:
  Engine();
  void GetInfo();
  bool Initialize();
  void Shutdown();
  static Engine* instance_;
  core::Window window_;
  bool is_running_;
};

}  // namespace style
