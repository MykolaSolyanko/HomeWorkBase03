========================№1================================
#include <iostream>

int main() {

  int a{0};
  double sum{0};
  int num{0};
  std::cout << "enter a three-digit number: ";
  std::cin >> num;
  std::cout << "Enter a number of digits in a number:";
  std::cin >> a;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  std::cout << "Amount of numbers: " << a << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Avarage: " << sum / a << std::endl;

  return 0;
}
========================№2==================================
#include <iostream>
int main() {
  std::cout << "Enter a six numbers: " << std::endl;
  int x1{};
  std::cout << "Enter x1: ";
  std::cin >> x1;
  if (x1 >= 10) {
    std::cout << "You enter a wrong number!" << std::endl;
    return -1;
  }
  int x2{};
  std::cout << "Enter x2: ";
  std::cin >> x2;
  if (x2 >= 10) {
    std::cout << "You enter a wrong number!" << std::endl;
    return -1;
  }
  int x3{};
  std::cout << "Enter x3: ";
  std::cin >> x3;
  if (x3 >= 10) {
    std::cout << "You enter a wrong number!" << std::endl;
    return -1;
  }
  int x4{};
  std::cout << "Enter x4: ";
  std::cin >> x4;
  if (x4 >= 10) {
    std::cout << "You enter a wrong number!" << std::endl;
    return -1;
  }
  int x5{};
  std::cout << "Enter x5: ";
  std::cin >> x5;
  if (x5 >= 10) {
    std::cout << "You enter a wrong number!" << std::endl;
    return -1;
  }
  int x6{};
  std::cout << "Enter x6: ";
  std::cin >> x6;
  if (x6 >= 10) {
    std::cout << "You enter a wrong number!" << std::endl;
    return -1;
  }
  std::cout << "Your number: " << x1 << x2 << x3 << x4 << x5 << x6 << std::endl;
  if (x1 + x2 + x3 != x4 + x5 + x6) {
    std::cout << "You enter a wrong number!" << std::endl;
  } else {
    std::cout << "\n\n*************************\n\n";
    std::cout << "You win!" << std::endl;
    std::cout << "\n\n*************************\n\n";
  }

  return 0;
}
===========================№3===============================
#include <iostream>

int main() {
  std::cout << "Enter a number: ";
  int32_t num{0};
  std::cin >> num;
  int revesenum{0};

  while (num) {
    revesenum = revesenum * 10 + (num % 10);
    num /= 10;
  }

  std::cout << "Your reversed number: " << revesenum << std::endl;
  return 0;
}
===========================№4===============================
#include <iostream>
int main() {
  std::cout << "Enter some numbers. You may enter a numbers from -60 to 90. "
               "For exit enter <0>: "
            << std::endl;
  int oddsum{};
  for (int i = 1; i < 50; ++i) {
    int value{};
    std::cin >> value;
    if (!std::cin || value == 0) {
      break;
    }
    if (value <= -60 || value >= 90) {
      std::cout
          << "You enter a wrong number! Please enter a number from -60 to 90 "
          << std::endl;
      return 0;
    }
    if (value % 2 != 0) {
      oddsum += value;
    }
  }
  std::cout << std::endl;
  std::cout << "Your oddsum of your number is:" << oddsum << std::endl;
  return 0;
}
===========================№5===============================
#include <iostream>
int main() {
  size_t number{0};
  int sum{0};
  int bestdivider{0};
  std::cout << "Input number to find best divider = ";
  std::cin >> number;
  int numOne = 0;
  std::cout << "Deviders of number " << number << ":" << std::endl;
  for (int i = number; i > 0; --i) {
    if (number % i == 0) {
      int j = 0;
      j = i;
      std::cout << j << "\n";
    }
  }
  for (int i{1}; i < number; ++i) {
    if (number % i == 0) {
      bestdivider = i;
    }
  }
  std::cout << "Best divider is:" << bestdivider;

  return 0;
}

