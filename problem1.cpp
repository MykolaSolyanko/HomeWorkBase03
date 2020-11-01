#include <cstring>
#include <iostream>

int main() {
  constexpr int Max_Char=100;
  
  std::cout << "Please enter string (no more "<<Max_Char<<" characters): \n";  
  
  char str[Max_Char];
  std::cin.get(str, Max_Char);

   for (size_t i = 0; i < std::strlen(str) / 2; ++i) {
      std::swap(str[i], str[std::strlen(str) - 1 - i]);
  }
  std::cout <<"Revert string: "<<str<< '\n';

  return 0;
}
