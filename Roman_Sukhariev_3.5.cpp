#include <iostream>

int main() {
  constexpr size_t kSize{5};
  char array[kSize]{};
  std::cout << "Enter your string" << '\n';
  std::cin >> array;
  std::cout << "is diget ";
  for (char elem : array) {
    constexpr int zero_number{48};
    constexpr int nine_number{57};
    if (elem >= zero_number && elem <= nine_number) {
      std::cout << elem << ' ';
    }
  }
  std::cout << '\n';
  return 0;
}
