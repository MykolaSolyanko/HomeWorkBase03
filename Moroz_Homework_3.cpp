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

int main() {

    reverseString();
    return 0;
}
