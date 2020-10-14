#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>

uint8_t equalation_init(double *a, double *b, double *c);

uint8_t equalation_solve(double a, double b, double c, double *x1, double *x2);

void equalation_result_print(double a, double b, double c, uint8_t roots_num,
                             double x1, double x2);

int main() {

  double a{};
  double b{};
  double c{};

  if (!equalation_init(&a, &b, &c)) {
    return EXIT_FAILURE;
  }

  double x1{};
  double x2{};

  uint8_t roots = equalation_solve(a, b, c, &x1, &x2);
  equalation_result_print(a, b, c, roots, x1, x2);

  return EXIT_SUCCESS;
}

/**
 * @brief This function creates an equalation with specific A,B,C coefficient
 *        Ax^2 + Bx + C = 0
 *
 * @param a        IO pointer to A coefficient
 * @param b        IO pointer to B coefficient
 * @param c        IO pointer to C coefficient
 * @return uint8_t SUCCESS - 1, FAILURE - 0
 */
uint8_t equalation_init(double *a, double *b, double *c) {
  if (!a || !b || !c) {
    return 0;
  }

  uint8_t status = 1;
  char name{'A'};
  const double LIM_MIN{2};
  const double LIM_MAX{255};
  const uint8_t INIT_ARRAY_SIZE{3};
  double *init_array[INIT_ARRAY_SIZE]{a, b, c};

  std::cout << "Init a, b, c coefficients for next equalation:" << std::endl;
  std::cout << "ax^2 + bx + c = 0" << std::endl;

  for (uint8_t i = 0; i < INIT_ARRAY_SIZE; i++) {
    std::cout << "Please enter number in range [" << LIM_MIN << ".." << LIM_MAX
              << "]" << std::endl;
    std::cout << name << "-->";
    std::cin >> *init_array[i];

    if ((*init_array[i] < LIM_MIN) || (*init_array[i] > LIM_MAX)) {
      std::cout << "You entered an incorrect number!" << std::endl;
      status = 0;
      break;
    }

    name++;
  }

  return status;
}

/**
 * @brief This function solves the square equalation like
 *        Ax^2 + Ax + A = 0
 *
 * @param a        A coefficient
 * @param b        B coefficient
 * @param c        C coefficient
 * @param x1       IO Poiter to 1st Root
 * @param x2       IO Poiter to 2d Root
 * @return uint8_t Result: 0 - no roots, 1 - one root, 2 - two roots (x1, x2)
 */
uint8_t equalation_solve(double a, double b, double c, double *x1, double *x2) {
  uint8_t status = 0;

  if (!a || !b || !c || !x1 || !x2) {
    return status;
  }

  const int POWER{2};
  const int MULTIPLIER{4};
  auto D = pow(b, POWER) - (MULTIPLIER * a * c);
  auto devider = POWER * a;

  if (D > 0) {
    status = 2;
    D = sqrt(D);
    *x1 = ((-b) - D) / devider;
    *x2 = ((-b) + D) / devider;
  } else if (D == 0) {
    status = 1;
    *x1 = (-b) / (POWER * a);
  }
  return status;
}

/**
 * @brief This function prints the answer for the square equalation
 *        Ax^2 + Ax + A = 0
 *
 * @param a         A coefficient
 * @param b         B coefficient
 * @param c         C coefficient
 * @param roots_num Quantity of roots
 * @param x1        1st Root
 * @param x2        2d Root
 */
void equalation_result_print(double a, double b, double c, uint8_t roots_num,
                             double x1, double x2) {
  std::cout << "Result is :" << std::endl;                    
  std::cout << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;

  if (roots_num == 2) {
    std::cout << "x1 = " << x1 << ";" << std::endl;
    std::cout << "x2 = " << x2 << ";" << std::endl;
  } else if (roots_num == 1) {
    std::cout << "x = " << x1 << ";" << std::endl;
  } else {
    std::cout << "equalation has no roots" << std::endl;
  }
}
