// Сумма нечетных элементов
#include <array>
#include <iostream>
#include <limits>

bool bGetTotal(uint32_t &out_uiTotal, const uint32_t cuiMYMINSIZE,
               const uint32_t cuiMYMAXSIZE) {
  uint32_t uiTempTotal{};

  std::cout << "Enter the total number of elements [" << cuiMYMINSIZE << "..."
            << cuiMYMAXSIZE << "]:";

  if (!(std::cin >> uiTempTotal)) {
    std::cout << "Uncorrect total!";
    return false;
  }

  if ((uiTempTotal < cuiMYMINSIZE) || (uiTempTotal > cuiMYMAXSIZE)) {
    std::cout << "Total is not in range!";
    return false;
  }

  out_uiTotal = uiTempTotal;
  return true;
}

bool bGetValue(int32_t &out_iValue, const int32_t ciMYMINVALUE,
               const int32_t ciMYMAXVALUE) {
  int32_t iTempValue{};

  std::cout << "Enter current value in range [" << ciMYMINVALUE << "..."
            << ciMYMAXVALUE << "]:";

  if (!(std::cin >> iTempValue)) {
    std::cout << "Uncorrect value!";
    return false;
  }

  if ((iTempValue < ciMYMINVALUE) || (iTempValue > ciMYMAXVALUE)) {
    std::cout << "Value is not in range!";
    return false;
  }

  out_iValue = iTempValue;
  return true;
}

bool bIsOdd(int32_t iValue) {
  if (iValue & 1) {
    return true;
  }
  return false;
}

bool bSumIsOutOfRange(const int32_t ciSum, const int32_t ciValue) {
  if ((ciSum > 0) && (ciValue > 0)) {
    if (ciSum > (std::numeric_limits<int32_t>::max() - ciValue)) {
      std::cout << "Sum is out of range (>max)";
      return true;
    }
  }
  if ((ciSum < 0) && (ciValue < 0)) {
    if (ciSum < (std::numeric_limits<int32_t>::min() - ciValue)) {
      std::cout << "Sum is out of range (<min)";
      return true;
    }
  }
  return false;
}

int main() {
  constexpr uint32_t cuiMINSIZE{1};
  constexpr uint32_t cuiMAXSIZE{50};
  constexpr int32_t ciMINVALUE{-60};
  constexpr int32_t ciMAXVALUE{90};

  uint32_t iTotal{0};
  if (!bGetTotal(iTotal, cuiMINSIZE, cuiMAXSIZE)) {
    return -1;
  }

  std::array<int32_t, cuiMAXSIZE> aiOddValues =
      {}; // использую статический array, чтоб попробовать. Хотя уместнее,
          // думаю, использовать вектор
  uint32_t uiArrayIndex{};
  int32_t iSum{};
  for (uint32_t uiIndex = 0; uiIndex < iTotal; ++uiIndex) {
    int32_t iTempValue{};
    if (!bGetValue(iTempValue, ciMINVALUE, ciMAXVALUE)) {
      return -1;
    }

    if (!bIsOdd(iTempValue)) {
      continue;
    }

    try {
      aiOddValues.at(uiArrayIndex) = iTempValue;
    } catch (std::out_of_range) {
      std::cout << "Array is out of range";
      return -1;
    } catch (...) {
      std::cout << "Something happened with array";
      return -1;
    }

    if (bSumIsOutOfRange(iSum, iTempValue)) {
      return -1;
    }
    iSum += iTempValue;
    ++uiArrayIndex;
  }

  std::cout << iSum << " ---> ";
  for (uint32_t uiIndex = 0; uiIndex < uiArrayIndex; ++uiIndex) {
    std::cout << aiOddValues[uiIndex];
    if (uiIndex == (uiArrayIndex - 1)) {
      std::cout << " = " << iSum << "\n";
    } else {
      std::cout << " + ";
    }
  }
  return 0;
}
