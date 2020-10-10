#include <cmath>
#include <iostream>

int main() {
    constexpr auto coef1{ 4 };
    constexpr auto coef2{ 2 };
    auto a{ 0 };
    auto b{ 0 };
    auto c{ 0 };
    auto D{ 0.0 };
    auto x1{ 0.0 };
    auto x2{ 0.0 };

    std::cout << "Please enter coefficient a in range [2...365] -->" << std::endl;
    std::cin >> a;
    if (a >= 2 && a <= 365) {
        std::cout << "You entered a correct number" << std::endl;
    }
    else {
        std::cout << "You entered incorrect number, try to enter the number again"
            << std::endl;
    }
    std::cout << "Please enter coefficient b in range [2...365] -->" << std::endl;
    std::cin >> b;
    if (b >= 2 && b <= 365) {
        std::cout << "You entered a correct number" << std::endl;
    }
    else {
        std::cout << "You entered incorrect number, try to enter the number again"
            << std::endl;
    }
    std::cout << "Please enter coefficient c in range [2...365] -->" << std::endl;
    std::cin >> c;
    if (c >= 2 && c <= 365) {
        std::cout << "You entered a correct number" << std::endl;
    }
    else {
        std::cout << "You entered incorrect number, try to enter the number again"
            << std::endl;
    }

    D = pow(b, 2) - coef1 * a * c;
    std::cout << "D=" << D << std::endl;

    if (D >= 0) {
        x1 = (-b + sqrt(pow(b, 2) - coef1 * a * c)) / (coef2 * a);
        std::cout << "x1=" << x1 << std::endl;
        x2 = (-b - sqrt(pow(b, 2) - coef1 * a * c)) / (coef2 * a);
        std::cout << "x2=" << x2 << std::endl;
    }
    else {
        std::cout << "D<=0" << std::endl;
    }

    return 0;
}
