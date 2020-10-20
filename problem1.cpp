#include <cstring>
#include <iostream>

int main() {
  std::cout << "Please enter string (no more 100 characters): \n";

  constexpr int Max_Char=100;
  
  char str[Max_Char];
  std::cin.get(str, Max_Char);

  for (size_t i{std::strlen(str) - 1}; str[i]; --i) {
    std::cout << str[i];
  }
  std::cout << '\n';

  return 0;
}
