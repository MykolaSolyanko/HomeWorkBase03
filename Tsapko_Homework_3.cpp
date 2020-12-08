// PZ_3_1 Reverse symbols

#include <iostream>

int main() {

    std::string symbols_right{};
    std::cout << "This program do reverse of entered symbols." << std::endl;
    std::cout << "Enter symbols: ";
    std::cin >> symbols_right;
    std::cout << "Number of symbols: " << symbols_right.size() << std::endl;

    int len_array{};
    len_array = symbols_right.size();

    std::cout << "Reverse string is ";
    while (len_array != -1) {

        std::cout << symbols_right[len_array];       
        --len_array;
    }
 
    std::cout << '\n';


    // PZ_3_2 Sorting items

    constexpr unsigned int iArr_size{ 6 };
    std::cout << "This program sorting " << iArr_size << " items.\n";
    int iArr[iArr_size]{};
    int value{};
    bool priznak{};

    std::cout << "Enter " << iArr_size << " numbers from range [-500 .. 500]: " << '\n';
    std::cin >> iArr[0]; //Записываем первый элемент в массив

    if ((iArr[0] < -500) || (iArr[0] > 500)) {
        std::cout << "You entered wrong number: " << iArr[0] << '\n';
        return 0;
    }

    //Цикл приема оставшихся элементов 
    for (int k{ 1 }; k < iArr_size; k++) {

        std::cin >> value;
        if ((value < -500) || (value > 500)) {
            std::cout << "You entered wrong number: " << value << '\n';
            return 0;
        }

        /*Изначально все элементы массива были инициализированы нулем, поэтому мы сравниваем введенное
        значение value только с записанными в массив элементами, т. е. начиная с нулевого элемента массива
        до номера равного последнему введенному значению value. Оставшиеся элементы массива пока равны нулю.
        */
        for (int i{}; i < k; i++) {

            if (iArr[i] > value) {

                priznak = true; //Признак того, что value меньше одного из элементов массива

                //Это цикл для смещения элементов массива больших, чем значение value
                for (int t{ iArr_size - 1 }; t > i; t--) {

                    iArr[t] = iArr[t - 1];
                }

                iArr[i] = value;
                break; //Чтобы не продолжать цикл до конца
            }
        }

        /*Если введенное value оказалось больше всех записанных элементов в массив,
        то присваиваем его следующему элементу массива*/
        if (priznak != 1) {

            iArr[k] = value;
        }

        priznak = false; //Обнуляем признак, чтобы опять видеть value больше записанных элементов массива или нет
    }

    std::cout << '\n';

    for (int i{}; i < iArr_size; i++) {

        std::cout << iArr[i] << '\n';
    }

    std::cout << '\n';


    // PZ_3_3 Do upper of entered symbols

    std::cout << "This program do upper of entered symbols." << '\n';
   
    constexpr int iLow_min{ 'a' };
    constexpr int iLow_max{ 'z' };
    constexpr int iDiff_l_high{ 32 };
    std::string symbols_inp{};

    std::cout << "Enter symbols: ";
    std::cin >> symbols_inp;
    std::cout << "Number of symbols: " << symbols_inp.size() << std::endl;

    std::cout << "Upper symbols: ";
    for (unsigned int i{}; i < symbols_inp.size(); i++) {
        if ((static_cast<int>(symbols_inp[i]) >= iLow_min) && (static_cast<int>(symbols_inp[i]) <= iLow_max)) {

            symbols_inp[i] -= iDiff_l_high;
        }

        std::cout << symbols_inp[i];
    }

    std::cout << '\n';


    // PZ_3_4 Do lower of entered symbols

    std::cout << "This program do lower of entered symbols." << '\n';

    constexpr int iHigh_min{ 'A' };
    constexpr int iHigh_max{ 'Z' };
    constexpr int iDiff_low_high{ 32 };
    std::string symbols_input{};

    std::cout << "Enter symbols: ";
    std::cin >> symbols_input;
    std::cout << "Number of symbols: " << symbols_input.size() << std::endl;
   
    std::cout << "Upper symbols: ";
    for (unsigned int i{}; i < symbols_input.size(); i++) {
        if ((static_cast<int>(symbols_input[i]) >= iHigh_min) && (static_cast<int>(symbols_input[i]) <= iHigh_max)) {

            symbols_input[i] += iDiff_low_high;
        }

        std::cout << symbols_input[i];
    }

    std::cout << '\n';


    // PZ_3_5 Search digits in string

    std::cout << "This program search digits in string." << '\n';

    constexpr int iDigit_min{ '0' };
    constexpr int iDigit_max{ '9' };
    std::string symbols_in{};

    std::cout << "Enter symbols: ";
    std::cin >> symbols_in;
    std::cout << "Number of symbols: " << symbols_in.size() << std::endl;
    
    std::cout << "Digits is  ";
    for (unsigned int i{}; i < symbols_in.size(); i++) {
        if ((static_cast<int>(symbols_in[i]) >= iDigit_min) && (static_cast<int>(symbols_in[i]) <= iDigit_max)) {

            std::cout << symbols_in[i] << ", ";
        }
    }

    return 0;
}
