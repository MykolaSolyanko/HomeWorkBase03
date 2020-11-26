#include <iostream>

int main() {
  std::cout << "Please, enter number" << std::endl;
  uint64_t number{0};
  std::cin >> number;
  int sum{0};
  int counter{0};
  for (; number != 0; number /= 10, ++counter) {
    sum += (number % 10);
  }
  std::cout << "Here is the sum of the numbers: " << sum << '\n';
  float average{static_cast<float>(sum) / counter};
  std::cout << "Here is the average of the numbers: " << average << '\n';
  return 0;
}
