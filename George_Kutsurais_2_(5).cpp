#include <cmath>
#include <iostream>

int main() {
  std::cout << "\t\t\t\tThe best remainder of the division\n\n\n";
  std::cout << "Enter your number --> \n";
  int number{};
  std::cin >> number;
  for (int i = number - 1; i > 0; --i) {
    if (number % i == 0) {
      int j = i;
      std::cout << "The best divider --> " << j << std::endl;
      break;
    }
  }
  system("pause");
  return 0;
}
