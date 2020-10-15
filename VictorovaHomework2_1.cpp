#include <iostream>

int main() {
  // 1
  std::cout << "Please enter the number" << std::endl;
  long long number{};
  std::cin >> number;
  int count{};
  int sum{};
  while (number != 0) {
    sum += number % 10;
    number /= 10;
    count++;
  }
  std::cout << "The amount of digits=" << count << std::endl;

  while (number > 0) {
    sum += number % 10;

    number /= 10;
  }
  std::cout << "Sum=" << sum << std::endl;
  int average{};
  average = sum / count;
  std::cout << "Average=" << average << std::endl;

  // 2
  std::cout << "Please enter a 6-digit number --> _ _ _ _ _ _" << std::endl;
  int number2{};

  std::cin >> number2;

  int a1{};
  int a2{};
  int c{};
  if (99999 >= number2 || number2 > 999999) {
    std::cout << "You enterd incorrect number" << std::endl;
    return -1;
  } else {
    for (int i = 0; number2; i++) {
      c = number2 % 10;
      if (i < 3) {
        a1 += c;
      } else {
        a2 += c;
      }
      number2 /= 10;
    }
  }

  std::cout << "Sum of first three digits=" << a1 << " \n"
            << "Sum of second three digits=" << a2 << std::endl;
  if (a1 == a2) {
    std::cout << "Your ticket is lucky" << std::endl;
  } else {
    std::cout << "Your ticket is unlucky" << std::endl;
  }

  return 0;
}
