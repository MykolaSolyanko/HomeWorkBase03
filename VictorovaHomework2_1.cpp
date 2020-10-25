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
  std::cout << "Sum=" << sum << std::endl;
  int average{};
  double average = sum / count;
  std::cout << "Average=" << average << std::endl;

  // 2
  std::cout << "Please enter a 6-digit number --> _ _ _ _ _ _" << std::endl;
  int number2{};

  std::cin >> number2;

  int a1{};
  int a2{};
  int constexpr kMin{ 99999 };
  int constexpr kMax{ 999999 };
  if (kMin >= number2 || number2 > kMax) {
    std::cout << "You enterd incorrect number" << std::endl;
    return -1;
  } else {
     int c{};
    for (int i = 0; number2>0; i++) {
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
//3
std::cout << "Enter number" << std::endl;
    int number{};
    std::cin >> number;
    int reverse{};
    while (number) {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
    std::cout << "Reverse ="<<reverse<<std::endl;
//4
int array[50];
    constexpr int kMinRange{ -60 };
    constexpr int kMaxRange{ 90 };

    std::cout << "Please, enter values in the range from" << kMinRange << "to"
        << kMaxRange << "inclusive" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::cin >> array[i];

        if (array[i] < kMinRange || array[i] > kMaxRange) {
            std::cout << "Value is out of range" << std::endl;
            return -1;
        }
        else {
            std::cout << "Array=" << array[i] << std::endl;
        }
    }
    int sum{};
    for (int i = 0; i < 50; i++) {
        if (array[i] % 2 != 0) {
            sum += array[i];
        }
    }
    std::cout << "Sum=" << sum << std::endl;
//5
 std::cout << "Input number  to findt best divider = \n";
  int number{};
  std::cin >> number;

  int sum = 0;
  int numOne = 0;
  int count = 0;
  int j{0};

  for (int i = number; i > 0; --i) {
    if (number % i == 0) {
      j = i;
      std::cout << "deliver = " << j << std::endl;
    }
  }
  while (number) {
    sum += number % 10;
    number /= 10;
  }
  std::cout << "Sum of digits of the number =" << sum << std::endl;

  if (j > sum) {
    numOne = j;
  }
  std::cout << "" << numOne << std::endl;
}
