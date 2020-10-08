#include <cmath>
#include <iostream>

int main() {

  std::cout << "\t\t\tCalculating\n";
  std::cout << "Please enter number in range [2..255] --> ";
  int b{};
  std::cin >> b;
  double a = {4}, c = {2};
  bool run = false;
  int d = b * b - 4 * a * c;
  if (d > 0) {
    while (!run) {
      if (b < 256 && b > 1 && pow(b, 2) > 4 * a * c) {
        double x1 = ((-b) + sqrt(d)) / (2 * a);
        double x2 = ((-b) - sqrt(d)) / (2 * a);

        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
        break;
      } else if (pow(b, 2) < 4 * a * c) {
        std::cout << "Cannot calculate if sqrt b^2 < 4 * a * c\n";
        std::cout << "Please enter another number.\n";
        std::cin >> b;
      } else {
        std::cout << "You entered an incorrect number, try entering the number "
                     "again. \n";
        std::cin >> b;
      }
    }
  }
}
