#include <iostream>

int main() {
  int32_t kSize{0};
  std::cout << "Enter a number of symbols you want to use" << '\n';
  std::cin >> kSize;
  if (!(std::cin) || kSize < 1) {
    std::cout << "You entered a wrong number. Try again" << '\n';
    return 0;
  }
  ++kSize;
  char array[kSize]{};
  std::cout << "Enter your string" << '\n';
  std::cin >> array;
  std::cout << "is diget ";
  for (int index = 0; index < kSize; ++index) {
    if (array[index] > 47 && array[index] < 58) {
      std::cout << array[index] << ' ';
    }
  }
  std::cout << '\n';
  return 0;
}