#include <iostream>
#include <utility>

void reverse() { // Написать программу revers для строки(частая задача на собеседовании)
    std::cout << "\n\t\t REVERSE \n\n";

    std::cout
        << "Enter some words --> "; // char words[20]; and strlen(words) for char.
    std::string words;
    std::cin >> words;
    std::cout << "Result --> ";
    for (int i = words.length(); 0 <= i; --i) {
        std::cout << words[i];
    }
    std::cout << std::endl;
}


void sort() { // Написать программу вставки элемента в массив(задача сортировка при вводе элемента)
    std::cout << "\n\t\tSORT ARRAY\n\n";

    int numbers[5]{ 0, 0, 0, 0, 0 };
    int x{};
    while (x < 5) {
        std::cout << "Enter number --> ";
        std::cin >> numbers[x];
        for (int i = 0; i < 5; i++) {
            if (numbers[i] > numbers[x]) {
                std::swap(numbers[i], numbers[x]);
            }
        }
        ++x;
        std::cout << "array[";
        for (int j = 0; j < 5; j++) {
            std::cout << numbers[j];
            if (j < 4) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n\n";
    }
}

void deleting() { // Написать программу удаление элемента с массива

    std::cout << "\n\t\t\tDeleting \n\n"; 
    int numbers[5]{};
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter numbers to array. --> ";
        std::cin >> numbers[i];
        for (int j = 0; j < 5; ++j) {
            std::cout << numbers[j] << "  ";
        }

        std::cout << std::endl;
    }

    std::cout << "What number you want to delete from array? --> ";
    int del{};
    while (true) {
        int sum{};
        std::cin >> del;

        for (int i = 0; i < 5; ++i) {
            if (del == numbers[i]) {
                numbers[i] = 0;
                break;
            }
        }
        for (int j = 0; j < 5; ++j) {
            std::cout << numbers[j] << "  ";
        }

        std::cout << std::endl;
        for (int k = 0; k < 5; ++k) {
            sum += numbers[k];
        }
        if (sum == 0)
            break;
        else if (sum != 0)
            sum = 0;

    }
    std::cout << "Array is empty. Programm closed.\n";
}

void toupper() { // Написать программу перевода символов в верхний регист(аналог функции to_upper)
    std::cout << "\n\t\tTOUPPER\n\n";
    std::cout << "Enter some words --> ";

    std::string words; // char words[30]; and strlen(words)
    std::cin >> words;
    std::cout << "Result --> ";
    for (int i = 0; i < words.length(); ++i) {
        if (words[i] < 97 || words[i] > 172) {
            std::cout << words[i];
        }
        else {
            words[i] -= 32;
            std::cout << words[i];
        }
    }
    std::cout << std::endl;
}

void find_numbers() { // Проверить являеться ли введеный символ числом(аналог функции is_diget)
    std::cout << "\n\t\tFIND NUMBERS\n\n";

    std::cout << "Enter some numbers and words --> ";
    std::string words; // char words[20]; and strlen(words) for char.
    std::cin >> words;
    std::cout << "Numbers --> ";
    for (int i = 0; i < words.length(); ++i) {

        if (words[i] > 47 && words[i] < 58) {
            std::cout << words[i];
        }
        if (words[i] > 47 && words[i] < 58 && i + 1 < words.length()) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

void tolower() { // Написать программу перевода символов в верхний регист(аналог функции to_lower)
    std::cout << "\n\t\tTOLOWER\n\n";
    std::cout << "Enter some words --> ";

    std::string words; // char words[30]; and strlen(words)
    std::cin >> words;
    std::cout << "Result --> ";
    for (int i = 0; i < words.length(); ++i) {
        if (words[i] < 65 || words[i] > 90) {
            std::cout << words[i];
        }
        else {
            words[i] += 32;
            std::cout << words[i];
        }
    }
    std::cout << std::endl;
}


int main() {

    std::cout
        << "What programm you want to choose? \n1 - reverse, 2 - sort array, 3 - "
        "find numbers, 4 - tolower, 5 - toupper, 6 - deleting from array.\nEnter number to pick. --> ";
    int choice{};
    while (true) {

        std::cin >> choice;
        if (choice == 666) {
            return 0;
        }

        switch (choice) {
        case 1: {
            reverse();
            break;
        }
        case 2: {
            sort();
            break;
        }
        case 3: {
            find_numbers();
            break;
        }
        case 4: {
            tolower();
            break;
        }
        case 5: {
            toupper();
            break;
        }
        case 6: {
            deleting();
            break;
        }
        default: {
            std::cout << "\nIncorrect number!" << std::endl;
        }
        }
        std::cout << "\nWhat programm you wanna run? \n1 - reverse, 2 - sort array, 3 - "
            "find numbers, 4 - tolower, 5 - toupper, 6 - deleting from array. \nIf you want to exit from programm enter \"666\" --> ";
    }


    system("pause");
    return 0;
}
