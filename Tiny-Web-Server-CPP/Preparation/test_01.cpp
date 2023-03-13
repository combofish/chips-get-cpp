#include <iostream>

int main() {
  std::cout << "test" << std::endl;

#ifdef DEBUG
  std::cout << "Debug Macro" << std::endl;

#endif

  return 0;
}
