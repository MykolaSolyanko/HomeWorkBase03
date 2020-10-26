#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

static uint32_t value_count_set_bits(uint32_t value);
static bool value_dec_2_bin(uint32_t value, char *string, uint32_t size);

int main() {
  uint32_t value{};
  constexpr uint32_t BIT_MASK_SIZE{sizeof(uint32_t) * 8};
  char BIT_MASK[BIT_MASK_SIZE]{};

  std::cout << "Input unsigned integer value:" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  if (!value_dec_2_bin(value, BIT_MASK, BIT_MASK_SIZE)) {
    return EXIT_FAILURE;
  }

  for (uint32_t i = 0; i < BIT_MASK_SIZE; i++) {
    if (((i % 4) == 0) && (i > 0)) {
      std::cout << '\'';
    }
    std::cout << BIT_MASK[i];
  }
  std::cout << std::endl;
  
  auto set_bist = value_count_set_bits(value);

  std::cout << set_bist << " bit is set." << std::endl;

  return EXIT_SUCCESS;
}

static uint32_t value_count_set_bits(uint32_t value) {
  uint32_t count{};

  while (value) {
    count += value & 1;
    value >>= 1;
  }

  return count;
}

static bool value_dec_2_bin(uint32_t value, char *string, uint32_t size) {
  if (string == nullptr) {
    return false;
  }

  for (uint32_t i = 0; i < size; i++){
    string[i] = '0';
  }

  while (value) {
    string[--size] = '0' + (value & 1);
    value >>= 1;
  }

  return true;
}