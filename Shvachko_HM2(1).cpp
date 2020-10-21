// sum and average
#include <iostream>

unsigned getSumAver(unsigned value, unsigned value1) {
    unsigned result = value % 10;
    unsigned amount = 1;

    while ((value /= 10) && (value1 /=10)) {
        result += value % 10;
        amount++;
    }
    std::cout<< "Sum of value = " << result;
    std::cout << "Average of value = " ;
    return (result,amount);
}


int main() {
    std::cout << "Program comput of amount, average value\n";
    unsigned n = 12345;
    std::cout << getSumAver(n,n) << std::endl;
    return 0;
}
