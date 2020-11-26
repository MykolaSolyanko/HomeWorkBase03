#include <iostream>

int main() {
  uint32_t input_number{0};
  std::cout << "Please, enter your number" << '\n';
  std::cin >> input_number;
  int best_divider{0};
  for (int32_t divider = 1; divider <= input_number; ++divider) {
    if ((input_number % divider) != 0) {
      continue;
    }
    int div_copy = divider;
    int best_div_copy = best_divider;
    int64_t check_number{0};
    for (; divider > 0; divider /= 10) {
      check_number += divider % 10;
      check_number -= best_divider % 10;
      best_divider /= 10;
    }
    divider = div_copy;
    if (check_number <= 0) {
      best_divider = best_div_copy;
    } else {
      best_divider = div_copy;
    }
  }
  std::cout << "The best divider is " << best_divider << '\n';
  return 0;
}
