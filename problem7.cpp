#include <iostream>

int main() {
  std::cout << "Enter the positive integer: ";

  uint32_t number{};
  std::cin >> number;
    if(check_bit<=0){
    std::cout<<incorrect input\n";
      return 1;
  }

  std::cout << "Enter the check bit number: ";

  uint32_t check_bit{};
  std::cin >> check_bit;
  if(check_bit<=0){
    std::cout<<incorrect input\n";
      return 1;
  }

  if (((number >> (check_bit - 1)) & 1) == 0) {
    std::cout << "No\n";
  } else {
    std::cout << "Yes\n";
  }
  return 0;
}
