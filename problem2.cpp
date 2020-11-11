#include <cmath>
#include <iostream>
#include <string>

bool is_whole(const std::string &str);
bool is_digit(const std::string &str);
void revert(std::string &str);
void shift_left(std::string &str);

int main() {
  std::cout << "Enter the string of the positive integers\n";

  std::string str;
  std::cin >> str;
  if (!is_digit(str)) {
    std::cout << "incorrect input\n";
    return -1;
  }
  std::cout << "Enter the size piece of the string\n";

  size_t Size_Piece{};
  std::cin >> Size_Piece;
  if (!std::cin || Size_Piece >= str.size()) {
    std::cout << "Sorry.. incorrect size of piece\n";
  }
  uint16_t Number_Parts = str.size() / Size_Piece;
  std::string revrot;
  size_t i{0};

  while (Number_Parts > 0) {
    std::string tmp_str;
    tmp_str = str.substr(i, Size_Piece);
    if (is_whole(tmp_str)) {
      revert(tmp_str);
    } else {
      shift_left(tmp_str);
    }
    revrot += tmp_str;
    i += Size_Piece;
    --Number_Parts;
  }

  std::cout << "Result: " << revrot << '\n';

  return 0;
}

bool is_whole(const std::string &str) {
  long long str_in_int = std::stoull(str);
  long long sum_cubes_digit{};
  while (str_in_int != 0) {
    int digit = str_in_int % 10;
    str_in_int /= 10;
    sum_cubes_digit += std::pow(digit, 3);
  }
  return (sum_cubes_digit % 2 == 0) ? true : false;
}

bool is_digit(const std::string &str) {
  for (size_t i = 0; i < str.size(); ++i) {
    if (str[i] >= '0' && str[i] <= '9') {

    } else {
      return false;
    }
  }
  return true;
}

void revert(std::string &str) {
  const size_t Size_Str = str.size();
  for (size_t i = 0; i < Size_Str / 2; ++i) {
    std::swap(str[i], str[Size_Str - i - 1]);
  }
}

void shift_left(std::string &str) {
  const size_t Size_Str = str.size();
  char tmp = str[0];
  for (size_t i = 0; i < Size_Str - 1; ++i) {
    str[i] = str[i + 1];
  }
  str[Size_Str - 1] = tmp;
}
