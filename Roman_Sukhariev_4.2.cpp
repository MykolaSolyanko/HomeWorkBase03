#include <array>
#include <cmath>
#include <iostream>
#include <limits>

static void sort(std::array<unsigned int, 5> &array) {
  for (size_t index = 0; index < array.size(); ++index) {
    for (size_t j = array.size() - 1; j > index; --j) {
      if (array[j - 1] > array[j]) {
        unsigned int tmp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = tmp;
      }
    }
  }
  return;
}
static void sort(std::array<double, 5> &array) {
  for (size_t index = 1; index < array.size(); ++index) {
    for (size_t j = array.size() - 1; j >= index; --j) {
      bool flag = std::fabs(array[j - 1] - array[j]) <=
                  std::numeric_limits<double>::epsilon();
      if (!flag && (array[j - 1] > array[j])) {
        double tmp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = tmp;
      }
    }
  }
  return;
}
static void sort(char array[], size_t kSize) {
  for (size_t index = 1; index < kSize; ++index) {
    for (size_t j = index; j > 0 && array[j - 1] > array[j]; --j) {
      char tmp = array[j];
      array[j] = array[j - 1];
      array[j - 1] = tmp;
    }
  }
  for (;;) {
    size_t begin{0};
    size_t end{kSize - 1};
    char tmp{0};
    if (array[begin] < 'A') {
      tmp = array[begin];
    } else {
      break;
    }
    for (size_t index = 1; index < kSize; ++index) {
      array[index - 1] = array[index];
    }
    array[end] = tmp;
  }
  return;
}
int main() {
  std::cout << "Enter the type of data you want to use" << '\n';
  std::cout << "Print 'u' for unsigned int" << '\n';
  std::cout << "Print 'd' for double" << '\n';
  std::cout << "Print 'c' for char" << '\n';
  char type{0};
  std::cin >> type;
  constexpr size_t kSize{5};
  if (type == 'u') {
    std::array<unsigned int, kSize> array{};
    std::cout << "Fulfill the array by numbers (5 numbers)" << '\n';
    for (size_t index = 0; index < array.size(); ++index) {
      if (!(std::cin >> array[index]) || array[index] == 0) {
        std::cerr << "Wrong data. Try again" << '\n';
        return 0;
      }
    }
    sort(array);
    std::cout << "Here is your array" << '\n';
    for (unsigned int elem : array) {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  } else if (type == 'd') {
    std::cout << "Fulfill the array by numbers" << '\n';
    std::array<double, kSize> array{};
    for (size_t index = 0; index < array.size(); ++index) {
      if (!(std::cin >> array[index])) {
        std::cerr << "Wrong data. Try again" << '\n';
      }
    }
    sort(array);
    std::cout << "Here is your array" << '\n';
    for (double elem : array) {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  } else if (type == 'c') {
    std::cout << "Enter your string" << '\n';
    char array[kSize]{};
    std::cin >> array;
    sort(array, kSize);
    std::cout << "Here is your array" << '\n';
    for (char elem : array) {
      std::cout << elem;
    }
    std::cout << '\n';
  } else {
    std::cerr << "Wrong data. Try again" << '\n';
    return 0;
  }
  return 0;
}