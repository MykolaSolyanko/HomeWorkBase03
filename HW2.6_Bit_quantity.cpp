#include <cstdint>
#include <iostream>

int main() {
  int64_t check_number{0};
  uint32_t number{0};
  std::cerr << "Please, enter your number" << '\n';
  std::cin >> number;
  std::cerr << "Please, enter your check number" << '\n';
  std::cin >> check_number;
  if ((number & check_number) == 0) {
    std::cerr << "No" << '\n';
    return 0;
  }
  std::cerr << "Yes" << '\n';
  return 0;
}