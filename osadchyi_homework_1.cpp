#include <iostream>
#include <cmath>

int main()
{
    int a{};
    int b{};
    int c{};
    double x_1{};
    double x_2{};
    double discr{};
    bool a_range{};
    bool b_range{};
    bool c_range{};

    std::cout << "Enter three numbers in range 2...255 separated by space in order a b c.\nIf value is empty leave 0." << std::endl;

    while(true){
        std::cin >> a >> b >> c;
        a_range = a >= 2 & a <= 255;
        b_range = b >= 2 & b <= 255;
        c_range = c >= 2 & c <= 255;

        if (!(a_range & b_range & c_range))
            std::cout << "One of your values is out of range. Please, please try again" << std::endl;
        else break;
    }

    discr = b*b - 4*a*c;
    if (discr >= 0){
        x_1 = (-b + std::sqrt((b*b) - 4*a*c)) / (2*a);
        x_2 = (-b - std::sqrt((b*b) - 4*a*c)) / (2*a);

        std::cout << "x1 = " << x_1 << std::endl;
        std::cout << "x2 = " << x_2 << std::endl;
    }
    else if (discr == 0){
        x_1 = -(b/2*a);

        std::cout << "x1 = x2 = " << x_1 << std::endl;
    }
    else{
        std::cout << "Discriminant < 0. The equation does not have solutions." << std::endl;
    }

}
