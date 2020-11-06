#include <cstdlib>
#include <iostream>

static bool string_to_lower(char *string);

int main() {
  constexpr size_t MAX_LENGHT{64};
  char string[MAX_LENGHT]{};
  std::cin >> string;
  string_to_lower(string);
  std::cout << string << std::endl;

  return EXIT_SUCCESS;
}

static inline char to_lower(char letter) {

  constexpr char LOW_CASE_FLAG{0x60};
  constexpr char UP_CASE_FLAG{0x40};

  return letter & UP_CASE_FLAG ? (letter & ~UP_CASE_FLAG) | LOW_CASE_FLAG
                               : letter;
}

static bool string_to_lower(char *string) {

  if (string == nullptr) {

    return false;
  }
  size_t i = 0;
  while (*(string + i) != '\0') {

    *(string + i) = to_lower(*(string + i));
    i++;
  }

  return true;
}