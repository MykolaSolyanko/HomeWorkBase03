#include <cmath>
#include <iostream>

long int a;
long int b;
long int c;
double D;
constexpr int discrconst4{4};
constexpr int findxconst2{2};

int main() {

  std::cout << "The equation will look like this: ax2 + bx + c = 0"
            << std::endl;
  std::cout << " Enter number a: ";
  std::cin >> a;
  if (a == 0) {
    std::cout
        << "Error: wrong number. Please use number bigger or smaller than 0"
        << std::endl;
    std::cout << "Enter numver a again, please: ";
    std::cin >> a;
  }
  std::cout << "\n Enter number b: ";
  std::cin >> b;
  std::cout << "\n Enter number c: ";
  std::cin >> c;
  D = pow(b, 2) - discrconst4 * a * c;

  if (D < 0) {
    std::cout << "Error! Discriminant have value smaller than 0." << std::endl,
        std::cout << "Please try to change one of the numbers: a, b or c. ";
  }
  auto x1 = (-b + (sqrt(D))) / findxconst2 * a;
  auto x2 = (-b - (sqrt(D))) / findxconst2 * a;
  std::cout << "\n x1= " << x1;
  std::cout << "\n x2= " << x2;
}
