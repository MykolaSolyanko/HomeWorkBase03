#include <chrono>
#include <iostream>
#include <random>
#include <time.h>
using namespace std::chrono;

void BubbleSort(int *begin, int *end) {
  for (end; end > begin; end--) {
    for (int *p = begin; p < end; p++) {
      if (*p > *end) {
        int temp{};
        temp = *p;
        *p = *end;
        *end = temp;
      }
    }
  }
}

void QuikSort(int *begin, int *end) {
  int middle = (*begin + *end) / 2;
  do {
    while (*begin < middle) {
      *begin++;
    }
    while (*end > middle) {
      *end--;
    }
    if (*begin < *end) {
      int temp{};
      temp = *begin;
      *begin = *end;
      *end = temp;
      *begin++;
      *end--;
    }
  } while (*begin < *end);
}

int main() {
  const int size{4};
  int arr[size];
  int ch{};
  std::cout << "Plese choose, how will fill array?" << std::endl
            << "0-->for Random Input" << std::endl
            << "1--> for User Input" << std::endl;
  std::cin >> ch;
  std::mt19937 gen(time(0));
  std::uniform_int_distribution<> uid(0, 50);
  switch (ch) {
  case (0):

    for (int i = 0; i < size; i++) {

      arr[i] = uid(gen);
    }
    std::cout << "Your array" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
      std::cout << arr[i] << "\t";
    }
    break;
  case (1):
    std::cout << std::endl << "Please, fill your array --->" << std::endl;
    for (int i = 0; i < size; i++) { //ввод масива
      std::cin >> arr[i];
    }
    std::cout << "Your array" << std::endl;
    for (int i = 0; i < size; i++) { //вывод масива
      std::cout << arr[i] << "\t";
    }
    break;
  default:
    std::cout << "Error" << std::endl;
  }
  auto start_1 = std::chrono::steady_clock::now();
  BubbleSort(arr, arr + 3);
  std::cout << std::endl << "Array after bubble sort" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << "\t";
  }
  auto end_1 = std::chrono::steady_clock::now();
  duration<double> sec_1 = end_1 - start_1;
  std::cout << sec_1.count() << " sec" << std::endl;
  auto start_2 = std::chrono::steady_clock::now();
  QuikSort(arr, arr + 3);
  std::cout << std::endl << "Array after quick sort" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << "\t";
  }
  auto end_2 = std::chrono::steady_clock::now();
  duration<double> sec_2 = end_2 - start_2;
  std::cout << sec_2.count() << " sec" << std::endl;
}
