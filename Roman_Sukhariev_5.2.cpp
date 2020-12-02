#include <iostream>
#include <string>

enum Enum : bool { Even = false, Odd = true };

int main() {
  std::string str;
  std::cout << "Enter your number" << '\n';
  std::cin >> str;
  for (char elem : str) {
    if (elem < '0' || elem > '9') {
      std::cerr << "Error. Wrong symbol" << '\n';
      return 0;
    }
  }
  constexpr size_t ksize_sz{3};
  if (str.length() < ksize_sz) {
    std::cerr << "" << '\n';
    return 0;
  }
  std::string revrot{};
  for (size_t counter = 0; str[counter] != '\0';) {
    std::string sz;
    sz.resize(ksize_sz);
    if ((str.size() - counter) < sz.size()) {
      break;
    }
    for (size_t index = 0; index < sz.size(); ++index, ++counter) {
      sz[index] = str[counter];
    }
    long long int_number = std::stoll(sz);
    int sum{0};
    for (; int_number != 0; int_number /= 10) {
      sum += int_number % 10;
    }
    if (sum <= 0) {
      std::cout << "" << '\n';
      return 0;
    }
    bool flag;
    if (sum % 2 == 0) {
      flag = Even;
    } else {
      flag = Odd;
    }
    switch (flag) {
      case Even: {
        for (size_t index = 0; index < sz.size() / 2; ++index) {
          auto tmp = sz[index];
          sz[index] = sz[sz.size() - 1 - index];
          sz[sz.size() - 1 - index] = tmp;
        }
      } break;
      case Odd:
        auto tmp = sz[0];
        for (size_t index = 1; index < sz.size(); ++index) {
          sz[index - 1] = sz[index];
        }
        sz[sz.size() - 1] = tmp;
        break;
    }
    revrot += sz;
  }
  std::cout << "Here is result value: " << revrot << '\n';
  return 0;
}