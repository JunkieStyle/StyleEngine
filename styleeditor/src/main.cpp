#include <iostream>
#include <style/engine.hpp>

int main() {
  std::cout << "Hello World" << std::endl;
  std::cout << style::Add(1, 3) << " " << style::Sub(10, 5) << std::endl;
  return 0;
}
