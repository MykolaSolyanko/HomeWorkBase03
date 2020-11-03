#include <bits/stdint-uintn.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>

bool array_init_sorted(uint32_t new_member, uint32_t *array, size_t size);
void array_print(const uint32_t *array, size_t size);

int main() {
  constexpr size_t MAX_SIZE{32};
  uint32_t array[MAX_SIZE]{};
  size_t selected_size{};

  std::cout << "Enter an array size" << std::endl;
  std::cout << "HINT: value must be in range [1 .. " << MAX_SIZE << "]"
            << std::endl;
  std::cin >> selected_size;

  if (selected_size == 0) {
    std::cout << "Incorrect the array size" << std::endl;
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < selected_size; i++) {
    uint32_t temp{};
    const auto NEW_SIZE{i + 1};
    std::cout << "Enter " << NEW_SIZE << " value --> ";
    std::cin >> temp;
    std::cout << std::endl;

    if (!array_init_sorted(temp, array, NEW_SIZE)) {
      std::cout << "Incorrect _array_init_sorted_ call" << std::endl;
      return EXIT_FAILURE;
    }

    array_print(array, NEW_SIZE);
  }

  return EXIT_SUCCESS;
}
 
/**
 * @brief This function adds new digit into an array and then sorts it
 * 
 * @param new_member     [input]        New value that will added into the array
 * @param array          [input/output] Pointer to the array to process
 * @param size           [input]        Size of the array
 * @return true 
 * @return false 
 */
bool array_init_sorted(uint32_t new_member, uint32_t *array, size_t size) {

  if ((array == nullptr) || (size == 0)) {
    return false;
  }

  uint32_t i = size - 1;
  array[i] = new_member;

  while ((i != 0) && (array[i - 1] > array[i])) {
    auto temp{array[i]};
    array[i] = array[i - 1];
    array[i - 1] = temp;
    i--;
  }

  return true;
}

/**
 * @brief This function prints an array
 * 
 * @param array    [input] Pointer to the array to print
 * @param size     [input] Array's size
 */
void array_print(const uint32_t *array, size_t size) {
  if ((array == nullptr) || (size == 0)) {
    return;
  }

  for (size_t j = 0; j < size; j++) {
    std::cout << array[j] << '\t';
  }
  std::cout << std::endl;
}