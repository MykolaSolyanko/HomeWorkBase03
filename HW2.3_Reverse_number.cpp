#include <iostream>

int main() {
  int32_t signed_number{0};
  std::cout << "Please, enter your number" << '\n';
  std::cin >> signed_number;
  int32_t reverse_number{0};
  for (; signed_number != 0;) {
    reverse_number += (signed_number % 10);
    signed_number /= 10;
    if (signed_number == 0) {
      break;
    }
    reverse_number *= 10;
  }
  reverse_number *= -1;
  std::cout << "Reverse number is " << reverse_number << '\n';
  return 0;
}
