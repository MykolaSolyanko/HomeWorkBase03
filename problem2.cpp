#include <array>
#include <iostream>

constexpr uint16_t Size_Array = 7;

void sort_in_place(std::array<int, Size_Array> &arr, size_t index) {
  if (arr[index] < arr[index - 1]) {
    for (size_t n = index; n > 0; --n) {
      if (arr[n] < arr[n - 1]) {
        std::swap(arr[n], arr[n - 1]);
      }
    }
  }
}

int main() {
  std::array<int, Size_Array> arr{};

  std::cout << "Please enter " << Size_Array << "  integers: \n"
            << "Number will sort when inserted\n";

  for (size_t i = 0; i < arr.size(); ++i) {
    int number{};
    std::cin >> number;
    if (!std::cin) {
      std::cout << "incorrect input\n";
      return -1;
    }
    if (i == 0) {
      arr[i] = number;
      continue;
    }
    arr[i] = number;
    sort_in_place(arr, i);
  }
  for (auto n : arr) {
    std::cout << n << " ";
  }

  return 0;
}

