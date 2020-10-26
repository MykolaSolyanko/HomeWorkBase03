#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

uint32_t value_best_devider(uint32_t value);

int main() {
  uint32_t value{};
  std::cout << "Input unsigned integer value:" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  auto devider = value_best_devider(value);

  if (devider == 0) {
    std::cout << "ERROR: 0 has not devider!" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "The best devider of value " << value << " is " << devider
            << std::endl;

  return EXIT_SUCCESS;
}

uint32_t value_best_devider(uint32_t value) {
  if (value == 0) {
    return 0;
  }

  auto devider{value};

  while (value % --devider) {
  }

  return devider;
}