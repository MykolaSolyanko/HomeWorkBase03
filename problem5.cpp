#include <cstring>
#include <iostream>

int main() {
  constexpr uint16_t Max_Char = 100;
  std::cout << "Please, enter string (no more " << Max_Char << " characters)\n";

  char str[Max_Char]{};
  std::cin >> str;

  std::cout << "Is digit: ";

  for (size_t i{}; i < std::strlen(str); ++i) {
    if (str[i] >= '0' && str[i] <= '9') {
      std::cout << str[i] << ' ';
    }
  }
  std::cout << '\n';

  return 0;
}
