#include <iostream>
#include <cmath>

int main()
{

    long double a {0}; // произвольное число
    long double b {0}; // произвольное число
    long double c {0}; // произвольное число
    constexpr int t {4}; // константа в уравнении

    std:: cout << "Для решения уравнения следующего вида ax2 + bx + c = 0, введите значения a, b, c" << std:: endl;
    std:: cout << "Введите a (не должно равнятся 0)" << std:: endl;
    std:: cin >> a;
    if (a != 0) {
        std:: cout << "Введите b" << std:: endl;
        std:: cin >> b;
        std:: cout << "Введите c" << std:: endl;
        std:: cin >> c;
        
        const long double D {(b*b) - (t*a*c)}; // дискриминант
        
        if (D > 0) {
            long double root1 = static_cast <long double>((sqrt(D) - b) / (2*a)); // первый корень уравнения
            long double root2 = static_cast <long double>((-b - sqrt(D)) / (2*a)); // второй корень уравнения
            
            std:: cout << "Корни квадратного уравнения равны:" << std:: endl;
            std:: cout << "root1 = " << root1 << std:: endl;
            std:: cout << "root2 = " << root2 << std:: endl;
        
        }
        else {
            std:: cout << "Дискриминант оказался отрицательным. Попробуйте ввести значения a, b, c заново." << std:: endl;
        }
    }
    else {
        std:: cout << "Вы ввели 0. Рассчитать квадратное уравнение невозможно. Попробуйте снова" << std:: endl;
    }   
    return 0;
}