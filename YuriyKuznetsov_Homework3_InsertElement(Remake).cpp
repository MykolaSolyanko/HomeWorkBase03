// Написать программу вставки элемента в массив
#include <iostream>

uint32_t uiGetValue();
void vInsertElement(uint32_t *auiElements, uint32_t uiValue,
                    const size_t csizeCur);

int main() {
  constexpr size_t csizeCAPACITY{10};
  uint32_t auiMyArray[csizeCAPACITY]{};
  size_t sizeCurrent{};

  while (sizeCurrent < csizeCAPACITY) {
    uint32_t uiCurrentValue{uiGetValue()};

    vInsertElement(auiMyArray, uiCurrentValue, sizeCurrent);

    ++sizeCurrent;

    for (auto Value : auiMyArray) {
      std::cout << Value << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

uint32_t uiGetValue() {
  uint32_t uiValue{};
  std::cout << "Enter unsigned integer value to insert to array: ";
  if (!(std::cin >> uiValue)) {
    std::cout << "Uncorrect value! Current value will be '0'";
    uiValue = 0;
  }
  return uiValue;
}

void vInsertElement(uint32_t *auiElements, const uint32_t cuiValue,
                    const size_t csizeCur) {
  if (csizeCur == 0) {
    *auiElements = cuiValue;
    return;
  }
  for (int32_t iRIndex = (csizeCur - 1); iRIndex >= 0; --iRIndex) {
    if (cuiValue < auiElements[iRIndex]) {
      auiElements[iRIndex + 1] = auiElements[iRIndex];
      auiElements[iRIndex] = cuiValue;
    } else {
      auiElements[iRIndex + 1] = cuiValue;
      break;
    }
  }
}
