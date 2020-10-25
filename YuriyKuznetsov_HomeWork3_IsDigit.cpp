#include <iostream>

bool bIsDigit(const unsigned char cuchSymbol);

int main() {
  constexpr uint32_t cuiMAXCHAR{256};
  constexpr char ccENDOFSTRING{'\0'};
  unsigned char auchInBuffer[cuiMAXCHAR]{};

  std::cout << "Enter the string: ";
  std::cin >> auchInBuffer; // without any checking

  std::cout << "Digits: ";
  for (uint32_t uiCharIndex = 0; uiCharIndex < cuiMAXCHAR; ++uiCharIndex) {
    if (*(auchInBuffer + uiCharIndex) == ccENDOFSTRING) {
      break;
    }
    if (!bIsDigit(*(auchInBuffer + uiCharIndex))) {
      continue;
    }
    std::cout << *(auchInBuffer + uiCharIndex) << ' ';
  }
  return 0;
}

bool bIsDigit(const unsigned char cuchSymbol) {
  if ((cuchSymbol < '0') || (cuchSymbol > '9')) {
    return false;
  }
  return true;
}
