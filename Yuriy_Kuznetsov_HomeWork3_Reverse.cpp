#include <iostream>
#include <string>

void vReverseAsString() {
  std::cout << "Enter the string: ";
  std::string sInData{};
  std::getline(std::cin, sInData);
  std::cout << "Reversed string: ";
  for (auto p = sInData.rbegin(); p < sInData.rend(); ++p) {
    std::cout << *p;
  }
}

void vReverseAsCharString() {
  constexpr uint32_t cuiMAXCHAR{256};
  constexpr char ccENDOFSTRING{'\0'};
  constexpr uint32_t cuiHALF{2};
  char acInBuffer[cuiMAXCHAR];

  std::cout << "Enter the string: ";
  std::cin >> acInBuffer; // without any checking

  for (uint32_t uiCharIndex = 0; uiCharIndex < cuiMAXCHAR; ++uiCharIndex) {
    if (acInBuffer[uiCharIndex] != ccENDOFSTRING) {
      continue;
    }
    for (uint32_t uiHelpIndex = 0; uiHelpIndex < (uiCharIndex / cuiHALF);
         ++uiHelpIndex) {
      std::swap(acInBuffer[uiHelpIndex],
                acInBuffer[uiCharIndex - 1 - uiHelpIndex]);
    }
    break;
  }
  std::cout << "Reversed string: ";
  std::cout << acInBuffer << '\n';
}

int main() {
  vReverseAsString();

  vReverseAsCharString();

  return 0;
}
