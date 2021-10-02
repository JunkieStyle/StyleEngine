#include <engine.hpp>
#include <iostream>

namespace style {

int Sub(int a, int b) { return a - b; }
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
}  // namespace style
