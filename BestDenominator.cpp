// Лучший делитель
#include <iostream>
#include <limits>

uint32_t iGetValue() {
  uint32_t iValue{};
  std::cout << "Enter unsigned integer value: ";
  std::cin >> iValue; // without checking for correctness
  return iValue;
}

uint32_t iCalcBestDenom(const uint32_t ciValue) {
  constexpr uint32_t ciKOEF_MULTI{10}; // must be > 0
  uint32_t iBestValue{};
  uint32_t iMaxSum{};

  for (uint32_t iIndex = 1; iIndex <= ciValue; ++iIndex) {
    if (ciValue % iIndex) {
      continue;
    }

    uint32_t iTempValue{iIndex};
    uint32_t iTempValueZeroEnd{};
    uint32_t iDigit{};
    uint32_t iCurrentSum{};

    while (iTempValue != 0) {
      iTempValueZeroEnd = (iTempValue / ciKOEF_MULTI) * ciKOEF_MULTI;
      iDigit = iTempValue - (iTempValueZeroEnd);
      if (iCurrentSum > (std::numeric_limits<std::uint32_t>::max() - iDigit)) {
        std::cout << "The sum is overlimit\n";
        return 0;
      }
      iCurrentSum += iDigit;
      iTempValue /= ciKOEF_MULTI;
    }
    if (iMaxSum >= iCurrentSum) {
      continue;
    }
    iMaxSum = iCurrentSum;
    iBestValue = iIndex;
  }
  return iBestValue;
}

int main() {
  uint32_t iInValue{iGetValue()};

  std::cout << "The best denominator is: " << iCalcBestDenom(iInValue) << "\n";

  return 0;
}
