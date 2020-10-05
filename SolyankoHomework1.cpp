#include <iomanip>
#include <iostream>
#include <limits>

// IEEE 754
// UTF-8
// void
int main(int argc, char const *argv[]) {
  int count{};

  int value{3};
  long long res = ++count + value++;

  if (true) {
    value = 100;
  }

  std::cout << count << std::endl; // 2

  return 0;
}
