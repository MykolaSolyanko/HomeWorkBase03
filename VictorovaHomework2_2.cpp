#include <iostream>

int main() {
    int array[50];
    constexpr int kMinRange{ -60 };
    constexpr int kMaxRange{ 90 };

    std::cout << "Please, enter values in the range from" << kMinRange << "to"
        << kMaxRange << "inclusive" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::cin >> array[i];

        if (array[i] < kMinRange || array[i] > kMaxRange) {
            std::cout << "Value is out of range" << std::endl;
            return -1;
        }
        else {
            std::cout << "Array=" << array[i] << std::endl;
        }
    }
    int sum{};
    for (int i = 0; i < 50; i++) {
        if (array[i] % 2 != 0) {
            sum += array[i];
        }
    }
    std::cout << "Sum=" << sum << std::endl;
    return 0;
}
