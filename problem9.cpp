#include <iostream>

int main() {
  std::cout << "Please enter positive integers \n"
            << "in the end input put 0 \n";

  int number{};
  int sum{};

  while (std::cin >> number && number != 0) {
    sum += number;
  }

 std::cout << (sum % 3) ? "Yes\n"  : "No\n";

  return 0;
}
