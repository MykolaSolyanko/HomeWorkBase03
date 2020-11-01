#include <array>
#include <cstdint>
#include <iostream>

int main() {
  constexpr uint32_t kSize{5};
  std::array<int, kSize> ar{};
  std::cerr << "Please, fulfill the array. Use numbers 1..5. Zero is forbidden"
            << '\n';
  for (int index = 0; index < kSize; ++index) {
    std::cin >> ar[index];
    if (!(std::cin) || ar[index] < 1 || ar[index] > 5) {
      std::cerr << "You entered a wrong symbol. Try again" << '\n';
      return 0;
    }
  }
  std::cerr << "Try to find all numbers of the array" << '\n';
  std::cerr << "You can use numbers 1..5" << '\n';
  for (int counter = 0; counter < kSize;) {
    int tmp{0};
    std::cin >> tmp;
    if (!(std::cin)) {
      std::cerr << "You entered a wrong symbol. Try again" << '\n';
      return 0;
    }
    for (int index = 0; index < kSize; ++index) {
      if (ar[index] != tmp) {
        continue;
      }
      ar[index] = 0;
      ++counter;
    }
  }
  std::cerr << "You found all numbers. Congratulations!" << '\n';
  for (int index = 0; index < kSize; ++index) {
    std::cerr << ar[index] << '\n';
  }
  return 0;
}