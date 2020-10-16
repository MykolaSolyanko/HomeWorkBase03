#include <iostream>
#include <math.h>

int main() {

  const int min_range{-50};
  const int max_range{50};

  std::cout << "Quadratic equation : Ax^2 + Bx+C =0" << std::endl;
  std::cout << "Please, enter integers A,B,C ( in the range (-50;50)) "
            << std::endl;

  std::cout << "A = ";
  int a;
  std::cin >> a;
  if (a < min_range || a > max_range) {
    std::cout << "Please, enter value in the range (-50;50)";
    return -1;
  }

  std::cout << "B= ";
  float b;
  std::cin >> b;
  if (b < min_range || b > max_range) {
    std::cout << "Please, enter value in the range (-50;50)";
    return -1;
  }

  std::cout << "C = ";
  float c;
  std::cin >> c;
  if (c < min_range || c > max_range) {
    std::cout << "Please, enter value in the range (-50;50)";
    return -1;
  }

  if (a == 0) {
    float x = -c / b;
    std::cout << "x= " << x;
    return 0;
  }

  float d = pow(b, 2) - 4 * a * c;
  if (d < 0) {
    std::cout << "Your quadratic equation has no real roots (D<0)";
    return -1;
  }

  if (d == 0) {
    float x = -b / 2 * a;
    std::cout << "x= " << x;
    return 0;
  }

  float x1 = (-b + sqrt(d)) / 2 * a;
  float x2 = (-b - sqrt(d)) / 2 * a;

  std::cout << "x1 = " << x1 << "\n"
            << "x2 = " << x2;
  return 0;
}
