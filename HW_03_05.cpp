#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>

static bool is_digit(char digit);

int main() {

  constexpr size_t MAX_LENGHT{64};
  char string[MAX_LENGHT]{};
  std::cin >> string;
  bool parse_flag = false;
  size_t i = 0;
  while(*(string + i) != '\0') {

    if(is_digit(*(string + i))){
      
      if(!parse_flag) {

        parse_flag = true;
        std::cout << "Digit is :\t";
      }
      std::cout << *(string + i) << "\t";
    }
    i++;
  }
  if(!parse_flag) {
    
    std::cout << "The string has no any digits" << std::endl;
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

static bool is_digit(char digit) {

  constexpr char DIGIT_FLAG{0x30};
  return (digit & DIGIT_FLAG) == DIGIT_FLAG;
}