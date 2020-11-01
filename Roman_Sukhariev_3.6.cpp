#include <cstdint>
#include <iostream>

int main() {
  int32_t kSize{0};
  std::cerr << "Enter a number of symbols you want to use" << '\n';
  std::cin >> kSize;
  if (!(std::cin) || kSize < 1) {
    std::cerr << "Wrong number. Try again" << '\n';
    return 0;
  }
  ++kSize;
  char array[kSize]{};
  std::cerr << "Enter a string" << '\n';
  std::cin >> array;
  for (int index = 0; index < kSize; ++index) {
    if (array[index] >= 65 && array[index] <= 90) {
      array[index] += 32;
    }
  }
  std::cerr << array << '\n';
  return 0;
}