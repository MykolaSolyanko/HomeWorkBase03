#include <cstdint>
#include <iostream>

static void print_array(int array[], size_t kSize) {
  for (size_t index = 0; index < kSize; ++index) {
    std::cerr << array[index] << ' ';
  }
  std::cerr << '\n';
  return;
}
static void bubble_sort(int array[], size_t kSize) {
  for (size_t i = 0; i < kSize; ++i) {
    for (size_t j = kSize - 1; j > i; --j) {
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
  size_t kSize{};
  std::cerr << "Enter a size of array" << '\n';
  if (!(std::cin >> kSize) || kSize < 1) {
    std::cout << "Wrong size. Try again" << '\n';
    return 0;
  }
  int array[kSize]{};
  std::cerr << "Enter a list of numbers to fulfill the array (w)" << '\n';
  for (size_t index = 0; array[index] == 0;) {
    if (!(std::cin >> array[index]) || array[index] == 0) {
      std::cout << "Wrong number or symbol. Try again" << '\n';
      array[index] = 0;
      continue;
    }
    bubble_sort(array, kSize);
    print_array(array, kSize);
  }
  return 0;
}