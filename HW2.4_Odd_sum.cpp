#include <iostream>

int main() {
  std::cerr << "Please, enter the list of numbers (up to 50 numbers)" << '\n';
  std::cerr << "Values of the numbers has to be in the range from -60 up to 90"
            << '\n';
  std::cerr << "If you want to finish, please, print 100" << '\n';
  int odd_sum{0};
  for (int i = 0; i < 50; ++i) {
    int input_number{0};
    std::cin >> input_number;
    if (input_number == 100) {
      break;
    }
    if (input_number < -60 || input_number > 90 || !(std::cin)) {
      std::cerr << "Value of the number is out of the numeric range" << '\n';
      return 0;
    }
    if ((input_number & 1) != 1) {
      continue;
    }
    odd_sum += input_number;
  }
  std::cerr << "The sum of the odd numbers is " << odd_sum << '\n';
  return 0;
}