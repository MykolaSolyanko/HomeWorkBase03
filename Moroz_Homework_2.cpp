#include <iostream>
#include <limits>

void getSumAndAverage() {
  std::cout << R"(Please, enter some integer value to calculate
          the sum of digits and it's average: )";
  long long inputValue{};
  std::cout << "-->";
  std::cin >> inputValue;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(32768, '\n');
    std::cout << "Wrong number! Please try again later." << std::endl;
    return;
  }

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
  std::cout << "-->";
  std::cin >> luckyTicketValue;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(32768, '\n');
    std::cout << "Wrong number! Please try again later." << std::endl;
    return;
  }

  if (luckyTicketValue < 100000 || luckyTicketValue > 999999) {
    std::cout << "The number of digits is different from 6 or your number is "
                 "less than 0"
              << std::endl;
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

void reverseNumber() {
  std::cout << "Please enter number in range "
            << std::numeric_limits<int32_t>::min() << ".."
            << std::numeric_limits<int32_t>::max() << std::endl;
  int32_t numberToReverse{};
  std::cout << "----->";
  std::cin >> numberToReverse;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(32768, '\n');
    std::cout << "Wrong number! Please try again later." << std::endl;
    return;
  }

  int64_t reversedNumber{};
  while (numberToReverse) {
    reversedNumber += ((numberToReverse % 10));
    numberToReverse /= 10;
    if (numberToReverse) {
      reversedNumber *= 10;
    }
  }

  std::cout << "Your reversed number: " << reversedNumber << std::endl;
}

void sumOfOdd() {
  constexpr uint16_t numberOfIteration{10};
  constexpr int16_t minValue{-60};
  constexpr int16_t maxValue{60};
  int64_t sumOfOddNumbers{};
  std::cout << "Please, enter " << numberOfIteration << " numbers to calculate summ of odd numbers:" << std::endl;

  uint16_t counter{};
  while(counter < numberOfIteration) {
    int32_t number{};
    std::cout << "-->";
    std::cin >> number;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32768, '\n');
      std::cout << "Wrong number! Please try again later." << std::endl;
      return;
    }
    if((number < minValue) || (number > maxValue)) {
      std::cout << "Invalid value! Break." << std::endl;
      return;
    }
    if((number % 2) != 0) {
      sumOfOddNumbers += number;
    }
    counter++;
  }

  std::cout << "The sum of all odd elements is " << sumOfOddNumbers << std::endl;
}

void bestDivider() {
    constexpr int16_t minValue{2};
    std::cout << "Please enter some integer number between " << minValue << " and " << std::numeric_limits<int16_t>::max() << std::endl;
    int16_t value{};

    std::cin >> value;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32768, '\n');
      std::cout << "Wrong number! Please try again later." << std::endl;
      return;
    }
    int16_t dividerValue{value};
    int16_t maxValue{};
    while(dividerValue) {
        if((value % dividerValue) == 0) {
            if(dividerValue > 9) {
                int16_t sumOfDigitsDividerValue{};
                int16_t temp{dividerValue};
                while (temp) {
                    sumOfDigitsDividerValue += temp % 10;
                    temp /= 10;
                }
                if(sumOfDigitsDividerValue > maxValue) {
                    maxValue = sumOfDigitsDividerValue;
                    dividerValue--;
                    continue;
                }
            }
            if(dividerValue > maxValue) {
                maxValue = dividerValue;
            }
        }
        dividerValue--;
    }

    std::cout << "Best divider of " << value << " is " << maxValue << std::endl;
}

int main() {
  while (true) {
    std::cout << "Choose your function. Enter one of the numbers below. To "
                 "exit enter -1."
              << std::endl;
    std::cout << "1 - Sum and Average." << std::endl;
    std::cout << "2 - Lucky ticket." << std::endl;
    std::cout << "3 - Reverse Number." << std::endl;
    std::cout << "4 - Sum of all odd elements." << std::endl;
    std::cout << "5 - Best divider." << std::endl;
    std::cout << "-----> ";
    int16_t marker{};
    std::cin >> marker;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32768, '\n');
      std::cout << "Wrong number! Please try again later." << std::endl;
    }
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
    case 3:
      std::cout << std::endl;
      reverseNumber();
      std::cout << std::endl;
      break;
    case 4:
      std::cout << std::endl;
      sumOfOdd();
      std::cout << std::endl;
      break;
    case 5:
        std::cout << std::endl;
        bestDivider();
        std::cout << std::endl;
        break;
    case -1:
      std::cout << std::endl;
      std::cout << "Bye!" << std::endl;
      return 0;
      break;
    default:
      std::cout << std::endl;
      std::cout << "This function is not presented." << std::endl;
      std::cout << std::endl;
      break;
    }
  }

  return -1;
}
