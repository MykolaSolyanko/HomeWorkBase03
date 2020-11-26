#include <array>
#include <iostream>

int main() {
  constexpr size_t kSize{5};
  std::array<int, kSize> ar{};
  std::cout << "Please, fulfill the array. Use numbers 1..5. Zero is forbidden"
            << '\n';
  constexpr int max_value{5};
  constexpr int min_value{1};
  for (auto& value : ar) {
    std::cin >> value;
    if (!(std::cin) || value < min_value || value > max_value) {
      std::cerr << "You entered a wrong symbol. Try again" << '\n';
      return 0;
    }
  }
  std::cout << "Try to find all numbers of the array" << '\n';
  std::cout << "You can use numbers 1..5" << '\n';
  for (int counter = 0; counter < ar.size();) {
    int tmp{0};
    if (!(std::cin >> tmp)) {
      std::cerr << "You entered a wrong symbol. Try again" << '\n';
      return 0;
    }
    for (auto& value : ar) {
      if (value != tmp) {
        continue;
      }
      value = 0;
      ++counter;
    }
  }
  std::cout << "You found all numbers. Congratulations!" << '\n';
  for (auto& value : ar) {
    std::cout << value << '\n';
  }
  return 0;
}
