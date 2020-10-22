#include <iostream>

// ODR 

void print_data();

static void internal() {
    std::cout << " 1" << std::endl;
}

// make ninja 
// CMake

int main(int argc, char const *argv[]) {

    // auto res = add(1, 2, 100);
    // std::cout << res << std::endl;
    // res = sub(2, 1);
    // std::cout << res << std::endl;
    print_data();
    internal();
    return 0;
}
