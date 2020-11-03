#include <cstdlib>
#include <ctime>
#include <iostream>

int main() 
{
  constexpr size_t MAX_SIZE{64};
  uint32_t array[MAX_SIZE]{};
  size_t selected_size{};

  std::cout << "Input array size in range [1 ... " << MAX_SIZE << " ]"
            << std::endl;
  std::cin >> selected_size;

  if (selected_size == 0) {
    std::cout << "Incorrect input size" << std::endl;
    return EXIT_FAILURE;
  }

  uint32_t RANGE_MIN{};
  uint32_t RANGE_MAX{};

  std::cout << "Enter minimal and maximal range for random generator"
            << std::endl;
  std::cout << "MIN --> ";
  std::cin >> RANGE_MIN;
  std::cout << "MAX --> ";
  std::cin >> RANGE_MAX;

  if (RANGE_MIN > RANGE_MAX) {
    std::cout << "Incorrect input range parameters" << std::endl;
    return EXIT_FAILURE;
  }

  std::srand(std::time(nullptr)); // use current time as seed for random generator

  for (int i = 0; i < selected_size; i++) {
    array[i] = RANGE_MIN + std::rand() / ((RAND_MAX + 1u) / RANGE_MAX);
    std::cout << array[i] << '\t';
  }
  std::cout << std::endl;
}