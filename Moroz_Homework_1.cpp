#include <cmath>
#include <iostream>
#include <limits>

constexpr uint16_t dividendMultiply(4);
constexpr uint16_t dividerMultiply(2);

constexpr uint16_t numberOfAttempts(3);

int main() {
  uint16_t a(0);
  uint16_t b(0);
  uint16_t c(0);

  uint16_t attemptsCounter = 0;

  while (attemptsCounter < numberOfAttempts) {
    std::cout << "Please, enter 3 variables (a, b, c) separated by space. "
                 "Variables must be in range 2.."
              << std::numeric_limits<uint16_t>::max() << std::endl;
    std::cin >> a >> b >> c;

    if ((a >= 2) && (a < std::numeric_limits<uint16_t>::max())) {
      if ((b >= 2) && (a < std::numeric_limits<uint16_t>::max())) {
        if ((c >= 2) && (a < std::numeric_limits<uint16_t>::max())) {
          std::cout << "All variables are correct." << std::endl;
          break;
        } else {
          std::cout << "c is out of range." << std::endl;
          attemptsCounter++;
        }
      } else {
        std::cout << "b is out of range." << std::endl;
        attemptsCounter++;
      }
    } else {
      std::cout << "a is out of range." << std::endl;
      attemptsCounter++;
    }
  }

  if (attemptsCounter < numberOfAttempts) {
    auto discriminant = b * b - dividendMultiply * a * c;
    if (discriminant > 0) {
      auto x1 = (-b + sqrt(discriminant)) / (dividerMultiply * a);
      auto x2 = (-b - sqrt(discriminant)) / (dividerMultiply * a);
      std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (discriminant == 0) {
      auto x1 = -b / (dividerMultiply * a);
      std::cout << "x1 = x2 = " << x1 << std::endl;
    } else
      std::cout << "Discriminant is less than 0." << std::endl;
  } else {
    std::cout << "You used all of your attempts. Please restart programm."
              << std::endl;
  }

  return 0;
}
