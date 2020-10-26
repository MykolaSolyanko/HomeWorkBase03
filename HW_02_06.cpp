#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

bool is_odd(int value);
// bool draw_triangle(uint32_t value);

int main() {


}

/**
 * @brief         This function check value for odd condition
 *
 * @param value   value to process
 * @return true
 * @return false
 */
bool is_odd(int value) { return value & 1; }

bool draw_triangle(char (&triangle) [31] [31], uint8_t filling) {
  if (filling < 3) {
    return false;
  }

  filling = !is_odd(filling) ? ++filling : filling;
  
  return true;
}

// while (value>>=1) {
//   counter += (value & 1);
// }