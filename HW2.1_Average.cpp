#include <cstdint>
#include <iostream>

int main() {
  std::cerr << "Please, enter number" << std::endl;
  uint64_t number{0};
  std::cin >> number;
  int sum{0};
  int counter{0};
  for (; number != 0;) {
    sum += (number % 10);
    number /= 10;
    ++counter;
  }
  std::cerr << "Here is the sum of the numbers: " << sum << '\n';
  float average{static_cast<float>(sum) / counter};
  std::cerr << "Here is the average of the numbers: " << average << '\n';
  return 0;
}
