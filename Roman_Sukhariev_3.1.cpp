#include <cstdint>
#include <cstdio>
#include <iostream>

int main() {
  size_t kSize{};
  std::cerr << "Enter a number of symbols you want to use" << '\n';
  std::cin >> kSize;
  if (!(std::cin) || kSize < 1) {
    std::cerr << "Wrong number. Try again" << '\n';
    return 0;
  }
  ++kSize;
  char normal_array[kSize]{};
  std::cerr << "Please, enter your string" << '\n';
  std::cin >> normal_array;
  if (!(std::cin)) {
    std::cout << "You entered a wrong symbol. Try again" << '\n';
    return 0;
  }
  char reverse_array[kSize]{};
  for (size_t index = 0; index < kSize; ++index) {
    reverse_array[index] = normal_array[kSize - 1 - index];
    if (reverse_array[index] != '\0') {
      std::cerr << reverse_array[index];
    }
  }
  std::cerr << '\n';
  return 0;
}