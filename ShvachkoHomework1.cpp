#include <cmath>
#include <iostream>

constexpr int two{2};
constexpr int four{4};

constexpr int llimit{-100};
constexpr int rlimits{100};

constexpr int attemtps{3};


int main() {
  int a{}, b{}, c{}, d{};
  int trying(0);
  // Проверяем корректность вводимых значений
  while (trying < attemtps) {
    std::cout << "Enter your coefficient a,b,c in range [-100;100]\n";
    std::cin >> a >> b >> c;
    if (a != 0 && a > -100 && a < 100) {
      if (b > -100 && b < 100) {
        if (c > -100 && c < 100) {
          std::cout << "Correctly!\n";
          break;
        } else
          std::cout << "Incorrectly\n!";
        trying++;
      } else
        std::cout << "Incorrectly!\n";
      trying++;
    } else
      std::cout << "Incorrectly!\n";
    trying++;
  }
  // основная фукнция подсчета
  if (trying <= attemtps)

  {
    const int discrim{d} = b * b - four * a * c;
    if (discrim < 0)
      std::cout << "No roots!\n";

    else if (discrim == 0) {
      auto x1 = -b / (two * a);
      std::cout << "x1=" << x1 << std::endl << "x2" << x1 << std::endl;
    }

    else {
      auto x1 = (-b + sqrt(discrim)) / (two * a);
      auto x2 = (-b - sqrt(discrim)) / (two * a);
      std::cout << "x1=" << x1 << "x2" << x2 << std::endl;
    }
  }

  else {
    std::cout << "Restart programm";
  }
  return 0;
}
