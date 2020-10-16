#include <cmath>
#include <iostream>

int main() {
  int atmpts{3};
  constexpr short lwr_bndr = 2;
  constexpr short uppr_bndr = 255;

  std::cout << "Enter three numbers in range " << lwr_bndr << "..."
            << std::to_string(uppr_bndr)
            << " separated by space in order a b c.\nIf value is empty leave 0."
            << std::endl;

  while (atmpts-- > 0) {
    short a{};
    short b{};
    short c{};

    std::cin >> a >> b >> c;
    bool a_range = a >= lwr_bndr && a <= uppr_bndr;
    bool b_range = b >= lwr_bndr && b <= uppr_bndr;
    bool c_range = c >= lwr_bndr && c <= uppr_bndr;

    if (a_range && b_range && c_range) {
      double x_1{};
      double x_2{};
      double discr = b * b - 4 * a * c;
      double mul_2_a = 2 * a;

      if (discr > 0) {
        double sqrt_discr = std::sqrt(discr);

        x_1 = (-b + sqrt_discr) / mul_2_a;
        x_2 = (-b - sqrt_discr) / mul_2_a;

        std::cout << "x1 = " << x_1 << std::endl;
        std::cout << "x2 = " << x_2 << std::endl;
      } else if (discr == 0) {
        x_1 = -(b / mul_2_a);

        std::cout << "x1 = x2 = " << x_1 << std::endl;
      } else {
        std::cout << "Discriminant < 0. The equation does not have solutions."
                  << std::endl;
      }
      break;
    } else {
      std::cout << "One of your values is out of range. Please, try again."
                << std::endl;
    }
  }
  return 0;
}
