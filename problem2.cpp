#include <array>
#include <iostream>

int main() {
  constexpr uint8_t Size_Array = 7;
  std::array<int, Size_Array> arr{};

  std::cout << "Please enter " << Size_Array << "  integers: \n";

  for (size_t i{}; i < Size_Array; ++i) {
    int number{};
    std::cin >> number;
    if (!std::cin) {
      std::cout << "incorrect input\n";
      return -1;
    }
    if (i == 0) {
      arr.at(i) = number;
    } else {
      arr.at(i) = number;

      if (arr.at(i) < arr.at(i - 1)) {
        for (size_t n{i}; n > 0; --n) {
          if (arr.at(n) < arr.at(n - 1)) {
            std::swap(arr.at(n - 1), arr.at(n));
          }
        }
      }
    }
  }
  for (auto n : arr) {
    std::cout << n << " ";
  }

  return 0;
}
