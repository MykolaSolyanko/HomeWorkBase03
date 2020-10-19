#include <cmath>
#include <iostream>
#include <limits>

constexpr uint16_t dividendMultiply{4};
constexpr uint16_t dividerMultiply{2};

constexpr uint16_t numberOfAttempts{3};
constexpr uint16_t minValue{2};

int main() {
  int16_t a{};
  int16_t b{};
  int16_t c{};

  uint16_t attemptsCounter{};

  while (attemptsCounter < numberOfAttempts) {
    std::cout << "Please, enter " << numberOfAttempts << " variables (a, b, c) separated by space. "
                 "Variables must be in range 2.."
              << std::numeric_limits<int16_t>::max() << std::endl;
    std::cin >> a >> b >> c;

    if ((a >= minValue) && (a < std::numeric_limits<int16_t>::max())) {
      if ((b >= minValue) && (a < std::numeric_limits<int16_t>::max())) {
        if ((c >= minValue) && (a < std::numeric_limits<int16_t>::max())) {
          std::cout << "All variables are correct." << std::endl;
          break;
        } else {
          std::cout << "c is out of range." << std::endl;
        }
      } else {
        std::cout << "b is out of range." << std::endl;
      }
    } else {
      std::cout << "a is out of range." << std::endl;
    }
    attemptsCounter++;
  }

  if (attemptsCounter < numberOfAttempts) {
    const auto divider = dividerMultiply * a;
    const auto discriminant = (b * b) - (divider * c);
    if (discriminant > 0) {
      const auto x1 = (-b + sqrt(discriminant)) / divider;
      const auto x2 = (-b - sqrt(discriminant)) / divider;
      std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (discriminant == 0) {
      const auto x1 = -b / (dividerMultiply * a);
      std::cout << "x1 = x2 = " << x1 << std::endl;
    } else
      std::cout << "Discriminant is less than 0." << std::endl;
  } else {
    std::cout << "You used all of your attempts. Please restart programm."
              << std::endl;
  }

  return 0;
}
