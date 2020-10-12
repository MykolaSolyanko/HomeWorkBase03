#include <iostream>

int main() {

  std::cout << "Please, enter the positive integer: \n";

  int number{};
  std::cin >> number;

  int best_divider{};

  for (int i{1}; i < number; ++i) {
    if (number % i == 0) {
      best_divider = i;
    }
  }
  std::cout << "Best divider " << number << " equal " << best_divider << '\n';

  return 0;
}
