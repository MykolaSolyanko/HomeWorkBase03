#include <iostream>

void getSumAndAverage() {
  std::cout << R"(Please, enter some integer value to calculate
          the sum of digits and it's average: )";
  long long inputValue{};
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
  int counter{1};
  while ((temp /= 10) > 0) {
    counter++;
  }

  if ((counter < 6) || (counter > 6)) {
    std::cerr << "The number of digits is different from 6.";
    return;
  }

  uint16_t firstPart{};
  uint32_t divider{100000};
  for (size_t i = 0; i < 3; i++) {
    firstPart += (luckyTicketValue / divider);
    luckyTicketValue %= divider;
    divider /= 10;
  }

  uint16_t secondPart{};
  for (size_t i = 0; i < 3; i++) {
    secondPart += (luckyTicketValue / divider);
    luckyTicketValue %= divider;
    divider /= 10;
  }

  if (firstPart != secondPart) {
    std::cout << "This number is not lucky:(" << std::endl;
    return;
  }

  std::cout << "Congratulations! Your number is lucky!" << std::endl;
}

int main() {
  //  getSumAndAverage();
  //  luckyTicket();

  while (true) {
    std::cout << "Choose your function. Enter one of the numbers below. To "
                 "exit enter -1."
              << std::endl;
    std::cout << "1 - Sum and Average." << std::endl;
    std::cout << "2 - Lucky ticket." << std::endl;
    std::cout << "-----> ";
    int16_t marker{};
    std::cin >> marker;
    switch (marker) {
    case 1:
      std::cout << std::endl;
      getSumAndAverage();
      std::cout << std::endl;
      break;
    case 2:
      std::cout << std::endl;
      luckyTicket();
      std::cout << std::endl;
      break;
    case -1:
      std::cout << std::endl;
      std::cout << "Bye!" << std::endl;
      return 0;
      break;
    default:
      std::cout << "This function is not presented." << std::endl;
      break;
    }
  }

  return -1;
}
