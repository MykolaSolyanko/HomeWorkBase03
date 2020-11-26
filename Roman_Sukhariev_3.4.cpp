#include <cstdint>
#include <iostream>

int main() {
  constexpr size_t kSize{5};
  char array[kSize]{};
  std::cout << "Please, enter your string (up to 5 symbols)" << '\n';
  std::cin >> array;
  for (size_t index = 0; index < kSize; ++index) {
    constexpr int first_letter{97};
    constexpr int last_letter{122};
    if (array[index] >= first_letter && array[index] <= last_letter) {
      constexpr int uppercase_translation{32};
      array[index] -= uppercase_translation;
    }
  }
  for (char elem : array) {
    std::cout << elem;
  }
  std::cout << '\n';
  return 0;
}
