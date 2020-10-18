#include <cmath>
#include <iostream>

int main() {
  int a{0};
  int b{0};
  int c{0};
  std::cout << "To solve the equation ax2 + bx + c = 0, enter a, b, c"
            << std::endl;
  std::cout << "Enter a (2..255). It cannot be zero" << std::endl;
  std::cin >> a;
  if (a == 0 || a < 2 || a > 255) {
    std::cout << "You have entered incorrect number" << std::endl;
    return 0;
  }
  std::cout << "Enter b (2..255)" << std::endl;
  std::cin >> b;
  if (b < 2 || b > 255) {
    std::cout << "You have entered incorrect number" << std::endl;
    return 0;
  }
  std::cout << "Enter c (2..255)" << std::endl;
  std::cin >> c;
  if (c < 2 || c > 255) {
    std::cout << "You have entered incorrect number" << std::endl;
    return 0;
  }
  const long double D{static_cast<long double>((b * b) - (4 * a * c))};
  if (D > 0) {
    long double root1 = (sqrt(D) - b) / (2 * a);
    long double root2 = (-b - sqrt(D)) / (2 * a);
    std::cout << "Roots of the equation are: " << std::endl;
    std::cout << "root1 = " << root1 << std::endl;
    std::cout << "root2 = " << root2 << std::endl;
  } else {
    std::cout << "Discriminant is negative. Try to enter a, b, c one more time"
              << std::endl;
  }
  return 0;
}