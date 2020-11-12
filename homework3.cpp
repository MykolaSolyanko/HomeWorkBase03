#include <iostream>

int get_str_len(char* str) {
    int count{};
    while (str[count] != '\0') {
        ++count;
    }

    return count;
}

void reverse_str() {
    constexpr int arr_len{ 100 };
    char str[arr_len];
    std::cout << "Enter a string: ";
    std::cin >> str;

    int str_len = get_str_len(str);
    int count = 0;
    char rev_str[arr_len];
    while (str_len > 0) {
        rev_str[count++] = str[--str_len];
    }

    std::cout << "Reversed string is ";
    for (int i = 0; str[i] != '\0'; ++i) {
        std::cout << rev_str[i];
    }
    std::cout << std::endl;
}


bool is_dgt(char var) {
    int dec_v = static_cast<int>(var);
    constexpr int lwr_ascii_dec_lim = 48;
    constexpr int uppr_ascii_dec_lim = 57;
    if (dec_v >= lwr_ascii_dec_lim && dec_v <= uppr_ascii_dec_lim) {
        return true;
    }
    return false;
}
void to_uppr() {
    constexpr int arr_len{ 100 };
    char arr[arr_len];
    std::cout << "Enter a string: ";
    std::cin >> arr;
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (is_dgt(arr[i])) {
            arr[i] = arr[i];
        }
        else {
            arr[i] = arr[i] & '_';
        }
    }

    std::cout << "Result string in upper case: ";
    for (int i = 0; arr[i] != '\0'; i++) {
        std::cout << arr[i];
    }
}

void to_lwr() {
    constexpr int arr_len{ 100 };
    char arr[arr_len];
    std::cout << "Enter a string: ";
    std::cin >> arr;
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (is_dgt(arr[i])) {
            arr[i] = arr[i];
        }
        else {
            arr[i] = arr[i] | ' ';
        }
    }

    std::cout << "Result string in lower case: ";
    for (int i = 0; arr[i] != '\0'; i++) {
        std::cout << arr[i];
    }
}

void remove_elmtn() {
    constexpr int arr_len{ 5 };
    int arr[arr_len];

    std::cout << "Enter " << arr_len << " numbers: ";
    for (int i = 0; i < arr_len; i++) {
        std::cin >> arr[i];
    }
    int elmnts_deleted{};

    while (elmnts_deleted != arr_len) {
        bool present = false;
        int num{};
        std::cout << "Enter a number which you want to delete from array: ";
        std::cin >> num;
        for (int j = 0; j < arr_len; j++) {
            if (num == arr[j]) {
                std::cout << "Element " << num << " is removed from array" << std::endl;
                arr[j] = '-';
                elmnts_deleted++;
                present = true;
                break;
            }
        }
        if (!present) {
            std::cout << "Sorry, element " << num << " is not presented in array"
                << std::endl;
        }
    }
}

void insert_elem() {
    constexpr int arr_len{ 5 };
    int arr[arr_len]{};
    for (int i = 0; i < arr_len; ++i) {
        int val{};
        std::cout << "Enter a number: ";
        std::cin >> val;
        for (int j = 0; j < arr_len; ++j) {
            std::cout << val;
            if (arr[j] == 0) {
                arr[j] = val;
                break;
            }
            else if (val < arr[j]) {

                int tmp = arr[j];
                arr[j] = val;
                val = tmp;
                j = 0;
            }
        }
        std::cout << "Current array is: ";
        for (int k = 0; k < arr_len; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    // reverse_str();
    // to_uppr();
    // to_lwr();
    // remove_elmtn();
    insert_elem();
    return 0;
}