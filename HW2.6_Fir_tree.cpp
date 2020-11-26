#include <iostream>

int main() {
  int stars_number{0};
  std::cerr << "Please, enter your number of stars" << '\n';
  std::cin >> stars_number;
  if ((stars_number & 1) != 1 && stars_number != 0) {
    ++stars_number;
  }
  for (int stars = 1; stars <= stars_number; stars += 2) {
    for (int space = 1; space <= (stars_number - stars) / 2; ++space) {
      std::cerr << ' ';
    }
    for (int counter = 1; counter <= stars; ++counter) {
      std::cerr << '*';
    }
    std::cerr << '\n';
  }
  return 0;
}