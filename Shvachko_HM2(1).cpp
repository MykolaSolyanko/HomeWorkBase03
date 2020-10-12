// sum and average
#include <iostream>

unsigned getSum(unsigned value) {
  unsigned result = value % 10;
  while (value /= 10)
    result += value % 10;
  return result;
}

unsigned getAmount(unsigned value) {
  unsigned result = 1;
  while (value /= 10)
    result++;
  return result;
}

int main() {
  unsigned n = 12345;
  std::cerr << getSum(n) << std::endl;
  std::cerr << (getSum(n) / getAmount(n));
  return 0;
}
