#include <cmath>
#include <iostream>

int main() {

    std::cout << "\t\t\t\tSum of odd numbers \n";
    int amount{};
    std::cout << "How many number you want to enter? [min 1 max 50] --> ";
    while (true) {
        std::cin >> amount;
        if (amount < 0 || amount > 50) {
            std::cout << "Only range 1 to 50. Type number again. --> ";
        }
        else {
            break;
        }
    }
    std::cout << "Enter numbers: " << std::endl;
    int* numbers = new int[amount];
    double sum{};
    int x{};
    for (int i = 0; i < amount; ++i) {
        int number{};
        std::cin >> number;
        if (number % 2 != 0) {
            sum += number;
            numbers[x] = number;
            ++x;
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < x; ++i) {
        std::cout << numbers[i];
        if (i + 1 == x) {
            break;
        }
        std::cout << " + ";
    }
    if (x == 0) {
        std::cout << "No odd numbers";
    }
    else {
        std::cout << " = " << sum;
        std::cout << std::endl;
        std::cout << sum << " / " << x << " = " << sum / x << std::endl;
    }
    system("pause");
    return 0;
}
