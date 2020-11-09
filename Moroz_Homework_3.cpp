#include <iostream>

void reverseString() {
    const int maxStringSize{100};
    std::cout << "Please enter size of string. Size must be less than " << maxStringSize << "." << std::endl;
    std::cout << "----->";
    int stringSize{};
    std::cin >> stringSize;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32768, '\n');
        std::cout << "Wrong number! Please try again later." << std::endl;
        return;
    }
    if(stringSize > maxStringSize) {
        std::cout << "Your size is larger than maximum size" << std::endl;
        return;
    }
    std::cout << "Please enter string." << std::endl;
    char string[stringSize];
    std::cin >> string;

    std::cout << "Your string : " << string << "." << std::endl;

    char * lastElementPtr = &string[stringSize - 1];

    std::cout << "Your reversed string : ";
    while(string != lastElementPtr) {
        std::cout << *lastElementPtr--;
    }
    std::cout << *lastElementPtr << std::endl;
}

void autoSortUserArray() {
    const int maxArraySize{10};
    std::cout << "Start typing a elements..." << std::endl;
    int counter{};
    int myArray[maxArraySize]={0};
    while(counter < maxArraySize) {
        int element{};
        std::cin >> element;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32768, '\n');
            std::cout << "Wrong number! Please try again later." << std::endl;
            return;
        }
        if(counter == 0) {
            myArray[counter++] = element;
            continue;
        }
        if(element < myArray[counter-1]) {
            int tmp = myArray[counter-1];
            myArray[counter-1] = element;
            myArray[counter++] = tmp;
        }else {
            myArray[counter++] = element;
        }
    }

    std::cout << "Your sorted array:" << std::endl;
    for(int i = 0; i < maxArraySize; i++) {
        std::cout << myArray[i];
    }

    std::cout << std::endl;
}

int main() {

    while (true) {
        std::cout << "Choose your function. Enter one of the numbers below. To "
                     "exit enter -1."
                  << std::endl;
        std::cout << "1 - Reverse string." << std::endl;
        std::cout << "2 - Sort array." << std::endl;
        std::cout << "-----> ";
        int16_t marker{};
        std::cin >> marker;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32768, '\n');
            std::cout << "Wrong number! Please try again later." << std::endl;
        }
        switch (marker) {
        case 1:
            std::cout << std::endl;
            reverseString();
            std::cout << std::endl;
            break;
        case 2:
            std::cout << std::endl;
            autoSortUserArray();
            std::cout << std::endl;
            break;
        case -1:
            std::cout << std::endl;
            std::cout << "Bye!" << std::endl;
            return 0;
        default:
            std::cout << std::endl;
            std::cout << "This function is not presented." << std::endl;
            std::cout << std::endl;
            break;
        }
    }

    return -1;
}
