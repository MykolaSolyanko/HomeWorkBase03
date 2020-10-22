#include <iostream>

int main() {
  std::cout << "Please enter the positive integer:\n ";

  uint16_t number{};
  std::cin >> number;

  uint16_t sum_bit{};

  while (number > 0) {
    if ((number & 1 ) != 0) {
      ++sum_bit;
    }
    number >>= 1;
  }
  std::cout << "The sum of the bits set is: " << sum_bit << '\n';

  return 0;
}
