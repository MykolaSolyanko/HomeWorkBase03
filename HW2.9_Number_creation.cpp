#include <iostream>

int main() {
  uint64_t number{0};
  uint64_t total_number{0};
  std::cout << "Please, enter your numbers. ";
  std::cout << "To see the result, please print any letter" << '\n';
  for (; std::cin;) {
    std::cin >> number;
    for (; number != 0; number /= 10) {
      total_number += number % 10;
      total_number *= 10;
    }
  }
  if ((total_number % 3) == 0 && total_number != 0) {
    std::cout << "Yes" << '\n';
    return 0;
  }
  std::cerr << "No" << '\n';
  return 0;
}