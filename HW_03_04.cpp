#include <cstdlib>
#include <iostream>

static bool to_upper(char *string);

int main() {
  constexpr size_t MAX_LENGHT{64};
  char string[MAX_LENGHT]{};
  std::cin >> string;
  to_upper(string);
  std::cout << string << std::endl;
  return EXIT_SUCCESS;
}

static bool to_upper(char *string) {

  if (string == nullptr) {

    return false;
  }
  constexpr char LOW_CASE_FLAG{0x60};
  constexpr char UP_CASE_FLAG{0x40};
  size_t i = 0;
  while (string[i] != '\0') {

    if (string[i] & LOW_CASE_FLAG) {

      string[i] &= ~LOW_CASE_FLAG;
      string[i] |= UP_CASE_FLAG;
    }
    i++;
  }
  return true;
}