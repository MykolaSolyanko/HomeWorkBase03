#include <chrono>
#include <iostream>
#include <random>

void fill_array_random(int *begin, const int *const end);
void fill_array_by_hand(int *begin, c const int *const end);
void bubble_sort(int *begin, int *const end);
void quick_sort(int *begin, int *end);

int main() {
  constexpr uint16_t Lower_Scope{1};
  constexpr uint32_t Upper_Scope{100000};

  std::cout << "To compare bubble sort and quicksort algorithm,\n"
            << "enter size sortable array (positive integer "
            << "in scope[" << Lower_Scope << ".." << Upper_Scope << "])\n";

  size_t Size_Array{};
  std::cin >> Size_Array;
  if (!std::cin || Size_Array < Lower_Scope || Size_Array > Upper_Scope) {
    std::cout << "incorrect input\n";
    return 1;
  }

  int array[Size_Array];
  
  constexpr char Random{'1'};
  constexpr char ByHand{'2'};

  std::cout << "Choose a way to fill the array:\n"
            << Random <<" - fill random\n"
            << ByHand <<" - fill by hand\n";

  char choose{};
  std::cin >> choose;
  if (std::cin) {
    switch (choose) {
    case Random:
      fill_array_random(array, array + Size_Array);
      break;
    case ByHand:
      fill_array_by_hand(array, array + Size_Array);
      break;
    default:
      std::cout << "incorrect input\n";
      return 2;
    }
  }

  int copy_array[Size_Array];

  for (size_t i = 0; i < Size_Array; ++i) {
    copy_array[i] = array[i];
  }

  std::cout << "Comparison execution time of sorts " << Size_Array
            << " numbers: \n";

  auto start = std::chrono::steady_clock::now();
  quick_sort(array, array + Size_Array);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Quicksort elapsed time: " << elapsed_seconds.count() << "s\n";

  auto start1 = std::chrono::steady_clock::now();
  bubble_sort(copy_array, copy_array + Size_Array);
  auto end1 = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
  std::cout << "Bubble sort elapsed time: " << elapsed_seconds1.count()
            << "s\n";

  return 0;
}

void fill_array_random(int *begin, const int *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "One of the argument is null\n";
    return;
  }
  std::random_device rd;
  while (begin != end) {
    *begin++ = rd() % 100;
  }
}

void fill_array_by_hand(int *begin, const int *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "One of the argument is null\n";
    return;
  }
  std::cout << "Enter " << *end << " integers in the array\n";

  for (int i = 0; i < *end; ++i) {
    int number{};
    std::cin >> number;
    if (std::cin) {
      *begin++ = number;
    }
  }
}

void bubble_sort(int *begin, int *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "One of the argument is null\n";
    return;
  }
  bool swap = true;
  for (int *i = end; (i > begin) && swap; --i) {
    swap = false;
    for (int *n = begin; n < i - 1; ++n) {
      if (*n > *(n + 1)) {

        int temp = *n;
        *n = *(n + 1);
        *(n + 1) = temp;
        swap = true;
      }
    }
  }
}

void quick_sort(int *begin, int *end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "One of the argument is null\n";
    return;
  }
  while (begin < end) {
    int pivot = *end;
    int *i = begin;
    for (int *j = begin; j < end; ++j) {
      if (*j < pivot) {
        std::swap(*i, *j);
        ++i;
      }
    }
    std::swap(*i, *end);
    if (i - begin <= end - i) {
      quick_sort(begin, i - 1);
      begin = i + 1;
    } else {
      quick_sort(i + 1, end);
      end = i - 1;
    }
  }
}
