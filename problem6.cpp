#include <cstring>
#include <iostream>

int main() {
  constexpr int Max_Char = 100;
  std::cout << "Please, enter string (no more " << Max_Char
            << " characters) \n";

  char str[Max_Char]{};
  std::cin >> str;

  std::cout << "to lower: ";

  for (size_t i{}; i < std::strlen(str); ++i) {
    if (static_cast<int>(str[i]) <= 90 && static_cast<int>(str[i]) >= 65) {
      str[i] = static_cast<char>(str[i] + 32);
    }
  }
  std::cout << str << '\n';

  return 0;
}
