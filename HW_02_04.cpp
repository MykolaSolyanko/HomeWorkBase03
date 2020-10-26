#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

constexpr int MAX_ARRAY_SIZE{50};
constexpr int MIN_ARRAY_SIZE{1};

bool is_odd(int value);
int array_sum(const int (&array)[MAX_ARRAY_SIZE], uint32_t size);
bool array_odd_init(int (&array)[MAX_ARRAY_SIZE], uint32_t &new_size,
                    uint32_t quantity);

int main() {
  int array[MAX_ARRAY_SIZE]{};
  uint32_t array_size{};
  uint32_t entries{};

  std::cout << "Enter the quantity of entries to process:" << std::endl;
  std::cout << "Hint: Value should be in range [" << MIN_ARRAY_SIZE << "..."
            << MAX_ARRAY_SIZE << "]" << std::endl;
  std::cout << "-->";
  std::cin >> entries;

  if ((entries < MIN_ARRAY_SIZE) || (entries > MAX_ARRAY_SIZE)) {
    std::cout << "ERROR: Incorrect entry" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Input" << std::endl;
  if (!array_odd_init(array, array_size, entries)) {
    return EXIT_FAILURE;
  }

  int sum{array_sum(array, array_size)};

  std::cout << sum << " --> " << array[0];

  for (uint32_t i = 1; i < array_size; i++) {
    std::cout << " + ";
    std::cout << array[i];
  }

  std::cout << " = " << sum << std::endl;

  return EXIT_SUCCESS;
}

/**
 * @brief         This function check value for odd condition
 *
 * @param value   value to process
 * @return true
 * @return false
 */
bool is_odd(int value) { return value & 1; }

/**
 * @brief This function writes only odd numbers into array
 *
 * @param array      [input/output] Array of references to process
 * @param new_size   [input/output] Refferense to variable that stores quantity
 * of odd numbers
 * @param quantity                  Quantity of entries
 * @return true
 * @return false
 */
bool array_odd_init(int (&array)[MAX_ARRAY_SIZE], uint32_t &new_size,
                    uint32_t quantity) {
  if (quantity == 0) {
    return false;
  }

  constexpr int LIM_MIN{-60};
  constexpr int LIM_MAX{90};

  new_size = 0;

  for (uint32_t i = 0; i < quantity; i++) {
    std::cin >> array[new_size];

    if ((array[new_size] < LIM_MIN) || (array[new_size] > LIM_MAX) ||
        !is_odd(array[new_size])) {
      continue;
    }
    new_size++;
  }

  return new_size;
}

int array_sum(const int (&array)[MAX_ARRAY_SIZE], uint32_t size) {
  if (size == 0) {
    return 0;
  }

  int sum{};

  while (size--) {
    sum += array[size];
  }

  return sum;
}