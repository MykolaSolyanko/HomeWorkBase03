#include <iostream>

int main() {
  std::cout << "Please enter number stars (positive odd integer)\n";

  uint16_t size_tree{};
  std::cin >> size_tree;

  if (!std::cin || size_tree % 2 == 0 || size_tree < 0) {
    std::cout << " Incorrect input\n";
    return -1;
  }
  const uint16_t half_size = static_cast<int>(size_tree / 2) + 1;

  for (size_t i{}; i < half_size; ++i) {
    for (size_t n{i}; n < half_size; ++n) {
      std::cout << " ";
    }
    for (size_t k{size_tree}; k >= (size_tree - 2 * i); --k) {
      std::cout << "*";
    }
    std::cout << '\n';
  }

  return 0;
}
