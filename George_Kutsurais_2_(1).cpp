#include <cmath>
#include <iostream>

int main() {
    std::cout << "How many numbers? --> ";
    int amount{};
    std::cin >> amount;
    int* numbers = new int[amount];
    int x{};
    double sum{};
    std::cout << "Enter your number: " << std::endl;
    for (int i = 0; i < amount; ++i) {
        std::cin >> numbers[i];
        sum += numbers[i];
        x++;
    }
    for (int i = 0; i < x; i++) {
        std::cout << numbers[i];
        if (i + 1 == x)
            break;
        std::cout << " + ";
    }
    std::cout << " = " << sum << std::endl;
    double result = sum / amount;
    std::cout << "Average --> ";
    std::cout << sum << " / " << amount << " = " << result << std::endl;

    system("pause");
    return 0;
}
