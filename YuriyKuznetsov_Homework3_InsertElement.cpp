#include <array>
#include <iostream>

constexpr uint32_t cuiCAPACITY{10};

void vFillBuiltInArray();
uint32_t uiGetValue();
void vFillFirstElement(uint32_t *ArrElement, uint32_t uiValue);
void vFillNextElement(uint32_t *auiElements, uint32_t uiValue,
                      size_t SizeElements);

int main() {
  vFillBuiltInArray();
  return 0;
}

void vFillBuiltInArray() {
  uint32_t auiMyArray[cuiCAPACITY]{};
  size_t uiSize{};

  while (uiSize < cuiCAPACITY) {
    uint32_t uiCurrentValue{uiGetValue()};

    if (uiSize == 0) {
      vFillFirstElement(auiMyArray, uiCurrentValue);
    } else {
      vFillNextElement(auiMyArray, uiCurrentValue, uiSize);
    }

    ++uiSize;

    for (auto Value : auiMyArray) {
      std::cout << Value << ' ';
    }
    std::cout << '\n';
  }
}

uint32_t uiGetValue() {
  uint32_t uiValue{};
  std::cout << "Enter integer value: ";
  if (!(std::cin >> uiValue)) {
    std::cout << "Uncorrect value! Current value will be '0'";
    uiValue = 0;
  }
  return uiValue;
}

void vFillFirstElement(uint32_t *uiArrElement, uint32_t uiValue) {
  *uiArrElement = uiValue;
}

void vFillNextElement(uint32_t *auiElements, uint32_t uiValue,
                      size_t SizeElements) {
  for (int32_t iRIndex = (SizeElements - 1); iRIndex >= 0; --iRIndex) {
    if (uiValue < auiElements[iRIndex]) {
      auiElements[iRIndex + 1] = auiElements[iRIndex];
      auiElements[iRIndex] = uiValue;
    } else {
      auiElements[iRIndex + 1] = uiValue;
      break;
    }
  }
}
