//Посчитать сумму и среднее арифметическое цифр в числе
//Calculate the sum and arithmetic mean of digits in a number
#include <iostream>
#include <cmath>

int main() {

	std::cout << "This program calculate the sum and arithmetic mean of digits in a number.\n";
	int number{};
	std::cout << "Enter, please, integer number. Number = ";
	std::cin >> number;
	float sum{};
	int counter_numb{};
	while (number >= 1) {

		++counter_numb;
		sum = sum + (number % 10);
		number = number / 10;

	};

	std::cout << "Total: sum = " << sum << std::endl;
	std::cout << "Counter numbers:  = " << counter_numb << std::endl;
	std::cout << "Average of numbers = " << sum / counter_numb << std::endl;

	std::cout << '\n';

//Счастливый билетик
//Search lucky ticket

	std::cout << "This program search lucky ticket.\n";
	int number_ticket{};
	std::cout << "Enter, please, six integer numbers. Number = ";
	std::cin >> number_ticket;

	constexpr int right_counter_numbers{ 6 };
	int counter_numbers{};
	int number2{ number_ticket };
	int number3{ number_ticket };

	//cycle 1 -- we count amount of numbers
	while (number_ticket >= 1) {
		++counter_numbers;
		number_ticket = number_ticket / 10;
	}

	if (counter_numbers != right_counter_numbers) {
		std::cout << "You entered wrong amount of numbers!\n";
	}
	else {
		//count sum first 3 numbers
		int sum1{};
		for (int count1{}; count1 < 3; count1++) {
			sum1 = sum1 + (number2 % 10);
			number2 = number2 / 10;
		}

		//count sum last 3 numbers
		int sum2{};
		for (int count2{}; count2 < 3; count2++) {
			sum2 = sum2 + (number2 % 10);
			number2 = number2 / 10;
		}

		std::cout << number3 << " is " << (sum1 == sum2 ? "happy" : "unhappy") << " ticket\n";

	}

	std::cout << '\n';

//Обратные числа
//Make reverse number

	std::cout << "This program make reverse number.\n";
	int number1{};
	std::cout << "Enter, please, integer number. Number = ";
	std::cin >> number1;

	bool sign_number{ number1 < 0 }; //for save sign of number
	number1 = abs(number1); // we work with positive number in cycle
	int count_numbers{};
	int numb2{ number1 }; //in cycle 1 value of number will change therefore we need a new variety for cycle 2

	//cycle 1 -- we count amount of numbers
	while (number1 >= 1) {

		++count_numbers;
		number1 = number1 / 10;

	};

	std::cout << "Counter numbers:  = " << count_numbers << '\n';

	int reverse_number{};

	//cycle2 -- we make reverse number
	while (count_numbers > 0) {

		reverse_number = reverse_number + ((numb2 % 10) * pow(10, (count_numbers - 1)));
		numb2 = numb2 / 10;
		--count_numbers;

	};

	std::cout << "Reverse number: = " << (sign_number ? -reverse_number : reverse_number) << '\n';

	std::cout << '\n';

//Сумма нечетных элементов
//Sum of odd elements

	std::cout << "This program counts the sum of odd items.\n";
	std::cout << "Enter the number of elements in the range [1..50] : ";
	int iNumber_elem{};
	std::cin >> iNumber_elem;
	if (iNumber_elem < 1 || iNumber_elem > 50) {

		std::cout << "You entered wrong number of items " << iNumber_elem << '\n';
		return 0;
	}

	std::cout << "Enter " << iNumber_elem << " integer numbers from range [-60 .. 90].\n";
	int iGet_elem{};
	int iSum_odd_elem{};
	while (iNumber_elem != 0) {

		std::cin >> iGet_elem;
		if (iGet_elem < -60 || iGet_elem > 90) {

			std::cout << "You entered wrong number " << iGet_elem << '\n';
			return 0;
		}
		if (iGet_elem % 2 != 0) {

			iSum_odd_elem += iGet_elem;
		}
		--iNumber_elem;
	}

	std::cout << "Sum of odd elements equal: " << iSum_odd_elem << '\n';

	std::cout << '\n';

//Вывод ёлочки на экран консоли
//Build christmas tree

	std::cout << "This program build christmas tree by stars.\n";
	int number_star{};
	std::cout << "Please, enter number of stars: ";
	std::cin >> number_star;

	//if an even number is entered, then add 1
	if ((number_star % 2) == 0) {
		++number_star;
	}

	int position_column{ 0 };
	int center_range = number_star / 2;
	const int max_raw = number_star - (number_star / 2);

	for (int position_raw{ 0 }; position_raw < max_raw; position_raw++) {

		for (position_column; position_column < number_star; position_column++) {

			if ((position_column < (center_range - position_raw)) || (position_column > (center_range + position_raw))) {
				std::cout << " ";
			}
			else std::cout << "*";

		}
		position_column = 0;
		std::cout << "\n";

	}

	std::cout << '\n';

//Посчитать количество установленых битов в числе
//Program count the amount of set bits

	std::cout << "This program count the amount of set bits.\n";
	int iValue{};
	std::cout << "Enter number: ";
	std::cin >> iValue;

	int iCounter{};
	while (iValue != 0) {

		if (iValue & 1) {
			++iCounter;
		}

		iValue >>= 1;

	}

	std::cout << "Amount of set bits: " << iCounter << '\n';

	std::cout << '\n';

//Установлен ли бит
//Check installed bit in some number

	std::cout << "This program check installed bit in some number.\n";
	uint32_t iNumber{};
	uint16_t iBit_number{};
	std::cout << "Enter number: ";
	std::cin >> iNumber;
	std::cout << "Enter bit number: ";
	std::cin >> iBit_number;

	((iNumber >> (iBit_number - 1)) & 1) ? std::cout << "Yes\n" : std::cout << "No\n";

	return 0;

}
