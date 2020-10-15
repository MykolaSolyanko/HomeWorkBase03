//Посчитать сумму и среднее арифметическое цифр в числе
//Calculate the sum and arithmetic mean of digits in a number
#include <iostream>

int main() {

	int number{};
	std::cout << "Enter, please, integer number. Number = ";
	std::cin >> number;
	int sum{};
	int counter_numbers{};
	while (number >= 1) {

		++counter_numbers;
		sum = sum + (number % 10);
		number = number / 10;

	}

	std::cout << "Total: sum = " << sum << std::endl;
	std::cout << "Counter numbers:  = " << counter_numbers << std::endl;
	std::cout << "Average of numbers = " << sum / counter_numbers << std::endl;
	
	return 0;

}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//Счастливый билетик
//Found lucky ticket
#include <iostream>

int main() {

	int number{};
	std::cout << "Enter, please, integer number. Number = ";
	std::cin >> number;

	int counter_numbers{};
	int number2{ number }; 
	int number3{ number };

	//cycle 1 -- we count amount of numbers
	while (number >= 1) {
		++counter_numbers;
		number = number / 10;
	}

	if (counter_numbers != 6) {
		std::cout << "You entered wrong amount of numbers!\n";
	}
	else {
		//found sum first 3 numbers
		int sum1{};
		int count1{};
		for (count1; count1 < 3; count1++) {
			sum1 = sum1 + (number2 % 10);
			number2 = number2 / 10;
		}

		//found sum last 3 numbers
		int sum2{};
		int count2{};
		for (count2; count2 < 3; count2++) {
			sum2 = sum2 + (number2 % 10);
			number2 = number2 / 10;
		}

		if (sum1 == sum2) {
			std::cout << number3 << " is happy ticket\n";
		}
		else {
			std::cout << number3 << " is unhappy ticket\n";
		}
		
	}
	
	return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//Обратные числа
//Make reverse number
#include <iostream>
#include <cmath>

int main() {

	int number{};
	std::cout << "Enter, please, integer number. Number = ";
	std::cin >> number;

	int sign_number{ number }; //for save sing of number
	number = abs(number); // we work with positive number in cycle
	int counter_numbers{};
	int number2{ number }; //in cycle 1 value of number will change therefore we need a new variety for cycle 2

	//cycle 1 -- we count amount of numbers
	while (number >= 1) {

		++counter_numbers;
		number = number / 10;

	}

	std::cout << "Counter numbers:  = " << counter_numbers << std::endl;

	int reverse_number{};

	//cycle2 -- we find reverse number
	while (counter_numbers > 0) {

		reverse_number = reverse_number + ((number2 % 10) * pow(10, (counter_numbers - 1)));
		number2 = number2 / 10;
		--counter_numbers;

	}

	//we check if enter number was negative than we change sign of reverse_number
	if (sign_number < 0) {
		std::cout << "Reverse number:  = " << (-1) * reverse_number << std::endl;
	}
	else {
		std::cout << "Reverse number:  = " << reverse_number << std::endl;
	}

	return 0;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//Сумма нечетных элементов
//sum of odd elements
#include <iostream>

int main()
{
    
    std::cout << "Please, enter ten elements\n";
    int array_element[10];
    int number_element{};
    int sum{};

    for (number_element; number_element < 10; number_element++) {

        std::cin >> array_element[number_element];
        if ((array_element[number_element] % 2) != 0) {
            sum = sum + array_element[number_element];
        }
    }

    std::cout << "Total sum of odd elements: " << sum << std::endl;

    return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//Вывод ёлочки на экран консоли
//Build christmas tree
#include <iostream>

int main()
{
    int number{};
    std::cout << "Please, enter number: ";
    std::cin >> number;
    int position_raw{0};
    int position_column{0};
    int center_range{0};
    
    //if an even number is entered, then add 1
    if ((number % 2) == 0) {
        ++number;
    }

    center_range = number / 2;
    
    for (position_raw; position_raw <(number - (number / 2)); position_raw++) {

        for (position_column; position_column < number; position_column++) {

            if ((position_column < (center_range - position_raw)) || (position_column > (center_range + position_raw))) {
                std::cout << " ";
            }
            else std::cout << "*";

        }
        position_column = 0;
        std::cout << "\n";

    }
    
	return 0;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//Посчитать количество установленых битов в числе
//Program count the amount of set bits
#include <iostream>

int main()
{
    int value{};
    
    std::cout << "Enter number: ";
    std::cin >> value;
    int set_bit{};

    do {
        if ((value % 2) == 1) {
            ++set_bit;
        }
        value = value / 2;
    } while (value >= 1);
    
    std::cout << "Amount of set bits: " << set_bit << std::endl;

    return 0;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//Установлен ли бит
//Check installed bit in some number
#include <iostream>
#include <bitset>

int main(){
    
    uint16_t number{};
    uint16_t bit_value{};
    std::cout << "Number: ";
    std::cin >> number;
    std::cout << "Bit: ";
    std::cin >> bit_value;

    uint16_t decimal_value{};
    decimal_value = pow(2, (bit_value - 1)); //find value in decimal number system for number installed bit

    std::cout << (number & decimal_value) << std::endl; //for checking
    if ((number & decimal_value) != 0) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //for checking
    std::bitset<16> b{ number };
    std::cout << b.to_string() << std::endl;
    std::bitset<16> b2{ decimal_value };
    std::cout << b2.to_string() << std::endl;

    return 0;

}
