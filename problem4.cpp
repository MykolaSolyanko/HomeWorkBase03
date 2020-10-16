#include <iostream>

int main() {

  std::cout << "Enter list integers from -60 to 90\n"
            << "(no more 50 numbers). At the end of input put 0 \n";

  constexpr int Max_Size = 50;
  constexpr int Low_Scope = -60;
  constexpr int High_Scope = 90;

  int sum{};

  for (int i{1}; i < Max_Size; ++i) {
    int num{};
    std::cin >> num;
    if (!std::cin || num == 0) {
      break;
    }
    if (num <= Low_Scope || num >= High_Scope) {
      std::cout << "out of scope\n";
      break;
    }
    if (i % 2 != 0) {
      sum += num;
    }
  }
  std::cout << "Sum of numbers in odd places is " << sum << '\n';

  return 0;
}