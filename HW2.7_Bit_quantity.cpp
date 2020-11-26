#include <iostream>

int main() {
  int input_number{0};
  std::cout << "Enter your number (-300..300)" << std::endl;
  constexpr int min_input_number{-300};
  constexpr int max_input_number{300};
  if (!(std::cin >> input_number) || input_number < min_input_number ||
      input_number > max_input_number) {
    std::cerr << "Wrong number. Try again" << std::endl;
    return 0;
  }
  constexpr int max_bit_position{10};
  int bit_mask{1};
  int bit_quantity{0};
  for (int bit_position = 1; bit_position < max_bit_position;
       ++bit_position, bit_mask = bit_mask << 1) {
    if ((input_number & bit_mask) == 0) {
      continue;
    }
    ++bit_quantity;
  }
  std::cout << "Bit quantity: " << bit_quantity << std::endl;
  return 0;
}