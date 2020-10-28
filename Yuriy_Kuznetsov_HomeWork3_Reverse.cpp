//программа revers для строки
#include <iostream>

int main() {
  constexpr uint32_t cuiMAXCHAR{256};
  constexpr char ccENDOFSTRING{'\0'};
  constexpr uint32_t cuiHALF{2};
  char acBuffer[cuiMAXCHAR];

  std::cout << "Enter the string you want to reverse: ";
  std::cin >> acBuffer; // without any checking

  for (size_t uiCharIndex = 0; uiCharIndex < cuiMAXCHAR; ++uiCharIndex) {
    if (acBuffer[uiCharIndex] != ccENDOFSTRING) {
      continue;
    }
    for (size_t uiHelpIndex = 0; uiHelpIndex < (uiCharIndex / cuiHALF);
         ++uiHelpIndex) {
      char cTempSymbol{acBuffer[uiHelpIndex]};
      acBuffer[uiHelpIndex] = acBuffer[uiCharIndex - 1 - uiHelpIndex];
      acBuffer[uiCharIndex - 1 - uiHelpIndex] = cTempSymbol;

      /*      std::swap(acBuffer[uiHelpIndex],
                      acBuffer[uiCharIndex - 1 - uiHelpIndex]);
      */
    }
    break;
  }
  std::cout << "Reversed string: ";
  std::cout << acBuffer << '\n';

  return 0;
}
