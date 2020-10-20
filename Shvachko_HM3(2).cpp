#include <array>
#include <iostream>

int main() {
  constexpr uint16_t kSize{8};
  std::array<int, kSize> ar{};
  for (int i = 0; i < kSize; i++) {
    std::cout << "Enter elements of array --->";
    std::cin >> ar[i];
    if (!(std::cin) >> ar[i]) {
      return 0;
    }
  }
  for (int i = 0; i < kSize - 1; i++) {
    for (int j = 0; j < kSize - i - 1; j++) {
      if (ar[j] > ar[j + 1]) {
        int temp = ar[j];
        ar[j] = ar[j + 1];
        ar[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < kSize; i++) {
    std::cout << ar[i] << " ";
  }
  return 0;
}
