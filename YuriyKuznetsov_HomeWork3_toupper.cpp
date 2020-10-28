// Перевод символов в верхний регистр
#include <iostream>

char chGetHi(const unsigned char in_cuchSymbol);

int main() {
  constexpr size_t csizeMAXCHAR{256};
  constexpr char cchENDOFSTRING{'\0'};
  unsigned char auchInBuffer[csizeMAXCHAR]{};

  std::cout << "Enter the string to convert to uppercase: ";
  std::cin >> auchInBuffer; // without any checking

  for (size_t sizeCharIndex = 0; sizeCharIndex < csizeMAXCHAR;
       ++sizeCharIndex) {
    if (*(auchInBuffer + sizeCharIndex) == cchENDOFSTRING) {
      break;
    }
    *(auchInBuffer + sizeCharIndex) = chGetHi(*(auchInBuffer + sizeCharIndex));
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
