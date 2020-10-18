// Количество установленных бит в числе
#include <bitset>
#include <cstring>
#include <iostream>

constexpr char cZeroSymbol{'0'};
constexpr char cOneSymbol{'1'};

uint32_t uiGetValue() {
  uint32_t uiValue{};
  std::cout << "Enter unsigned integer value: ";
  std::cin >> uiValue; // without checking for correctness
  return uiValue;
}

uint32_t uiGetSum(uint32_t ui_inValue, char *pBits, const uint32_t cuiSize) {

  std::memset(pBits, cZeroSymbol, cuiSize);
  uint32_t uiBitSum{};
  uint32_t uiBitCount{};
  while (ui_inValue) {
    ++uiBitCount;
    if (ui_inValue & 1) {
      pBits[cuiSize - uiBitCount] = cOneSymbol;
      ++uiBitSum;
    }
    ui_inValue >>= 1;
  }
  return uiBitSum;
}

void vPrintRes(uint32_t ui_inValue, uint32_t ui_inPosBitTotal, char *pBits,
               const uint32_t cuiSize) {
  constexpr uint32_t cuiSymbInGroup{4};
  std::cout << ui_inValue << " ---> ";
  for (uint32_t uiBitIndex = 0; uiBitIndex < cuiSize; ++uiBitIndex) {
    if ((!(uiBitIndex % cuiSymbInGroup)) && (uiBitIndex > 0)) {
      std::cout << '\'';
    }
    std::cout << pBits[uiBitIndex];
  }
  std::cout << " Bits '" << cOneSymbol << "': " << ui_inPosBitTotal << '\n';
}

int main() {
  constexpr uint32_t cuiBITSINBYTE{8};
  constexpr uint32_t cuiTOTALBITS{sizeof(uint32_t) * cuiBITSINBYTE};

  uint32_t uiValue{uiGetValue()};

  char acBits[cuiTOTALBITS];

  uint32_t uiPosBitTotal{uiGetSum(uiValue, acBits, cuiTOTALBITS)};
  vPrintRes(uiValue, uiPosBitTotal, acBits, cuiTOTALBITS);

  //-----------------------------
  // the same but with bitset
  //-----------------------------
  std::bitset<cuiTOTALBITS> myBitset{uiValue};

  std::cout << uiValue << " Bitset --->";
  std::cout << myBitset << " Bits '" << cOneSymbol << "': " << myBitset.count()
            << '\n';

  return 0;
}
