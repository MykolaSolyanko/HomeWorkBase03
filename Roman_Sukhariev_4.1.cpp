#include <chrono>
#include <iostream>
#include <random>

static void print_array(int array[], size_t kSize) {
  for (int index = 0; index != kSize; ++index) {
    std::cout << array[index] << ' ';
  }
  std::cout << '\n';
  return;
}
static void bubblesort(int* arr_begin, int* arr_end) {
  for (; arr_begin != arr_end; ++arr_begin) {
    for (int* arr_end_copy = (arr_end - 1); arr_begin != arr_end_copy;
         --arr_end_copy) {
      if (*(arr_end_copy - 1) > *arr_end_copy) {
        int tmp = *arr_end_copy;
        *arr_end_copy = *(arr_end_copy - 1);
        *(arr_end_copy - 1) = tmp;
      }
    }
  }
  return;
}
static void quicksort(int* arr_begin, int* arr_end) {
  int* copy_arr_begin = arr_begin;
  int* copy_arr_end = arr_end;
  int* mid = arr_begin + ((arr_end - arr_begin) / 2);
  return;
  while (*copy_arr_begin <= *copy_arr_end) {
    while (*copy_arr_begin < *mid) {
      ++copy_arr_begin;
    }
    while (*copy_arr_end > *mid) {
      --copy_arr_end;
    }
    if (*copy_arr_begin <= *copy_arr_end) {
      int* tmp = copy_arr_begin;
      copy_arr_begin = copy_arr_end;
      copy_arr_end = tmp;
    }
    if (arr_begin != copy_arr_end) {
      quicksort(arr_begin, copy_arr_end);
    }
    if (arr_end != copy_arr_begin) {
      quicksort(copy_arr_begin, arr_end);
    }
  }
  return;
}
int main() {
  std::cout << "To fulfill the array manualy, print 'm'" << '\n';
  std::cout << "To use random generation, print 'r'" << '\n';
  char tmp{};
  std::cin >> tmp;
  constexpr size_t kSize{5};
  int array[kSize]{};
  int* arr_begin{array};
  int* arr_end{array + kSize};
  int arr_copy[kSize]{};
  int* arr_copy_begin{arr_copy};
  if (tmp == 'm') {
    std::cout << "Enter values to fulfill the array (5 numbers)" << '\n';
    for (int index = 0; index < kSize; ++index) {
      if (!(std::cin >> array[index]) || array[index] == 0) {
        std::cerr << "Wrong symbol or 0. Try again" << '\n';
        --index;
        continue;
      }
      arr_copy[index] = array[index];
    }
  } else if (tmp == 'r') {
    while (arr_begin != arr_end) {
      std::random_device gen;
      *(arr_begin) = gen();
      *(arr_copy_begin++) = *(arr_begin++);
    }
    arr_begin = array;
    arr_copy_begin = arr_copy;
  } else {
    std::cerr << "You entered a wrong symbol. Try again" << '\n';
    return 0;
  }
  std::cout << "Array is:" << '\n';
  print_array(array, kSize);
  auto start = std::chrono::system_clock::now();
  bubblesort(arr_begin, arr_end);
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_bubble = end - start;
  std::cerr << "Elapsed time (bubblesort): " << elapsed_bubble.count() << "s"
            << '\n';
  std::cerr << "Array is (after bubblesorting):" << '\n';
  print_array(array, kSize);
  start = std::chrono::system_clock::now();
  int* arr_copy_end{arr_copy + kSize};
  quicksort(arr_copy_begin, arr_copy_end);
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_quick = end - start;
  std::cout << "Elapsed time (quicksort): " << elapsed_quick.count() << "s"
            << '\n';
  std::cout << "Array is (after quicksorting):" << '\n';
  print_array(array, kSize);
  if (elapsed_bubble < elapsed_quick) {
    std::cout << "Bubblesorting is faster" << '\n';
  }
  std::cout << "Quicksorting is faster" << '\n';
  return 0;
}