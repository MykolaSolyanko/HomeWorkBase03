#include <cstdint>
#include <cstdlib>
#include <iostream>

uint32_t value_digits_quantity(uint32_t value);
uint32_t value_summ_digits(uint32_t value);

int main() {
  uint32_t value{};

  std::cout << "Please, enter unsigned integer value" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  uint32_t quantity = value_digits_quantity(value);

  std::cout << "The value " << value << " consists of " << quantity << " digits"
            << std::endl;

  uint32_t summ = value_summ_digits(value);
  std::cout << "Summ of digits is " << summ << std::endl;

  auto average = static_cast<float>(summ) / quantity;
  std::cout << "The average is " << average << std::endl;
  
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
 * @brief This function calculates summ for given value
 * 
 * @param value     [input] Given value for calculation
 * @return uint32_t Summ
 */
uint32_t value_summ_digits(uint32_t value) {
  uint32_t summ = 0;

  for (; value; value /= 10) {
    summ += value % 10;
  }

  return summ;
}