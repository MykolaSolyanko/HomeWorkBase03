#include <iostream>

int main() {
  std::cout << "Enter your string (up to 5 symbols)" << '\n';
  constexpr size_t kSize{5};
  char string_array[kSize]{};
  std::cin >> string_array;
  size_t row{2};
  size_t column{(kSize / 2) + 1};
  char crypto_array[row][column]{};
  for (size_t index = 0, i = 0; i < column; ++i) {
    for (size_t j = 0; j < row && index < kSize; ++j, ++index) {
      crypto_array[j][i] = string_array[index];
    }
  }
  std::cout << "Here is encrypted message" << '\n';
  for (size_t i = 0; i < row; ++i) {
    for (size_t j = 0; j < column; ++j) {
      std::cout << crypto_array[i][j];
    }
  }
  std::cout << '\n';
  std::cout << "Please, enter your row (enter \'2\')" << '\n';
  if (!(std::cin >> row)) {
    std::cerr << "You entered a wrong symbol. Try again" << '\n';
    return 0;
  }
  std::cout << "Please, enter your column (enter \'" << (kSize / 2) + 1 << "\')"
            << '\n';
  if (!(std::cin >> column)) {
    std::cerr << "You entered a wrong symbol. Try again" << '\n';
    return 0;
  }
  std::cout << "Here is decrypted message:" << '\n';
  for (size_t i = 0; i < column; ++i) {
    for (size_t j = 0; j < row; ++j) {
      std::cout << crypto_array[j][i];
    }
  }
  std::cout << '\n';
  return 0;
}