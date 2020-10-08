#include <cmath>
#include <iostream>

int main() {

  std::cout << "\t\t\tCalculating\n";
  std::cout << "a = 4, c = 2" << std::endl;
  std::cout << "Please enter b in range [2..255] --> ";
  int b{};
  std::cin >> b;
  int a = {4}, c = {2};
  bool run = false;

  while (!run) {
    int d = pow(b, 2) - 4 * a * c;
    if (b < 2 || b > 255) {
      std::cout << "You entered an incorrect number, try entering the number "
                   "again. \n";
      std::cin >> b;
    }

    else if (d < 0) {
      std::cout << "Cannot calculate if d < 0\n";
      std::cout << "Please enter another number.\n";
      std::cin >> b;
    } else if (d > 0) {
      double x1 = ((-b) + sqrt(d)) / (2 * a);
      double x2 = ((-b) - sqrt(d)) / (2 * a);

      std::cout << "x1 = " << x1 << std::endl;
      std::cout << "x2 = " << x2 << std::endl;
      break;
    }
  }
}
