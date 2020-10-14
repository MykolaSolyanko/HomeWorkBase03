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
}

uint32_t value_digits_quantity(uint32_t value) {
  uint32_t quantity = 1;
  
  while (value /= 10) {
    ++quantity;
  }

  return quantity;
}

uint32_t value_summ_digits(uint32_t value) {
  uint32_t average = 0;

  for (; value; value /= 10) {
    average += value % 10;
  }

  return average;
}