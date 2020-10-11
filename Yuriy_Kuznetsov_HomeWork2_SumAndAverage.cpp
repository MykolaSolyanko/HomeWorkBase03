// Посчитать сумму и среднее арифметическое цифр в числе
#include <iostream>
#include <limits>
#include <vector>

int main(int argc, char *argv[]) {
  const std::uint32_t ciKOEF_MULTI{10}; // must be >0
  std::uint32_t iInNumber{};
  std::vector<uint32_t> vDigits{};

  std::cout << "Enter digits: ";
  std::cin >> iInNumber; // without checking for correctness

  std::uint32_t iTempNumber{iInNumber};
  std::uint32_t iTempNumberZeroEnd{iInNumber};
  std::uint32_t iDigit{};
  while (iTempNumber != 0) {
    iTempNumberZeroEnd = (iTempNumber / ciKOEF_MULTI) * ciKOEF_MULTI;
    iDigit = iTempNumber - (iTempNumberZeroEnd);
    vDigits.push_back(iDigit);
    iTempNumber /= ciKOEF_MULTI;
  }
  std::uint32_t iSum{};
  for (auto p = vDigits.rbegin(); p != vDigits.rend(); ++p) {
    std::cout << *p;
    if (iSum > (std::numeric_limits<std::uint32_t>::max() - *p)) {
      std::cout << "The sum is overlimit\n";
      return -1;
    }
    iSum += *p;
    if (p != (vDigits.rend() - 1)) {
      std::cout << " + ";
    }
  }
  std::cout << " = " << iSum << '\n';

  if (vDigits.size() == 0) {
    std::cout << "There is no digits \n";
    return -1;
  }
  std::cout << iSum << " / " << vDigits.size() << " = "
            << (iSum / vDigits.size()) << '\n';

  return 0;
}
