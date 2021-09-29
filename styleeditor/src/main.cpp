#include <style/engine.h>

#include <iostream>

int main() {
  std::cout << "Hello World" << std::endl;
  std::cout << style::Add(1, 3) << " " << style::Sub(10, 5) << std::endl;
  return 0;
}
