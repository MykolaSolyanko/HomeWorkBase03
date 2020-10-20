#include <array>
#include <experimental/random>
#include <iostream>

int main() {
  constexpr uint16_t Size_Array = 5;
  std::array<int, Size_Array> arr{};

  for (size_t i{}; i < Size_Array; ++i) {
    arr.at(i) = std::experimental::randint(1, 20);
  }

  long sum{1};

  while (std::cin) {
    constexpr uint16_t Low_Limit{1};
    constexpr uint16_t Upper_Limit{20};
    std::cout << "Enter positive integer in scope [" << Low_Limit << ".."
              << Upper_Limit << "]\n";
    int number{};
    std::cin >> number;
    if (!std::cin || number < Low_Limit || number > Upper_Limit) {
      std::cout << "incorrect input\n";
      break;
    }
    sum = 0;

    for (size_t i{}; i < Size_Array; ++i) {
      if (arr.at(i) == number) {
        std::cout << "Deleting " << arr.at(i) << " from array\n\n";
        arr.at(i) = 0;
      }
      sum += arr.at(i);
    }
    if (sum != 0) {
      std::cout << "\ntry again\n\n";
    } else {
      std::cout << "Array is empty\n";
      break;
    }
  }

  return 0;
}
