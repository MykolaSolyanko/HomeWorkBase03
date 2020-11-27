#include <iostream>

class Array {
public:
    void show_array() {
        if (index < 1) {
            std::cout << "Your array is empty, please full it" << std::endl;
        }
        else {
            std::cout << "Your array is " << std::endl;
            for (int i = 0; i < index; ++i) {
                std::cout << array[i] << "\t";
            }
        }
    }
    void add_element(int element) {
        if (index < 4) {
            array[index] = element;
            ++index;
        }
    }
    void delete_element() {
        if (index > 0) {
            std::cout << "What is element that you want to delete?" << std::endl;
            int digit{};
            std::cin >> digit;
            for (int i = 0; i < 4; ++i) {
                if (array[i] == digit) {
                    array[i] = 0;
                    break;
                }
            }
        }
    }
    void find_element() {
        if (index > 0) {
            std::cout << "What element do you want to find?" << std::endl;
            int find{};
            std::cin >> find;
            for (int i = 0; i < 4; ++i) {
                if (array[i] == find) {
                    std::cout << array[i] << std::endl;
                }
            }
        }
    }

private:
    int array[4];
    int index{};
};

int main() {
    Array a{};
    while (true) {
        std::cout << "Please choose the command, which you want to execute:"
            << std::endl;
        std::cout << "1. Find element" << std::endl;
        std::cout << "2. Add the element to you array." << std::endl;
        std::cout << "3. Delete the element from your array." << std::endl;
        std::cout << "4. Show your array." << std::endl;
        std::cout << "0. Exit" << std::endl;

        int command{};
        std::cin >> command;
        switch (command) {
        case 1: {
            a.find_element();
            std::cout << std::endl;
        }
        case 2: {
            std::cout << "What digit do you want to add?" << std::endl;
            int element{};
            std::cin >> element;
            a.add_element(element);
            std::cout << std::endl;
            break;
        }
        case 3: {
            a.delete_element();
            std::cout << std::endl;
            break;
        }
        case 4: {
            a.show_array();
            std::cout << std::endl;
            break;
        }
        case 0: {
            return -1;
        }
        default: {
            std::cout << "You entered incorrect command,please try again"
                << std::endl;
            break;
        }
        }
    }
    return 0;
}
