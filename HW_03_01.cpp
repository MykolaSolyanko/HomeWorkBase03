#include "cstring"
#include <bits/stdint-uintn.h>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

static bool string_reverse(char *string, size_t len);

int main() {
  constexpr uint32_t MAX_SIZE{20};
  char str_array[MAX_SIZE]{};

  std::cout << "Input string:" << std::endl;
  std::cin >> str_array;
  size_t str_size = strlen(str_array);

  if (!string_reverse(str_array, str_size)) {
    return EXIT_FAILURE;
  }

  std::cout << str_array << std::endl;

  return EXIT_SUCCESS;
}

static bool string_reverse(char *string, size_t len) {
  if ((string == NULL) || (len == 0)) {
    return false;
  }
  
  const auto change = len / 2;

  for (size_t i = 0, j = len - 1; i != change; i++, j--) {
    char temp{string[i]};
    string[i] = string[j];
    string[j] = temp;
  }

  return true;
}