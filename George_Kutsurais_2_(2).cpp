#include <cmath>
#include <iostream>

int main() {
    std::cout << "\t\t\t\t\tSimple programm named \" Lucky ticket \"\n\n\n";
    std::cout << "Enter your number: " << std::endl;

    int number{};
    std::cin >> number;

    while (true) {
        int x1 = number % 10;
        int x2 = number / 10 % 10;
        int x3 = number / 100 % 10;
        int x4 = number / 1000 % 10;
        int x5 = number / 10000 % 10;
        int x6 = number / 100000 % 10;
        int sum = x1 + x2 + x3;
        int sum2 = x4 + x5 + x6;

        if (sum == sum2 && number / 1000000 % 10 == 0) {
            std::cout << "Lucky ticket";
            break;
        }
        else if (sum != sum2 && number / 1000000 % 10 == 0) {
            std::cout << "Unlucky ticket";
            break;
        }
    }
}
