#include <array>
#include <iostream>

static void print_array(std::array<int, 5> &array) {
  for (int elem : array) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return;
}
static void bubble_sort(std::array<int, 5> &array) {
  for (size_t i = 0; i < array.size(); ++i) {
    for (size_t j = array.size() - 1; j > i; --j) {
      if (array[j - 1] > array[j]) {
        int32_t tmp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = tmp;
      }
    }
  }
  return;
}
int main() {
  std::cout << "Enter a list of numbers to fulfill the array (up to 5 numbers)"
            << '\n';
  constexpr size_t kSize{5};
  std::array<int, kSize> array{};
  for (size_t index = 0; array[index] == 0;) {
    if (!(std::cin >> array[index])) {
      std::cerr << "Wrong number or symbol. Try again" << '\n';
      return 0;
    }
    bubble_sort(array);
    print_array(array);
  }
  return 0;
}
