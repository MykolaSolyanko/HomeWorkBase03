#include <bits/stdint-uintn.h>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

static bool array_remove_range(uint32_t *array, size_t *const size,
                               uint32_t MIN, uint32_t MAX);
static bool array_print(const uint32_t *array, size_t size);
static bool array_init_rand(uint32_t *array, size_t size, uint32_t MIN,
                            uint32_t MAX);
static bool param_init_safety(const char *annotation, uint32_t *const param);
static bool param_init_safety(const char *annotation, size_t *const param);

int main() {

  constexpr size_t MAX_SIZE{64};
  uint32_t array[MAX_SIZE]{};
  size_t selected_size{};
  std::cout << "Input an array size in range [1 ... " << MAX_SIZE << " ]"
            << std::endl;
  param_init_safety("Array size -->", &selected_size);
  if (selected_size == 0) {

    std::cout << "Incorrect input the array's size" << std::endl;
    return EXIT_FAILURE;
  }
  uint32_t RANGE_MIN{};
  uint32_t RANGE_MAX{};
  std::cout << "Enter minimal and maximal range to init the array" << std::endl;
  param_init_safety("MIN -->", &RANGE_MIN);
  param_init_safety("MAX -->", &RANGE_MAX);
  array_init_rand(array, selected_size, RANGE_MIN, RANGE_MAX);
  do {

    std::cout << "Array's size is --> " << selected_size << std::endl;
    array_print(array, selected_size);
    std::cout << "Enter range to cleanup in the array" << std::endl;
    param_init_safety("MIN -->", &RANGE_MIN);
    param_init_safety("MAX -->", &RANGE_MAX);
  } while (array_remove_range(array, &selected_size, RANGE_MIN, RANGE_MAX));

  return EXIT_SUCCESS;
}

static bool array_remove_cell(uint32_t *array, size_t *const size,
                              size_t cell) {

  if ((array == nullptr) || (size == nullptr) || (*size == 0) ||
      (cell > *size)) {

    return false;
  }
  (*size)--;
  for (size_t j = cell; j < *size; j++) {

    auto temp{array[cell]};
    array[cell] = array[cell + 1];
    array[cell + 1] = temp;
  }
  return true;
}

static bool array_remove_range(uint32_t *array, size_t *const size,
                               uint32_t MIN, uint32_t MAX) {

  if ((array == nullptr) || (size == nullptr)) {

    return false;
  }

  size_t i = 0;
  while (i < *size) {

    if ((MIN <= array[i]) && (MAX >= array[i])) {
      std::cout << "IN RANGE! ";
      std::cout << MIN << " <= " << array[i] << " && " << MAX
                << " >= " << array[i] << std::endl;
      array_remove_cell(array, size, i);
    } else {

      i++;
    }
  }
  return (*size != 0);
}

static bool array_print(const uint32_t *array, size_t size) {

  if ((array == nullptr) || (size == 0)) {

    return false;
  }

  for (size_t i = 0; i < size; i++) {

    std::cout << array[i] << '\t';
  }
  std::cout << std::endl;

  return true;
}

static bool array_init_rand(uint32_t *array, size_t size, uint32_t MIN,
                            uint32_t MAX) {

  if ((array == nullptr) || (size == 0)) {

    return false;
  }

  std::srand(
      std::time(nullptr)); // use current time as seed for random generator

  for (int i = 0; i < size; i++) {

    array[i] = MIN + std::rand() / ((RAND_MAX + 1u) / MAX);
  }

  return true;
}

static bool param_init_safety(const char *annotation, uint32_t *const param) {

  if ((param == nullptr) || (annotation == nullptr)) {

    return false;
  }

  while (true) {

    std::cout << annotation;
    std::cin >> *param;
    if (!std::cin.fail()) {

      return true;
    }
    std::cin.clear();
    std::cin.ignore();
  }
}

static bool param_init_safety(const char *annotation, size_t *const param) {

  if ((param == nullptr) || (annotation == nullptr)) {

    return false;
  }

  while (true) {

    std::cout << annotation;
    std::cin >> *param;
    std::cout << std::endl;
    if (!std::cin.fail()) {

      return true;
    }
    std::cin.clear();
    std::cin.ignore();
  }
}