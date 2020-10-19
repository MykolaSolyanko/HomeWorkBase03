#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>

/**
 * @brief          Init one of coefficient for square equalation
 *
 * @param value     [inpit/output] value pointer to 
 * @param name      coefficient designation
 * @return true 
 * @return false 
 */
bool equalation_coefficient_init(double *value, char name) {
  if ((value == nullptr) || (name < 'A') || (name > 'C')) {
    return false;
  }

  constexpr int LIM_MIN{2};
  constexpr int LIM_MAX{255};

  std::cout << "Please enter number in range [" << LIM_MIN << ".." << LIM_MAX
            << "]" << std::endl;
  std::cout << name << "-->";
  std::cin >> *value;

  return ((*value >= LIM_MIN) && (*value <= LIM_MAX));
}

int main() {

  double a{};
  double b{};
  double c{};

  if (!equalation_coefficient_init(&a, 'A')) {
    std::cout << "Incorrect entered value" << std::endl;
    return EXIT_FAILURE;
  }

  if (!equalation_coefficient_init(&b, 'B')) {
    std::cout << "Incorrect entered value" << std::endl;
    return EXIT_FAILURE;
  }

  if (!equalation_coefficient_init(&c, 'C')) {
    std::cout << "Incorrect entered value" << std::endl;
    return EXIT_FAILURE;
  }

  const int POWER{2};
  const int MULTIPLIER{4};
  auto D = pow(b, POWER) - (MULTIPLIER * a * c);
  auto devider = POWER * a;

  std::cout << "Result is :" << std::endl;
  std::cout << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;

  if (D > 0) {
    D = sqrt(D);
    auto x1 = ((-b) - D) / devider;
    std::cout << "x1 = " << x1 << ";" << std::endl;
    auto x2 = ((-b) + D) / devider;
    std::cout << "x2 = " << x2 << ";" << std::endl;
  } else if (D == 0) {
    auto x = (-b) / (POWER * a);
    std::cout << "x = " << x << ";" << std::endl;
  } else {
    std::cout << "equalation has no roots" << std::endl;
  }

  return EXIT_SUCCESS;
}

