#include <cmath>
#include <iostream>

int main() {
    constexpr int kMinRange{ -2 };
    constexpr int kMaxRange{ 365 };

    auto x1{ 0.0 };
    auto x2{ 0.0 };

    std::cout << "Please enter coefficient a (in the range from " << kMaxRange
        << "to" << kMaxRange << ")" << std::endl;
    auto a{ 0 };
    std::cin >> a;
    if (a >= 2 && a <= 365) {
        std::cout << "You entered a correct number" << std::endl;
    }
    else {
        std::cout << "You entered incorrect number, try to enter the number again"

            << std::endl;
        return -1;
    }
    std::cout << "Please enter coefficient b (in the range from" << kMinRange
        << "to" << kMaxRange << ")" << std::endl;
    auto b{ 0 };
    std::cin >> b;
    if (b >= 2 && b <= 365) {
        std::cout << "You entered a correct number" << std::endl;
    }
    else {
        std::cout << "You entered incorrect number, try to enter the number again"
            << std::endl;
        return -1;
    }
    std::cout << "Please enter coefficient c (in the range " << kMinRange << "to"
        << kMaxRange << ")" << std::endl;
    auto c{ 0 };
    std::cin >> c;
    if (c >= 2 && c <= 365) {
        std::cout << "You entered a correct number" << std::endl;
    }
    else {
        std::cout << "You entered incorrect number, try to enter the number again"
            << std::endl;
        return -1;
    }
    const long double kD = (b * b) - 4 * a * c;
    std::cout << "D=" << kD << std::endl;

    if (kD >= 0) {
        x1 = (-b + sqrt(kD)) / (2 * a);
        std::cout << "x1=" << x1 << std::endl;
        x2 = (-b - sqrt(kD)) / (2 * a);
        std::cout << "x2=" << x2 << std::endl;
    }
    else {
        std::cout << "D<=0" << std::endl;
    }

    return 0;
}
