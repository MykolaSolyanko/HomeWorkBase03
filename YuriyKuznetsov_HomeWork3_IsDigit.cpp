//Проверить является ли введеный символ числом
#include <iostream>

bool bIsDigit(const unsigned char cuchSymbol);

int main() {
  constexpr size_t csizeMAXCHAR{256};
  constexpr char cchENDOFSTRING{'\0'};
  unsigned char auchInBuffer[csizeMAXCHAR]{};

  std::cout << "Enter the string for digits extracting: ";
  std::cin >> auchInBuffer; // without any checking

  std::cout << "Digits are: ";
  for (size_t sizeCharIndex = 0; sizeCharIndex < csizeMAXCHAR;
       ++sizeCharIndex) {
    if (*(auchInBuffer + sizeCharIndex) == cchENDOFSTRING) {
      break;
    }
    if (!bIsDigit(*(auchInBuffer + sizeCharIndex))) {
      continue;
    }
    std::cout << *(auchInBuffer + sizeCharIndex) << ' ';
  }
  std::cout << '\n';
  return 0;
}

bool bIsDigit(const unsigned char cuchSymbol) {
  return !((cuchSymbol < '0') || (cuchSymbol > '9'));
}
