#include <iostream>
#include <cmath>

/*
ax2 + bx + c = 0
*/

int main(int argc, char const* argv[]) {
	constexpr int16_t kMinRange{ 2 };
	constexpr int16_t kMaxRange{ 255 };
	std::cout << "To solve a quadratic equation \n\tA*X^2+B*X+C=0\n";
	std::cout << R"(To solve a quadratic equation
            A*X^2+B*X+C=0
)";
	std::cout << "Please, enter integers A, B and C ( in the range from 2 to 255)\n";

	std::cout << "A = ";
	int32_t a{};
	std::cin >> a;
	if ((a == 0) || (a < kMinRange) || (a > kMaxRange)) {
		std::cerr << "Wrong initial value\n";
		return -1;
	}

	std::cout << "B = ";
	int32_t b{};
	std::cin >> b;
	if (b < kMinRange || b > kMaxRange) {
		std::cerr << "Wrong initial value\n";
		return -1;
	}

	std::cout << "C = ";
	int32_t c{};
	std::cin >> c;
	if (c < kMinRange || c > kMaxRange) {
		std::cerr << "Wrong initial value\n";
		return -1;
	}

	const long long kD = (b * b) - (4 * a * c);

	if (kD < 0) {
		std::cerr << "Error \n";
		return -1;
	}


	const auto k2a = 2 * a;

	const long double kX1 = (-b + sqrt(kD)) / k2a;
	const long double kX2 = (-b - sqrt(kD)) / k2a;

	std::cout << " x1 =" << kX1 << " x2 = " << kX2 << std::endl;
	return 0;
}

