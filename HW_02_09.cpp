#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>

static uint32_t value_digits_quantity(uint32_t value);
static uint64_t value_change_order (uint32_t value, uint32_t order);

int main() {
  constexpr uint32_t MAX_ARRAY_SIZE{10};
  uint32_t array[MAX_ARRAY_SIZE]{};
  uint32_t value{};

  std::cout << "Please, enter number of values to process" << std::endl;
  std::cout << "Hint: The value must be int range [1..." << MAX_ARRAY_SIZE
            << "]" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  if ((value == 0) || (value > MAX_ARRAY_SIZE)) {
    return EXIT_FAILURE;
  }

  uint64_t summ_check{};

  for (size_t i = 0; i < value; i++) {
    std::cout << "Enter " << i + 1 << " value: ";
    std::cin >> array[i];
    std::cout << std::endl;

    summ_check += array[i];
  }

  /*Сheck for the possibility of building a number*/
  if ((summ_check % 3) != 0) {
    std::cout << "NO" << std::endl;
    return EXIT_FAILURE;
  }

  uint64_t calc_value_order{};
  uint64_t calc_value{};

  /*Calculatу order for new value*/
  for (size_t i = 0; i < value; i++) {
    calc_value_order += value_digits_quantity(array[i]);
  }

  while(true) {
    bool flag{false};

    for (size_t i = 0; i < value; i++) {

      if (array[i] != 0) {
        flag = true;
        const auto __order = value_digits_quantity(array[i]) - 1;
        const auto __trim = value_change_order(1, __order);
        auto __value = array[i];
        
        if (__order != 0) {
          /*Skip last n digits*/
          __value /= __trim;
        }
        /*Get the last digit*/
        __value %= 10;
  
        calc_value += value_change_order(__value, --calc_value_order);
        array[i] -= __value * __trim;
      }
    }

    if (flag == false) {
      break;
    }
  }

  std::cout << "YES" << std::endl;
  std::cout << "Calculated value is --> " << calc_value << std::endl;

  return EXIT_SUCCESS;
}

/**
 * @brief This function returns quantity of digits for given value
 *
 * @param value     [input] Value for calculation
 * @return uint32_t Quantity of digits
 */
static uint32_t value_digits_quantity(uint32_t value) {
  uint32_t quantity = 1;

  while (value /= 10) {
    ++quantity;
  }

  return quantity;
}

/**
 * @brief This function return value with new order
 * 
 * @param value     Value to process
 * @param order     Value's order that will return
 * @return uint64_t 
 */
static uint64_t value_change_order (uint32_t value, uint32_t order) {
  return static_cast<uint64_t>(value * pow(10, order));
}
