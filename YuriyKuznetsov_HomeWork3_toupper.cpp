// Перевод символов в верхний регистр
#include <iostream>

char chGetHi(const unsigned char in_cuchSymbol);

int main() {
  constexpr uint32_t cuiMAXCHAR{256};
  constexpr char ccENDOFSTRING{'\0'};
  unsigned char auchInBuffer[cuiMAXCHAR]{};

  std::cout << "Enter the string: ";
  std::cin >> auchInBuffer; // without any checking

  for (uint32_t uiCharIndex = 0; uiCharIndex < cuiMAXCHAR; ++uiCharIndex) {
    if (*(auchInBuffer + uiCharIndex) == ccENDOFSTRING) {
      break;
    }
    *(auchInBuffer + uiCharIndex) = chGetHi(*(auchInBuffer + uiCharIndex));
  }
  std::cout << "To upper string: ";
  std::cout << auchInBuffer << '\n';

  return 0;
}

char chGetHi(const unsigned char in_cuchSymbol) {
  constexpr unsigned char cuchDIFFERENCE{
      0x20}; // difference between hi and low symbol in ASCII table
  if ((in_cuchSymbol < 'a') || (in_cuchSymbol > 'z')) {
    return in_cuchSymbol;
  }
  return (in_cuchSymbol - cuchDIFFERENCE);
}
