//1
#include <iostream>
void Reverse(char *array, int size) {
  for (int i = size - 1; i >= 0; i--) {
    std::cout << array[i];
  }
}

int main() {
  char array[10];
  std::cin >> array;
  Reverse(array, std::size(array));
}

//2
#include <iostream>

int main() {
    const int size{ 4 };
    int mas[size]{};

    std::cin >> mas[0];
    std::cout << "Your array " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << "\t";
    }
    std::cin >> mas[1];
    if (mas[0] > mas[1]) {
        std::swap(mas[1], mas[0]);
    }
    std::cout << "Your array " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << "\t";
    }
    std::cin >> mas[2];
    if (mas[2] < mas[1]) {
        std::swap(mas[2], mas[1]);

        std::swap(mas[1], mas[0]);
    }
    if (mas[2] < mas[0]) {
        std::swap(mas[1], mas[0]);
        std::swap(mas[2], mas[1]);
    }

    std::cout << "Your array " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << "\t";
    }
    std::cin >> mas[3];
    if (mas[3] < mas[2]) {
        std::swap(mas[3], mas[2]);
        std::swap(mas[2], mas[1]);
        std::swap(mas[1], mas[0]);
    }
    if (mas[3] < mas[1]) {
        std::swap(mas[3], mas[1]);
    }
    if (mas[3] < mas[0]) {
        std::swap(mas[3], mas[0]);
    }

    std::cout << "Your array " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << "\t";
    }

    return 0;
}
