#include <iostream>

int main(int argc, char *argv[]) {
  constexpr std::int32_t k{10};
  std::int32_t Number{};
  // check for correct input(int32_t)
  if (!(std::cin) >> Number) {
    std::cout << "Uncorrect";
    return 1;
  }

  // firtly, did with string
  //  std::string Number;
  //	std::cin >> Number;
  //	std::cout << std::string(Number.rbegin(), Nubmer.rend()) << '\n';

  // found on the internet, but its work
  std::int32_t RevNumber{};
  while (Number) {
    RevNumber = RevNumber * k + Number % k;
    Number /= k;
  }

  std::cout << RevNumber << '\n';
  return 0;
}
