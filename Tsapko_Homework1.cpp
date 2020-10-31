//This program finds the roots of a quadratic equation
#include <iostream>
#include <cmath>

int main() {

    std::cout << "This program finds the roots of a quadratic equation a*(x^2) + b*x + c = 0 .\n";
    float a{};
    std::cout << "Please enter the first coefficient from the range, other than zero [-20..20]: a = ";
    std::cin >> a;
    int attempts{};
    constexpr int min_range{ -20 };
    constexpr int max_range{ 20 };
    constexpr int max_attempts{ 2 };

    //We check the first coefficient in the range and provide three input attempts
    while ((a < min_range) || (a > max_range) || (a == 0)) {

        std::cout << "You entered the wrong number. Try again.\n";
        std::cout << "Please enter the first coefficient again from the range, except for zero [-20..20]: a = ";
        std::cin >> a;
        ++attempts;

        if (attempts >= 2) {

            std::cout << "Sorry, you misused three attempts in a row!\n";
            return 0;
        }
    }

    //If the first coefficient is within the range, then we take the two remaining coefficients
    float b{};
    std::cout << "Please enter the second coefficient from the range [-20..20]: b = ";
    std::cin >> b;
    if ((b < min_range) || (b > max_range)) {

       std::cout << "Coefficient b is out of range!\n";
       return 0;
    }

    float c{};
    std::cout << "Please enter the third coefficient from the range [-20..20]: c = ";
    std::cin >> c;
    if ((c < min_range) || (c > max_range)) {

        std::cout << "Coefficient c is out of range!\n";
        return 0;
    }

    std::cout << "a = " << a << "; " << "b = " << b << "; " << "c = " << c << "." << std::endl;
    constexpr int m1{ 2 };
    constexpr int m2{ 4 };

    //Calculate the discriminant
    double D = b * b - m2 * a * c;
       
    //We check the discriminant against zero and find the roots
    if (D == 0) {

        std::cout << "Answer: x1 = x2 = " << (-b) / (m1 * a) << std::endl;
    }
    else
        if (D > 0) {

            std::cout << "Answer: x1 = " << ((-b) + sqrt(D)) / (m1 * a) << "; " << "x2 = " << ((-b) - sqrt(D)) / (m1 * a) << std::endl;
        }
        else
            std::cout << "The equation has no roots. Discriminant D < 0." << std::endl;
    
    return 0;
}
