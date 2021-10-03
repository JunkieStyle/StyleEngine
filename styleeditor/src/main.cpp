#include <iostream>

#include "style/engine.hpp"

int main() {
  std::cout << "Hello World" << std::endl;
  style::GetInfo();
  style::Initialize();
  style::Shutdown();
#ifdef STYLE_PLATFORM_WINDOWS
  system("pause");
#endif
  return 0;
}
