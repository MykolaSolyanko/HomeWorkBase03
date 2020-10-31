#include <cmath>
#include <iostream>

double dGetValue(const char in_ccValueName) {
  constexpr double cdMIN{2.0};
  constexpr double cdMAX{255.0};
  double sInData{};
  std::cout << "Please enter number in range [" << cdMIN << "..." << cdMAX
            << "] for coefficient " << in_ccValueName << ':';
  std::cin >> sInData;
  if ((sInData < cdMIN) || (sInData > cdMAX)) {
    sInData = cdMIN;
    std::cout << "You entered an incorrect number, the default value is MIN";
  }
  return sInData;
}

int main() {
  constexpr double cdTWO{2.0};
  constexpr double cdFOUR{4.0};

  const double cdA{dGetValue('A')};
  const double cdB{dGetValue('B')};
  const double cdC{dGetValue('C')};

  const double cdDiskriminant{cdB * cdB - cdFOUR * cdA * cdC};
  if (cdDiskriminant < 0) {
    std::cout << "No answer in this equation \n";
    return 0;
  }

  double dX1{(-cdB + std::sqrt(cdDiskriminant)) / (cdTWO * cdA)};
  double dX2{(-cdB - std::sqrt(cdDiskriminant)) / (cdTWO * cdA)};

  std::cout << "X1 = " << dX1 << ";\nX2 = " << dX2 << ";\n";

  return 0;
}
