#include <iostream>

int main() {
  constexpr uint32_t cuiCOEF{2};
  uint32_t uiValue{};

  std::cout << "Enter unsigned integer value: ";
  std::cin >> uiValue; // without checking for correctness

  if (!(uiValue & 1)) {
    ++uiValue;
  }

  if (uiValue == 0) {
    std::cout << "Uncorrect value";
  }

  for (uint32_t uiRowIndex = 0; uiRowIndex <= (uiValue / 2); ++uiRowIndex) {
    for (uint32_t uiSpaceIndex = 0;
         uiSpaceIndex < ((uiValue / cuiCOEF) - uiRowIndex); ++uiSpaceIndex) {
      std::cout << ' ';
    }
    for (uint32_t uiStarIndex = 0; uiStarIndex < (uiRowIndex * cuiCOEF + 1);
         ++uiStarIndex) {
      std::cout << '*';
    }
    std::cout << "\n";
  }

  return 0;
}
