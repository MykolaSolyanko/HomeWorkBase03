#include <iostream>

int main() {
	std::cout << "Enter number --> ";
	int num{};
	std::cin >> num;
	if (num % 2 == 0) {
		num += 1;
	}

	for (int i = 0; i < num; i +=2 ) {
		for (int k = num-1; k > i; k-=2) {
			std::cout << " ";
		}
		for (int j = 0; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}
