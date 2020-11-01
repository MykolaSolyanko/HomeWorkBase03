#include <array>
#include <random>
#include <iostream>

int main() {
  constexpr uint16_t Size_Array = 5;
  std::array<int, Size_Array> arr{};

  std::random_device rd;
  std::uniform_int_distribution<int> dist(1, 9);

  for (size_t i{}; i < Size_Array; ++i) {
      arr[i] = dist(rd);
  }
    size_t reduce_size{Size_Array};

  while (std::cin && reduce_size != 0) {
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
    
    for (size_t i = 0; i < arr.size(); ++i) {
      if (arr[i] == number) {
        std::cout << "Deleting " << arr[i] << " from array\n\n";
        for (size_t n = i; n < reduce_size; ++n) {
          arr[n] = arr[n + 1];
        }
        --reduce_size;
      }
    }
    for (size_t i = 0; i < reduce_size; ++i) {
      std::cout << arr[i] << " ";
    }
      std::cout << "\ntry again\n";
  }

  std::cout << "Array is empty\n";

  return 0;
}
