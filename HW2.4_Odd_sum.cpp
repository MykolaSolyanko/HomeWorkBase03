#include <iostream>

int main() {
  std::cout << "Enter a size of the number list" << std::endl;
  size_t kSize{0};
  constexpr int min_list_size{1};
  constexpr int max_list_size{50};
  if (!(std::cin >> kSize) || kSize > max_list_size || kSize < min_list_size) {
    std::cerr << "Wrong number. Try again" << std::endl;
    return 0;
  }
  std::cout << "Enter the list of numbers" << std::endl;
  std::cout << "Values of the numbers has to be in the range from -60 up to 90"
            << std::endl;
  int odd_sum{0};
  for (size_t index = 0; index < kSize; ++index) {
    int input_list[kSize]{};
    constexpr int min_value{-60};
    constexpr int max_value{90};
    if (!(std::cin >> input_list[index]) || input_list[index] < min_value ||
        input_list[index] > max_value) {
      std::cerr << "Wrong number. Try again" << std::endl;
      return 0;
    }
    if ((input_list[index] % 2) == 0) {
      continue;
    }
    odd_sum += input_list[index];
  }
  std::cout << "The sum of the odd numbers is " << odd_sum << '\n';
  return 0;
}
