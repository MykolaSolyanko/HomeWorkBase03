#include <iostream>

int main() {
  constexpr int16_t Max_Size{50};
  constexpr int16_t MinRange{-60};
  constexpr int16_t MaxRange{90};

  std::cout << "Enter list integers from " << MinRange << " to " << MaxRange
            << "\n"
            << "(no more 50 numbers). At the end of input put 0 \n";

  int Sum{};

  for (int i{1}; i < Max_Size; ++i) {
    int32_t Numb{};
    std::cin >> Numb;
    if (!std::cin || Numb < MinRange || Numb > MaxRange) {
      return -1;
    }
    // Exit of programm
    if (Numb == 0) {
      break;
    }
    if (i % 2 != 0) {
      Sum += Numb;
    }
  }
  std::cout << "sum of odd numbers =  " << Sum << '\n';

  return 0;
}
