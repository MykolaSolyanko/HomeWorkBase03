#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

uint32_t value_digits_quantity(uint32_t value);
bool value_trim_the_last_digit(uint32_t *const value);
uint32_t value_get_the_last_digit(uint32_t value);

int value_reverce(int value);

int main() {

  int value{};

  std::cout << "Please, enter integer value" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  int reverse = value_reverce(value);

  std::cout << "Reverse value is " << reverse << std::endl;

  return EXIT_SUCCESS;
}

/**
 * @brief This function returns quantity of digits for given value
 *
 * @param value     Input value for calculation
 * @return uint32_t Quantity of digits
 */
uint32_t value_digits_quantity(uint32_t value) {
  uint32_t quantity = 1;

  while (value /= 10) {
    ++quantity;
  }

  return quantity;
}

/**
 * @brief This function returns the last digit for given value
 *
 * @param value     [input] Value for calculation
 * @return uint32_t The last digit
 */
uint32_t value_get_the_last_digit(uint32_t value) { return (value % 10); }

/**
 * @brief This function trims the last digit for given number
 *
 * @param value [input/output] Pointer to external variable
 * @return true
 * @return false
 */
bool value_trim_the_last_digit(uint32_t *const value) {
  if (!value) {
    return false;
  }

  *value /= 10;

  return true;
}

/**
 * @brief This function changes the order of given number
 *
 * @param value     [input] Number for calculation
 * @param order     [input] New order for given number
 * @return uint32_t  Number with changed order
 */
uint32_t value_change_order(uint32_t value, uint32_t order) {
  return static_cast<uint32_t>(value * pow(10, order));
}

/**
 * @brief This function returns value with reverse digits order
 *
 * @param value Value for calculation
 * @return int  Reverse value
 */
int value_reverce(int value) {
  int reverse = 0;
  bool is_signed = (value < 0);
  // std::cout << "log: is signed = "<< is_signed << std::endl;

  uint32_t abs_value = static_cast<uint32_t>(abs(value));
  // std::cout << "log: abs = "<< abs_value << std::endl;

  uint32_t value_order = value_digits_quantity(abs_value);
  // std::cout << "log: order = "<< value_order << std::endl;
  // std::cout << "---------------"<< std::endl;

  while (abs_value) {
    auto last_digit = value_get_the_last_digit(abs_value);
    // std::cout << "log: the last is = "<< last_digit << std::endl;

    reverse += value_change_order(last_digit, --value_order);
    // std::cout << "log: reverse = "<< reverse << std::endl;

    value_trim_the_last_digit(&abs_value);
    // std::cout << "log: abs = "<< abs_value << std::endl;
    // std::cout << "---------------"<< std::endl;
  }

  return is_signed ? -reverse : reverse;
}