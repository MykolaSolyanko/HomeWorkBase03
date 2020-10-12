#include <cmath>
#include <iostream>

int main() {

  constexpr int NUM_DIGITS = 6;

  std::cout << "Please enter six-digit number: " << '\n';

  int value{};
  std::cin >> value;

  if (!std::cin || (int(std::log10(value) + 1) != NUM_DIGITS)) {
    std::cout << "incorrect input\n";
    return -1;
  }

  int left_set_digits{};
  int right_set_digits{};

  for (int i{}; i < NUM_DIGITS; ++i) {
    auto num = value % 10;
    value /= 10;
    if (i < (NUM_DIGITS / 2)) {
      right_set_digits += num;
    } else {
      left_set_digits += num;
    }
  }
  if (right_set_digits == left_set_digits) {
    std::cout << "Lucky ticket\n";
  } else {
    std::cout << "try again\n";
  }

  return 0;
}
