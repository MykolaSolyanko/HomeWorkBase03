#include <iostream>

enum funcTypes{
    EXIT,
    REVERSE_STRING,
    AUTO_SORT_ARRAY
};

int32_t inputValueFunc() {
  const uint16_t howManySymbolsIgnore{32768};

  int32_t value{};
  std::cin >> value;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(howManySymbolsIgnore, '\n');
    std::cout << "Wrong number! Please try again later." << std::endl;
    return -1;
  }

  return value;
}

void reverseString() {
    const int maxStringSize{100};
    std::cout << "Please enter size of string. Size must be less than " << maxStringSize << "." << std::endl;
    std::cout << "----->";
    int32_t stringSize = inputValueFunc();
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
    std::cout << "Start typing an elements..." << std::endl;
    int32_t counter{};
    int32_t myArray[maxArraySize]={0};
    while(counter < maxArraySize) {
        int32_t element = inputValueFunc();
        if(counter == 0) {
            myArray[counter++] = element;
            continue;
        }
        myArray[counter++] = element;
        for(int i = 0; i < counter; i++) {
            for(int j = 0; j < counter - i - 1; j++)
            {
                if(myArray[j] > myArray[j + 1]) {
                    std::swap(myArray[j], myArray[j+1]);
                }
            }
        }
    }

    std::cout << "Your sorted array:" << std::endl;
    for(auto elem: myArray) {
        std::cout << elem << " ";
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
        int32_t marker = inputValueFunc();
        switch (marker) {
        case REVERSE_STRING:
            std::cout << std::endl;
            reverseString();
            std::cout << std::endl;
            break;
        case AUTO_SORT_ARRAY:
            std::cout << std::endl;
            autoSortUserArray();
            std::cout << std::endl;
            break;
        case EXIT:
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
