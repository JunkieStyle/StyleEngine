#include <iostream>

#include "style/engine.hpp"

int main() {
  std::cout << "Hello World" << std::endl;
  style::GetInfo();
  style::Initialize();
  style::Shutdown();
  std::cout << "Please press ENTER to continue ...";
  std::cin.ignore();
  return 0;
}
