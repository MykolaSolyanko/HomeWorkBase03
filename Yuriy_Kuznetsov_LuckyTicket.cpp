//Счастливый билетик
#include <iostream>
#include <string>
#include <vector>

constexpr std::uint32_t ciKOEF_MULTI{10};
constexpr std::uint32_t ciTICKET_SIZE{6};
constexpr std::uint32_t ciHALF{2};
constexpr std::uint32_t ciMyError{1};

std::uint32_t uiGetNumber(void) {
  std::string sTempString{};
  std::uint32_t iRes{};

  std::cout << "Please enter " << ciTICKET_SIZE
            << " digits of the number of ticket : ";

  try {
    std::getline(std::cin, sTempString);

    if (sTempString.length() > ciTICKET_SIZE) {
      throw ciMyError;
    }
    for (auto p = sTempString.begin(); p != sTempString.end(); ++p) {
      if ((*p > '9') || (*p < '0')) {
        throw ciMyError;
      }
    }
    iRes = std::stoi(sTempString);

  } catch (...) {
    std::cout << "You entered an incorrect number";
  }
  return iRes;
}

int main(int argc, char *argv[]) {
  std::uint32_t uiTicketNumber{uiGetNumber()};

  std::uint32_t uiTempNumber{uiTicketNumber};
  std::uint32_t uiTempNumberZeroEnd{uiTicketNumber};
  std::uint32_t uiDigit{};
  std::uint32_t uiSum1{};
  std::uint32_t uiSum2{};

  for (std::uint32_t iIndex = 0; iIndex < ciTICKET_SIZE; ++iIndex) {
    uiTempNumberZeroEnd = (uiTempNumber / ciKOEF_MULTI) * ciKOEF_MULTI;
    uiDigit = uiTempNumber - (uiTempNumberZeroEnd);
    if (iIndex < (ciTICKET_SIZE / ciHALF)) {
      uiSum1 += uiDigit;
    } else {
      uiSum2 += uiDigit;
    }
    uiTempNumber /= ciKOEF_MULTI;
  }

  std::cout << "Your ticket is ";
  if (uiSum1 == uiSum2) {
    std::cout << "lucky\n";
  } else {
    std::cout << "unlucky\n";
  }

  return 0;
}
