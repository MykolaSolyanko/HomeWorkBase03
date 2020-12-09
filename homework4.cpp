#include <chrono>
#include <iostream>
#include <random>

void fill_arr(unsigned int *arr, size_t arr_bgn, size_t arr_end) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<unsigned int> rd_rng(
      std::numeric_limits<unsigned int>::min(),
      std::numeric_limits<unsigned int>::max());
  for (size_t i = arr_bgn; i < arr_end; ++i) {
    arr[i] = rd_rng(mt);
  }
}

void print_arr(unsigned int *arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
void print_arr(double *arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
void print_arr(char *arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
void swap(unsigned int *a, unsigned int *b) {
  unsigned int tmp = *a;
  *a = *b;
  *b = tmp;
}
void swap(double *a, double *b) {
  double tmp = *a;
  *a = *b;
  *b = tmp;
}
void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
bool is_dgt(char ch) {
  constexpr char zero_ch = '0';
  constexpr char nine_ch = '9';
  if (ch >= zero_ch && ch <= nine_ch) {
    return true;
  }
  return false;
}

bool is_letter(char ch) {
  constexpr char uppr_a = 'A';
  constexpr char uppr_z = 'Z';
  constexpr char lwr_a = 'a';
  constexpr char lwr_z = 'z';

  if ((ch >= uppr_a && ch <= uppr_z) || (ch >= lwr_a && ch <= lwr_z)) {
    return true;
  }
  return false;
}
void bubble_sort(unsigned int *arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    for (size_t j = bgn; j < end - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}
void bubble_sort(double *arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    for (size_t j = bgn; j < end - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int partition(unsigned int *arr, size_t bgn, size_t end) {
  unsigned int pivot = arr[end];
  int i = (bgn - 1);

  for (size_t j = bgn; j <= end - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}
void quick_sort(unsigned int *arr, size_t bgn, size_t end) {
  if (bgn < end) {
    int p = partition(arr, bgn, end);
    quick_sort(arr, bgn, p - 1);
    quick_sort(arr, p + 1, end);
  }
}

int partition(char *arr, size_t bgn, size_t end) {
  char pivot = arr[end];
  int i = (bgn - 1);

  for (size_t j = bgn; j <= end - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}
void quick_sort(char *arr, size_t bgn, size_t end) {
  if (bgn < end) {
    int p = partition(arr, bgn, end);
    quick_sort(arr, bgn, p - 1);
    quick_sort(arr, p + 1, end);
  }
}
int partition(double *arr, size_t bgn, size_t end) {
  double pivot = arr[end];
  int i = (bgn - 1);

  for (size_t j = bgn; j <= end - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}
void quick_sort(double *arr, size_t bgn, size_t end) {
  if (bgn < end) {
    int p = partition(arr, bgn, end);
    quick_sort(arr, bgn, p - 1);
    quick_sort(arr, p + 1, end);
  }
}
void locate_dgts_at_end(char *arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    for (size_t j = bgn; j < end - 1; ++j) {
      if (is_dgt(arr[j]) || is_dgt(arr[j + 1])) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
  for (size_t i = end - 1; i > bgn; --i) {
    for (size_t j = end - 1; j > bgn + 1; --j) {
      if (is_dgt(arr[j]) && is_dgt(arr[j - 1])) {
        if (arr[j] < arr[j - 1]) {
          swap(&arr[j], &arr[j - 1]);
        }
      }
    }
  }
}
void bubble_sort(char *arr, size_t bgn, size_t end) {
  int lst_dgt_pos{0};
  for (size_t i = bgn; i < end; ++i) {
    for (size_t j = bgn; j < end - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
      if (!is_dgt(arr[j]) && arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      } else if (is_dgt(arr[j]) && arr[j] < arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
  locate_dgts_at_end(arr, bgn, end);
}

void cast_arr(unsigned int *f_arr, double *t_arr, size_t bgn, size_t end) {
  double magic_num_for_cast = 5;
  for (size_t i = bgn; i < end; ++i) {
    t_arr[i] = f_arr[i] / magic_num_for_cast;
  }
}
void cast_arr(char *charr, size_t bgn, size_t end) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> rd_rng(0,
                                            std::numeric_limits<char>::max());
  for (size_t i = bgn; i < end; ++i) {
    char ch = static_cast<char>(rd_rng(mt));
    if (is_dgt(ch) || is_letter(ch)) {
      charr[i] = ch;
    } else {
      charr[i] = 'a';
    }
  }
}

void measure_bubble(unsigned int *uiarr, double *darr, char *charr, size_t bgn,
                    size_t end) {
  auto uistart_t = std::chrono::system_clock::now();
  bubble_sort(uiarr, bgn, end);
  auto uiend_t = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = uiend_t - uistart_t;
  std::cout << "Elapsed unsigned int bubble sort: " << elapsed.count()
            << std::endl;

  auto dstart_t = std::chrono::system_clock::now();
  bubble_sort(darr, bgn, end);
  auto dend_t = std::chrono::system_clock::now();
  elapsed = dend_t - dstart_t;
  std::cout << "Elapsed double bubble sort: " << elapsed.count() << std::endl;

  auto chstart_t = std::chrono::system_clock::now();
  bubble_sort(charr, bgn, end);
  auto chend_t = std::chrono::system_clock::now();
  std::cout << "Elapsed char bubble sort: " << elapsed.count() << std::endl;
}

void measure_quick(unsigned int *uiarr, double *darr, char *charr, size_t bgn,
                   size_t end) {
  auto uistart_t = std::chrono::system_clock::now();
  quick_sort(uiarr, bgn, end);
  auto uiend_t = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = uiend_t - uistart_t;
  std::cout << "Elapsed unsigned int quick sort: " << elapsed.count()
            << std::endl;

  auto dstart_t = std::chrono::system_clock::now();
  quick_sort(darr, bgn, end);
  auto dend_t = std::chrono::system_clock::now();
  elapsed = dend_t - dstart_t;
  std::cout << "Elapsed double quick sort: " << elapsed.count() << std::endl;

  auto chstart_t = std::chrono::system_clock::now();
  quick_sort(charr, bgn, end);
  auto chend_t = std::chrono::system_clock::now();
  std::cout << "Elapsed char quick sort: " << elapsed.count() << std::endl;
}

void prepare_data(unsigned int *uiarr, char *charr, double *darr, size_t bgn,
                  size_t end) {
  fill_arr(uiarr, bgn, end);
  cast_arr(uiarr, darr, bgn, end);
  cast_arr(charr, bgn, end);
}

void copy_arr(unsigned int *f_arr, unsigned int *t_arr, size_t bgn,
              size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    t_arr[i] = f_arr[i];
  }
}

void copy_arr(double *f_arr, double *t_arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    t_arr[i] = f_arr[i];
  }
}

void copy_arr(char *f_arr, char *t_arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    t_arr[i] = f_arr[i];
  }
}

bool compare_arr(unsigned int *b_arr, unsigned int *q_arr, size_t bgn,
                 size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    if (b_arr[i] != q_arr[i]) {
      return false;
    }
  }
  return true;
}
bool compare_arr(char *b_arr, char *q_arr, size_t bgn, size_t end) {
  for (size_t i = bgn; i < end; ++i) {
    if (b_arr[i] != q_arr[i]) {
      return false;
    }
  }
  return true;
}
int main() {
   /* быстрая сортировка пока что не запускается */
  // constexpr int num_bgn{ 0 };
  // constexpr unsigned int num_end{ std::numeric_limits<unsigned int>::max() };
  constexpr size_t arr_len{100};
  constexpr size_t strt_arr{0};
  unsigned int uiarr_bub[arr_len]{};
  double darr_bub[arr_len]{};
  char charr_bub[arr_len]{};

  prepare_data(uiarr_bub, charr_bub, darr_bub, strt_arr, arr_len);
  std::cout << std::endl;

  unsigned int uiarr_qui[arr_len]{};
  double darr_qui[arr_len]{};
  char charr_qui[arr_len]{};
  copy_arr(uiarr_bub, uiarr_qui, strt_arr, arr_len);
  copy_arr(darr_bub, darr_qui, strt_arr, arr_len);
  copy_arr(charr_bub, charr_qui, strt_arr, arr_len);

  measure_bubble(uiarr_bub, darr_bub, charr_bub, strt_arr, arr_len);
  measure_quick(uiarr_qui, darr_qui, charr_qui, strt_arr, arr_len);
  // std::cout << compare_arr(uiarr_bub, uiarr_qui, strt_arr, arr_len) <<
  // std::endl; std::cout << compare_arr(charr_bub, charr_qui, strt_arr,
  // arr_len)
  // << std::endl;
  return 0;
}