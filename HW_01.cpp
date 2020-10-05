#include <iostream>
#include <cstdint>
#include <cmath>

constexpr int POWER{2};
constexpr int MULTIPLIER{4};

char          name = {'A'};
double        coefficient [3]{};

#define       ARRAY_LEN(x) ( sizeof( coefficient ) / sizeof( coefficient[0] ) )

#define A     coefficient [0]
#define B     coefficient [1]
#define C     coefficient [2]

int main (void) {
    std::cout<<"ax^2 + bx + c = 0"<<std::endl;

    for (uint8_t i = 0; i < ARRAY_LEN(coefficient);) {
        std::cout<<"Please enter number in range [2..255]"<<std::endl;
        std::cout<<name<<"-->";
        std::cin>>coefficient[i];

        if ((coefficient[i] >= 2) && (coefficient[i] <= 255)) {
            i++;
            name++;
        } else {
            std::cout<<"You entered an incorrect number, try entering the number again"<<std::endl;
        }
        
    }

    auto D = pow(B,POWER) - (MULTIPLIER * A * C);
    
    if (D > 0) {
        D = sqrt(D);
        auto x = ((-B) - D) / (POWER * A);
        std::cout<<"x1 = "<< x<<std::endl;

        x = ((-B) + D) / (POWER * A);
        std::cout<<"x2 = "<<x<<std::endl;
    } else if (D == 0) {
        auto x = (-B) / (POWER * A);
        std::cout<<"x = "<<x<<std::endl;
    } else if ( (D < 0) || (D == NAN) || (D == -NAN)) {
         std::cout<<"No roots!"<<std::endl;
    }



    return 0;
}