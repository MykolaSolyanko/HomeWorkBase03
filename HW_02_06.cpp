#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

/**
 * @brief Limitations on triangle sizes
 * 
 */
static constexpr uint32_t MATRIX_SIZE_MAX{41};
static constexpr uint32_t MATRIX_SIZE_MIN{2};

typedef uint8_t matrix_t[MATRIX_SIZE_MAX];

/**
 * @brief Space character ASCII code ( hex )
 * 
 */
#define SPACE ((uint8_t)0x20)

inline static bool is_odd(int value);
static bool triangle_init(uint32_t *const width, uint32_t *const height);
static bool triangle_draw(matrix_t *triangle, uint32_t width, uint32_t height);

int main() {

  matrix_t object[MATRIX_SIZE_MAX]{};
  uint32_t width{};
  uint32_t height{};

  std::cout << "To draw an isosceles triangle, set its side as an unsigned value:" << std::endl;
  std::cout << "Hint: the value has to be in range [" << MATRIX_SIZE_MIN << " ... " << MATRIX_SIZE_MAX << "]" << std::endl;
  std::cout << "-->";
  std::cin >> width;

  if (!triangle_init(&width, &height)) {
    std::cout << "ERROR: Input value is not correct" << std::endl;
    return EXIT_FAILURE;
  }

  triangle_draw(object, width, height);

  for (uint32_t i = 0; i < height; i++) {
    for (uint32_t j = 0; j < width; j++) {
      std::cout << object[i][j];
    }
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}

/**
 * @brief         This function check value for odd condition
 *
 * @param value   value to process
 * @return true
 * @return false
 */
inline bool is_odd(int value) { return value & 1; }

/**
 * @brief          The function calculates the dimensions of the matrix required to draw the triangle
 * 
 * @param width    [input/output]  pointer to width propery
 * @param height   [input/output]  pointer to calculate height propery
 * @return true 
 * @return false 
 */
static bool triangle_init(uint32_t *const width, uint32_t *const height) {

  if ((*width < MATRIX_SIZE_MIN) || (*width > MATRIX_SIZE_MAX)) {
    return false;
  }

  /*If side value is even - add 1 to align triangle*/
  if (!is_odd(*width)) {
    (*width)++;
  }

  /*Calculating*/
  uint32_t temp = *width;
  *height = MATRIX_SIZE_MIN;

  do {
    (*height)++;
    temp -= 2;
  } while (temp != 1);

  return true;
}

/**
 * @brief             This function draws the triangle       
 * 
 * @param triangle    [input/output] pointer to matrix where triangle will be driven
 * @param width                      matrix width
 * @param height                     matrix heigth
 * @return true 
 * @return false 
 */
static bool triangle_draw(matrix_t *triangle, uint32_t width, uint32_t height) {

  if ((triangle == nullptr) || (width == 0) || (height == 0)) {
    return false;
  }

  /*filling array the space characters*/
  for (uint32_t i = 0; i < height; i++) {
    for (uint32_t j = 0; j < width; j++) {
      triangle[i][j] = SPACE;
    }
  }

  /*Drawing the triangle*/
  uint32_t swipe{};

  while (--height) {
    for (uint32_t col = swipe; col < (width - swipe); col++) {
      triangle[height][col] = '*';
    }
    swipe++;
  }

  return true;
}