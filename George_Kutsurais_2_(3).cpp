#include <cmath>
#include <iostream>

int main() {
    std::cout << "Enter number of digits: " << std::endl;
    int amount{};
    std::cin >> amount;
    std::cout << "Enter your number: " << std::endl;
    int number{};
    std::cin >> number;
    if (number > 0 && number % 10 != 0) {
        for (int i = 0; i < amount; ++i)
            std::cout << static_cast<int>(number) / static_cast<int>(pow(10, i)) % 10;
    }
    else if (number == 0) {
        for (int i = 0; i < amount; ++i)
            std::cout << "0";
    }
    else if (number < 0) {
        std::cout << "-";
        for (int i = 0; i < amount; ++i)
            std::cout << static_cast<int>(-number) / static_cast<int>(pow(10, i)) %
            10;
    }
    else if (number % 10 == 0) {
        for (int i = 1; i < amount; ++i)
            std::cout << static_cast<int>(number) / static_cast<int>(pow(10, i)) % 10;
    }
}
