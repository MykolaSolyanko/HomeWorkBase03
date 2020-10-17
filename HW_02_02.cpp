#include <bits/c++config.h>
#include <bits/stdint-uintn.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <math.h>

/**
 * @brief This constant sets quantity of digits of ticket number that was entered by user
 * 
 */
constexpr uint32_t ALLOWWED_TICKET_DIGITS_QUANTITY{6};

/**
 * @brief This constant defines a halves of ticket's nimber to check that ticket is lucky
 * 
 */
constexpr uint32_t TICKET_PART_TO_COMPARE{ALLOWWED_TICKET_DIGITS_QUANTITY / 2};

uint32_t value_digits_quantity(uint32_t value);
bool     value_summ_n_digits  (uint32_t value, uint32_t quantity, uint32_t *summ);
bool     value_skip_n_digits  (uint32_t* value, uint32_t n);

int main() {

  uint32_t value{};

  std::cout << "Please, enter unsigned integer value" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  uint32_t quantity = value_digits_quantity(value);

  std::cout << "The value " << value << " consists of " << quantity << " digits"
            << std::endl;

  if (quantity != ALLOWWED_TICKET_DIGITS_QUANTITY) {
    std::cout << "Value have to consist " << ALLOWWED_TICKET_DIGITS_QUANTITY << " digits!"
              << std::endl;
    return EXIT_FAILURE;
  }

  uint32_t part1{};
  uint32_t part2{};

  value_summ_n_digits(value, TICKET_PART_TO_COMPARE, &part1);
  std::cout<< "part1: " << part1 << std::endl;
  value_skip_n_digits(&value, TICKET_PART_TO_COMPARE);
  std::cout<< "value: " << value << std::endl;
  value_summ_n_digits(value, TICKET_PART_TO_COMPARE, &part2);
  std::cout<< "part2: " << part2 << std::endl;

  /*Checking for ticket's lucky*/
  if (part1 == part2) {
    std::cout<< "My congratulations, You have got a lucky ticket!"<< std::endl;
  } else {
    std::cout<< "No big deal, no luck with this ticket."<< std::endl;
  }

  return EXIT_SUCCESS;
}

/**
 * @brief This function returns quantity of digits for given value
 * 
 * @param value     [input] Value for calculation
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
 * @brief This function calculates summ of first n digits for given value
 * 
 * @param value     [input] Value for calculation
 * @param quantity  [input] Quantity of digits for addition
 * @param summ      [input/output] Pointer to variable, where summ will be written
 * @return true 
 * @return false  
 */
bool value_summ_n_digits(uint32_t value, uint32_t quantity, uint32_t *summ) {

  if (!summ || (value_digits_quantity(value) < quantity)) {
    return 0;
  }

  *summ = 0;

  while (quantity--) {
    *summ += value % 10;
    value /= 10;
  }

  return 1;
}

/**
 * @brief This function trimms n first digits for given value
 * 
 * @param value    [input/output] pointer to variable for trimming
 * @param n        [input] Number of first digits that will deleted from value 
 * @return true 
 * @return false 
 */
bool value_skip_n_digits (uint32_t* value, uint32_t n) {
  if(!value) {
      return 0;
  }

  *value/=pow(10, n);

  return 1;
}