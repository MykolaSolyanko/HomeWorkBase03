#include <iostream>
#include <limits>

enum funcTypes {
  EXIT,
  GET_SUM_OF_AVERAGE,
  LUCKY_TICKET,
  REVERSE_NUMBER,
  SUM_OF_ODD,
  BEST_DIVIDER
};

int32_t inputValueFunc() {
  const uint16_t howManySymbolsIgnore{32768};

  int32_t value{};
  std::cin >> value;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(howManySymbolsIgnore, '\n');
    std::cout << "Wrong number! Please try again later." << std::endl;
    return -1;
  }

  return value;
}

void getSumAndAverage() {

  std::cout << R"(Please, enter some integer value to calculate
          the sum of digits and it's average: )";
  std::cout << "-->";
  int32_t inputValue{inputValueFunc()};
  if (inputValue == -1) {
    return;
  }

  long long sumOfDigits{};
  int numOfDigits{};
  while (inputValue) {
    sumOfDigits += inputValue % 10;
    inputValue /= 10;
    numOfDigits++;
  }

  double average = sumOfDigits / static_cast<double>(numOfDigits);

  std::cout << "Sum of digits: " << sumOfDigits << "." << std::endl;
  std::cout << "Average of the sum of digits: " << average << "." << std::endl;
}

void luckyTicket() {
  std::cout << "It's \"Lucky ticket\" checker function " << std::endl;
  std::cout << "Please, enter 6 digit number: ";
  std::cout << "-->";
  int luckyTicketValue{inputValueFunc()};
  if (luckyTicketValue == -1) {
    return;
  }

  const int minSixDigitNember{100000};
  const int maxSixDigitNumber{999999};

  if (luckyTicketValue < minSixDigitNember ||
      luckyTicketValue > maxSixDigitNumber) {
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
  std::cout << "----->";
  int32_t numberToReverse{inputValueFunc()};
  if (numberToReverse == -1) {
    return;
  }

  int64_t reversedNumber{};
  while (numberToReverse > 0) {
    reversedNumber += ((numberToReverse % 10));
    numberToReverse /= 10;
    if (numberToReverse > 0) {
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
  std::cout << "Please, enter " << numberOfIteration
            << " numbers to calculate summ of odd numbers:" << std::endl;

  uint16_t counter{};
  while (counter < numberOfIteration) {
    std::cout << "-->";
    int32_t number{inputValueFunc()};
    if (number == -1) {
      return;
    }

    if ((number < minValue) || (number > maxValue)) {
      std::cout << "Invalid value! Break." << std::endl;
      return;
    }
    if ((number % 2) != 0) {
      sumOfOddNumbers += number;
    }
    counter++;
  }

  std::cout << "The sum of all odd elements is " << sumOfOddNumbers
            << std::endl;
}

void bestDivider() {
  constexpr int16_t minValue{2};
  std::cout << "Please enter some integer number between " << minValue
            << " and " << std::numeric_limits<int16_t>::max() << std::endl;
  int32_t value{inputValueFunc()};
  if (value == -1) {
    return;
  }

  int32_t dividerValue{value};
  int32_t maxValue{};
  while (dividerValue > 0) {
    if ((value % dividerValue) == 0) {
      if (dividerValue > 9) {
        int32_t sumOfDigitsDividerValue{};
        int32_t temp{dividerValue};
        while (temp) {
          sumOfDigitsDividerValue += temp % 10;
          temp /= 10;
        }
        if (sumOfDigitsDividerValue > maxValue) {
          maxValue = dividerValue;
          dividerValue--;
          continue;
        }
      }
      if (dividerValue > maxValue) {
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
                 "exit enter "
              << EXIT << std::endl;
    std::cout << "1 - Sum and Average." << std::endl;
    std::cout << "2 - Lucky ticket." << std::endl;
    std::cout << "3 - Reverse Number." << std::endl;
    std::cout << "4 - Sum of all odd elements." << std::endl;
    std::cout << "5 - Best divider." << std::endl;
    std::cout << "-----> ";

    int32_t marker{inputValueFunc()};

    switch (marker) {
    case GET_SUM_OF_AVERAGE:
      std::cout << std::endl;
      getSumAndAverage();
      std::cout << std::endl;
      break;
    case LUCKY_TICKET:
      std::cout << std::endl;
      luckyTicket();
      std::cout << std::endl;
      break;
    case REVERSE_NUMBER:
      std::cout << std::endl;
      reverseNumber();
      std::cout << std::endl;
      break;
    case SUM_OF_ODD:
      std::cout << std::endl;
      sumOfOdd();
      std::cout << std::endl;
      break;
    case BEST_DIVIDER:
      std::cout << std::endl;
      bestDivider();
      std::cout << std::endl;
      break;
    case EXIT:
      std::cout << std::endl;
      std::cout << "Bye!" << std::endl;
      return 0;
    default:
      std::cout << std::endl;
      std::cout << "This function is not presented." << std::endl;
      std::cout << std::endl;
      break;
    }
  }

  return -1;
}
