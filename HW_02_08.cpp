#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>

static inline bool bit_is_set(uint32_t value, uint32_t bit) ;

int main() {
  uint32_t value{};
  std::cout << "Input unsigned integer value:" << std::endl;
  std::cout << "-->";
  std::cin >> value;

  uint32_t bit{};
  std::cout << "Input bit's number to check is set:" << std::endl;
  std::cout << "-->";
  std::cin >> bit;

  if (bit < 0) {
    std::cout << "ERROR: Incorrect entry" << std::endl;
    return EXIT_FAILURE;
  }

  const char* response =  bit_is_set(value, bit) ? "Yes" : "No";
  std::cout << response << std::endl;

  return EXIT_SUCCESS;
}

static inline bool bit_is_set(uint32_t value, uint32_t bit) {
  if(bit == 0) {
    return false;
  }

  return value & (1 << --bit);
}