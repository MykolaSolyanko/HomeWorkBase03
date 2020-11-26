#include <iostream>

int main() {
  std::cout << "Enter a string" << '\n';
  constexpr size_t kSize{5};
  char array[kSize]{};
  std::cin >> array;
  for (int index = 0; index < kSize; ++index) {
    constexpr int first_letter{65};
    constexpr int last_letter{90};
    if (array[index] >= first_letter && array[index] <= last_letter) {
      constexpr int lowercase_translation{32};
      array[index] += lowercase_translation;
    }
  }
  std::cout << array << '\n';
  return 0;
}
