#include <cmath>
#include <iostream>

int main() {

  std::cout << "Please, enter the integer: \n";

  int32_t number{};
  std::cin >> number;

  int32_t rev_number{};

  while (number>0) {
    rev_number = number % 10 + rev_number * 10;
    number /= 10;
  }

  std::cout << "Reverse number equal " << rev_number << '\n';
  
  return 0;
}
