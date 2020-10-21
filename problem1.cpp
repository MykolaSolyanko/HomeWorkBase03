#include <cmath>
#include <iostream>

int main() {
 
  constexpr int Lower_Limit {1};
  constexpr int Upper_Limit {1000000};
  
  std::cout << "Enter the integer in scope from "<< Lower_Limit <<" to "<< Upper_Limit <<'\n';
  
  int number{};
  std::cin >> number;
  if(number < Lower_Limit || number > Upper_Limit){
    std::cout<<"incorrect input\n";
    return 1;
  }

  const int Digit_in_Number = std::log10(number) + 1;
  int sum{};

  for (int i=0; i < Digit_in_Number; ++i) {
    auto val = number % 10;
    sum += val;
    number /= 10;
  }

  auto average = static_cast<double>(sum) / Digit_in_Number;

  std::cout << "Sum of digits in number  equal " << sum << '\n'
            << "Average is  " << average << '\n';

  return 0;
}
