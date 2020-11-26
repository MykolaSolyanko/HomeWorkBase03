#include <iostream>

int main() {
  std::cout << "Please, enter your string (up to 5 symbols)" << '\n';
  constexpr size_t kSize{5};
  char normal_array[kSize]{};
  if (!(std::cin >> normal_array)) {
    std::cerr << "You entered a wrong symbol. Try again" << '\n';
    return 0;
  }
  std::cout << "Here is reverse string" << std::endl;
  size_t mid_array{kSize / 2};
  for (size_t index = 0; index < mid_array; ++index) {
    char tmp;
    tmp = normal_array[index];
    normal_array[index] = normal_array[kSize - 1 - index];
    normal_array[kSize - 1 - index] = tmp;
  }
  for (char elem : normal_array) {
    std::cout << elem;
  }
  std::cout << '\n';
  return 0;
}
