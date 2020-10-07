#include <cmath>
#include <iostream>

constexpr int val1 = 4;
constexpr int val2 = 2;

void quadr_equation(
    double a, double b,
    double c) { //функция для вычиления корней квадратного уравнения
  if (a == 0) {
    std::cout << "деление на ноль\n";
    return;
  }
  double discrim = b * b - 4 * a * c; //расчет дискриминанта

  if (discrim < 0) {
    std::cout << "нет вещественных корней\n";
    return;
  }
  auto x1 = (-b + sqrt(b * b - val1 * a * c)) / (val2 * a);
  auto x2 = (-b - sqrt(b * b - val1 * a * c)) / (val2 * a);

  std::cout << "Для квадратного уравнения " << a << "x^2+" << b << "x+" << c
            << "=0\n"
            << "x1=" << x1 << "   x2=" << x2 << '\n';
}

int main() {
  double a{};
  double b{};
  double c{};

  char ans{};

  do {
    std::cout
        << "Для квадратного уравнения вида ax^2+bx+c=0\n"
        << "введите a, b, c - вещественные числа в диапазоне [-1000..1000]\n";

    std::cin >> a >> b >> c;

    if (a > 1000 || a < -1000 || b > 1000 || b < -1000 || c > 1000 ||
        c < -1000) {
      std::cout << "некорректное значение\n";
    }
    quadr_equation(a, b, c);

    std::cout << "Если хотите повторить вычисление  введите 'y'или 'Y'\n"
              << "если нет - любой другой симол\n";
    std::cin >> ans;

  } while (ans == 'y' || ans == 'Y');

  return 0;
}
