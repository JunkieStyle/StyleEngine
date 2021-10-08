#pragma once
#include "core/window.hpp"
#include "managers/logmanager.hpp"

namespace style {

class Engine {
 public:
  static Engine& GetInstance();
  ~Engine() {}
  void Run();
  void inline Quit() { is_running_ = false; }

 private:
  void GetInfo();
  bool Initialize();
  void Shutdown();

 private:
  core::Window window_;
  bool is_running_;
  bool is_initialized_;

  // managers
  style::managers::LogManager log_manager_;

  // singleton
  Engine();
  static Engine* instance_;
};

}  // namespace style
