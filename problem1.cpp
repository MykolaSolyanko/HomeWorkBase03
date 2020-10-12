#include <cmath>
#include <iostream>

int main() {

  std::cout << "Enter the integer in scope from 1 to 1000000\n";

  int number{};
  std::cin >> number;

  const int n = std::log10(number) + 1;
  int sum{};

  for (int i{}; i < n; ++i) {
    auto val = number % 10;
    sum += val;
    number /= 10;
  }

  auto average = static_cast<double>(sum) / n;

  std::cout << "Sum of digits in number  equal " << sum << '\n'
            << "Average is  " << average << '\n';

  return 0;
}
