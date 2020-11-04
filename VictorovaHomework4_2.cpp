#include <cctype>
#include <iostream>
#include <random>
#include <time.h>

void Sort_u(unsigned int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                std::swap(arr[j + 1], arr[j]);
            }
        }
    }
}
void Sort_d(double* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                std::swap(arr[j + 1], arr[j]);
            }
        }
    }
}
void Sort_c(char* arr_3, size_t size) {
    for (int i = 0; i < size; i++) {
        if (isupper(arr_3[i])) {
            std::cout << arr_3[i] << "\t";
        }
    }
    for (int i = 0; i < size; i++) {
        if (islower(arr_3[i])) {
            std::cout << arr_3[i] << "\t";
        }
    }
}

int main() {
    const int size{ 4 };
    unsigned int arr[size];
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, 50);
    for (int i = 0; i < size; i++) {

        arr[i] = uid(gen);
    }
    std::cout << "Your array" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
        std::cout << arr[i] << "\t";
    }
    Sort_u(arr, std::size(arr));
    std::cout << std::endl << "Your array after sort" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
        std::cout << arr[i] << "\t";
    }
    double arr_2[size];
    std::cout << std::endl << "Please, fill your array" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr_2[i];
    }
    std::cout << std::endl << "Your array" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
        std::cout << arr_2[i] << "\t";
    }
    Sort_d(arr_2, std::size(arr_2));
    std::cout << std::endl << "Your array after sort" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
        std::cout << arr_2[i] << "\t";
    }
    char arr_3[size];
    std::cout << std::endl << "Please, fill your array" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr_3[i];
    }
    std::cout << std::endl << "Your array" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
        std::cout << arr_3[i] << "\t";
    }
    std::cout << std::endl << "Your array af sort" << std::endl;
    Sort_c(arr_3, std::size(arr_3));
}
