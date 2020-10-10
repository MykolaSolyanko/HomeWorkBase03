#include <cmath>
#include <iostream>

constexpr int val1 = 4;
constexpr int val2 = 2;

//функция для вычиления корней квадратного уравнения
void quadr_equation(double a, double b, double c) {

  if (a == 0) {
    std::cout << "\nделение на ноль\n";
    return;
  }
  const double val3 = val2 * a;
  const double discrim = b * b - 4 * a * c; //расчет дискриминанта

  if (discrim < 0) {
    std::cout << "\nнет вещественных корней\n";
    return;
  }
  auto x1 = (-b + sqrt(discrim)) / val3;
  auto x2 = (-b - sqrt(discrim)) / val3;

  std::cout << "\nДля квадратного уравнения " << a << "x^2+" << b << "x+" << c
            << "=0\n"
            << "x1=" << x1 << "   x2=" << x2 << '\n';
}

int main() {

  char ans{};

  do {
    constexpr int max_val = 1000;
    constexpr int min_val = -1000;

    double a{};
    double b{};
    double c{};

    std::cout
        << "Для квадратного уравнения вида ax^2+bx+c=0\n"
        << "введите a, b, c - вещественные числа в диапазоне [-1000..1000]\n";

    std::cin >> a >> b >> c;
    if (std::cin.fail()) {
      std::cout << "некорректный ввод\n";
      break;
    }
    if ((a > max_val) || (b > max_val) || (c > max_val) || (a < min_val) ||
        (b < min_val) || (c < min_val)) {
      std::cout << "некорректное значение\n";
      break;
    }
    quadr_equation(a, b, c);

    std::cout << "\nЕсли хотите повторить вычисление  введите 'y'или 'Y'\n"
              << "если нет - любой другой символ\n\n";
    std::cin >> ans;

  } while (ans == 'y' || ans == 'Y');

  return 0;
}

