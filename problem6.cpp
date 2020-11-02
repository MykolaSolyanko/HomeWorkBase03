#include <cstring>
#include <iostream>

int main() {
  constexpr int Max_Char = 100;
  std::cout << "Please, enter string (no more " << Max_Char
            << " characters) \n";

  char str[Max_Char]{};
  std::cin >> str;

  constexpr uint8_t Differ_Low_Up = 32;

  std::cout << "to lower: ";

  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += Differ_Low_Up;
    }
   }
  }
  std::cout << str << '\n';

  return 0;
}
