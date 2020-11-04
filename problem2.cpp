#include <algorithm>
#include <iostream>

union Arrays {
  uint u[];
  double d[];
  char ch[];
} array;

enum class Data_Type { UINT = 1, DOUBLE = 2, CHAR = 3 };

void fill_array_uint(Arrays &array, const size_t &Size_Array);
void fill_array_double(Arrays &array, const size_t &Size_Array);
void fill_array_char(Arrays &array, const size_t &Size_Array);
bool predicat(char &a, char &b);
void print_array(const Arrays &array, const size_t &Size_Array, Data_Type type);

int main() {
  std::cout << "Enter the size of the sortable array(positive integer)\n";

  size_t size_array{};
  std::cin >> size_array;
  if (!std::cin) {
    std::cout << "incorrect input\n";
    return -1;
  }
  const size_t Size_Array = size_array;

  std::cout << "Choose input data type:\n"
            << "1 - unsigner integer;\n"
            << "2 - double;\n"
            << "3 - characters;\n";

  uint choose{};
  std::cin >> choose;

  Data_Type type_choose = static_cast<Data_Type>(choose);

  switch (type_choose) {
  case Data_Type::UINT:
    fill_array_uint(array, Size_Array);
    std::sort(array.u, array.u + Size_Array);
    print_array(array, Size_Array, type_choose);
    break;
  case Data_Type::DOUBLE:
    fill_array_double(array, Size_Array);
    std::sort(array.d, array.d + Size_Array);
    print_array(array, Size_Array, type_choose);
    break;
  case Data_Type::CHAR:
    fill_array_char(array, Size_Array);
    std::sort(array.ch, array.ch + Size_Array, predicat);
    print_array(array, Size_Array, type_choose);
    break;
  default:
    std::cout << "incorrect input\n";
    return -1;
  }

  return 0;
}

void fill_array_uint(Arrays &array, const size_t &Size_Array) {
  std::cout << "Enter " << Size_Array << " unsigned integers\n";
  for (size_t i = 0; i < Size_Array; ++i) {
    int var{};
    std::cin >> var;
    if (!std::cin || var < 0) {
      std::cout << "incorrect input\n";
      return;
    }
    array.u[i] = var;
  }
}
void fill_array_double(Arrays &array, const size_t &Size_Array) {
  std::cout << "Enter " << Size_Array << " real numbers\n";
  for (size_t i = 0; i < Size_Array; ++i) {
    double var{};
    std::cin >> var;
    if (!std::cin) {
      std::cout << "incorrect input\n";
      return;
    }
      array.d[i] = var;    
  }
}
void fill_array_char(Arrays &array, const size_t &Size_Array) {
  std::cout << "Enter " << Size_Array << " characters\n";
  for (size_t i = 0; i < Size_Array; ++i) {
    char var{};
    std::cin >> var;
    if (!std::cin) {
      std::cout << "incorrect input\n";
      return;
    }
      array.ch[i] = var;    
  }
}

bool predicat(char &a, char &b) {
  if (a >= '0' && a <= '9') {
    return a > b;
  }
  if (b >= '0' && b <= '9') {
    return a > b;
  }
  return a < b;
}

void print_array(const Arrays &array, const size_t &Size_Array,
                 Data_Type type) {
  if (type == Data_Type::UINT) {
    for (size_t i = 0; i < Size_Array; ++i) {
      std::cout << array.u[i] << " ";
    }
  }
  if (type == Data_Type::DOUBLE) {
    for (size_t i = 0; i < Size_Array; ++i) {
      std::cout << array.d[i] << " ";
    }
  }
  if (type == Data_Type::CHAR) {
    for (size_t i = 0; i < Size_Array; ++i) {
      std::cout << array.ch[i];
    }
  }
  std::cout << '\n';
}
