// lucky ticket
#include <iostream>

unsigned getSum(unsigned value) {
  unsigned result = value % 10;
  while (value /= 10)
    result += value % 10;
  return result;
}

int main() {
  std::cout << "Enter your ticket number --->";
  std::int32_t Numb{};
  std::int32_t Select = Numb;
  std::cin >> Numb;
  if ((Select /= 1000000) > 0) {
    std::cout << "Wrong input";
    return -1;
  }
  std::int16_t Res1 = Numb / 1000;
  std::int16_t Res2 = Numb % 1000;
  if (getSum(Res1) != getSum(Res2)) {
    std::cout << ":(";
    return 1;
  }
  std::cout << "You win!";
  return 0;
}
