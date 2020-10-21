// inverse number
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Enter value, which want to inverse-->";
  constexpr std::int32_t k{10};
  std::int32_t Number{};
  std::cin >> Number;
  // check for correct input(int32_t)
  if (!(std::cin) >> (Number)) {
    std::cout << "Uncorrect";
    return 1;
  }

  std::int32_t RevNumber{};
  while (abs(Number) > 0) {
    RevNumber = RevNumber * k + abs(Number) % k;
    Number /= k;
  }

  std::cout << RevNumber << '\n';
  return 0;
}
