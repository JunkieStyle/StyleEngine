#include <iostream>

#include "style/engine.hpp"

int main() {
  style::Engine& engine = style::Engine::GetInstance();
  engine.Run();
  std::cout << "Press ENTER to continue ...";
  std::cin.ignore();
  return 0;
}
