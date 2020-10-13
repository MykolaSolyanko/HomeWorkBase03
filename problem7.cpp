#include <iostream>

int main() {
  std::cout << "Enter the positive integer: ";

  uint32_t number{};
  std::cin >> number;

  std::cout << "Enter the check bit number: ";

  uint32_t check_bit{};
  std::cin >> check_bit;

  if ((number >> (check_bit - 1)) % 2 == 0) {
    std::cout << "No\n";
  } else {
    std::cout << "Yes\n";
  }
  return 0;
}
