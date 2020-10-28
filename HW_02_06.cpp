#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>

inline static bool is_even(int value);

int main() {
  constexpr uint32_t MATRIX_SIZE_MAX{64};
  constexpr uint32_t MATRIX_SIZE_MIN{2};
  constexpr uint32_t EVEN_PADDING{3};
  constexpr uint32_t ODD_PADDING{2};
  
  char object[MATRIX_SIZE_MAX];
  uint32_t value{};

  std::cout
      << "To draw an isosceles triangle, set its side as an unsigned value:"
      << std::endl;
  std::cout << "Hint: the value has to be in range [" << MATRIX_SIZE_MIN
            << " ... " << MATRIX_SIZE_MAX << "]" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  if ((value < MATRIX_SIZE_MIN) || (value > MATRIX_SIZE_MAX - EVEN_PADDING)) {
    return EXIT_FAILURE;
  }

  value += is_even(value) ? EVEN_PADDING : ODD_PADDING;

  /*Filling the array space character*/
  for (uint32_t i = 0; i < value; i++) {
    object[i] = ' ';
  }

  /*In this loop draws triangle from top to bottom*/
  for (uint32_t swipe = value / 2; swipe != 0; swipe--) {

    /*drawing triangle row*/
    for (uint32_t j = swipe; j < (value - swipe); j++) {
      object[j] = '*';
    }
    /*Set NULL termitaned character to init string*/
    object[value - swipe] = '\0';

    /*Just print this string*/
    std::cout << object << std::endl;
  }

  return EXIT_SUCCESS;
}

/**
 * @brief         This function check value for even condition
 *
 * @param value   value to process
 * @return true
 * @return false
 */
inline bool is_even(int value) { return (value % 2 == 0); }