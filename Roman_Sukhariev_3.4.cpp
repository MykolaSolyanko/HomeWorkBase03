#include <cstdint>
#include <iostream>

int main() {
  uint64_t kSize{0};
  std::cout << "Please, enter a number of symbols you want to use" << '\n';
  std::cin >> kSize;
  if (!(std::cin) || kSize == 0) {
    std::cout << "You entered a wrong symbol. Please, try again" << '\n';
    return 0;
  }
  ++kSize;  // increasing for '\0'
  char array[kSize]{};
  std::cout << "Please, enter your string" << '\n';
  std::cin >> array;
  for (uint64_t index = 0; index < kSize; ++index) {
    if (array[index] > 96 && array[index] < 123) {
      array[index] -= 32;
    }
  }
  for (uint64_t index = 0; index < kSize; ++index) {
    if (array[index] == 0) {
      std::cout << ' ';
    }
    std::cout << array[index];
  }
  std::cout << '\n';
  return 0;
}