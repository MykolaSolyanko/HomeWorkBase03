#include <iostream>

void getSumAndAverage() {
  std::cout << R"(Please, enter some integer value to calculate
          the sum of digits and it's average: )";
  long inputValue{};
  std::cin >> inputValue;

  long long sumOfDigits{};
  int numOfDigits{};
  while (inputValue) {
    sumOfDigits += inputValue % 10;
    inputValue /= 10;
    numOfDigits++;
  }

  long long average = sumOfDigits / numOfDigits;

  std::cout << "Sum of digits: " << sumOfDigits << "." << std::endl;
  std::cout << "Average of the sum of digits: " << average << "." << std::endl;
}

void luckyTicket() {
  std::cout << "It's \"Lucky ticket\" checker function " << std::endl;
  std::cout << "Please, enter 6 digit number: ";
  int luckyTicketValue{};
  std::cin >> luckyTicketValue;

  if (luckyTicketValue <= 0) {
    std::cerr << "It's bad value. Your value must be above 0.";
    return;
  }

  int temp{luckyTicketValue};
  int counter{};
  while ((temp /= 10) != 0) {
    counter++;
  }

  if ((counter < 6) || (counter > 6)) {
    std::cerr << "The number of digits is different from 6.";
    return;
  }
}

int main() {
  getSumAndAverage();
  luckyTicket();
  return 0;
}
