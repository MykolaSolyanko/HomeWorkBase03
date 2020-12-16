#include <algorithm>
#include <iostream>

enum Data_Type { UINT = 1, DOUBLE = 2, CHAR = 3 };

template <typename T>
void fill_array(T array[], const uint16_t &Size_Array) {
  std::cout << "Please enter " << Size_Array << " unsigned integers\n";
  for (size_t i = 0; i < Size_Array; ++i) {
    T val{};
    std::cin >> val;
    if (!std::cin) {
      std::cout << "incorrect input\n";
      return;
    }
    array[i] = val;
  }
}

template <typename T>
void print_array(const T array[], const uint16_t &Size_Array) {
  for (size_t i = 0; i < Size_Array; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

bool compare_char(char &a, char &b) {
  if (a >= '0' && a <= '9') {
    return a > b;
  }
  if (b >= '0' && b <= '9') {
    return a > b;
  }
  return a < b;
}

int main() {
  constexpr uint16_t Size_Array{10};

  std::cout << "Choose input data type:\n"
            << Data_Type::UINT << " - unsigner integer;\n"
            << Data_Type::DOUBLE << " - double;\n"
            << Data_Type::CHAR << " - characters;\n";

  uint type_choose{};
  std::cin >> type_choose;

  switch (type_choose) {
  case Data_Type::UINT:
    uint array_uint[Size_Array];
    fill_array(array_uint, Size_Array);
    std::sort(array_uint, array_uint + Size_Array);
    print_array(array_uint, Size_Array);
    break;
  case Data_Type::DOUBLE:
    double array_double[Size_Array];
    fill_array(array_double, Size_Array);
    std::sort(array_double, array_double + Size_Array);
    print_array(array_double, Size_Array);
    break;
  case Data_Type::CHAR:
    char array_char[Size_Array];
    fill_array(array_char, Size_Array);
    std::sort(array_char, array_char + Size_Array, compare_char);
    print_array(array_char, Size_Array);
    break;
  default:
    std::cout << "incorrect input\n";
    return -1;
  }

  return 0;
}
