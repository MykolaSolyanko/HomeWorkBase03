#include <chrono>
#include <iostream>
#include <random>
/*Type declaration-------------------------------------------------------*/
enum test_e { e_BUBBLE = 0, e_SELECTION, e_INSERTION, e_QUICK };

constexpr size_t TEST_ARRAY_SIZE{4};

struct test_s {
  const char *name;
  void (*function)(uint32_t *array, size_t size);
};
/*An array Init----------------------------------------------------------*/
static constexpr size_t MAX_SIZE{2048};
static constexpr size_t MIN_SIZE{1};
static uint32_t         array[MAX_SIZE];
/*Declaration of function to perform test--------------------------------*/
static bool test_init        (test_s *obj, const char *_name,
                              void (*_function)(uint32_t *array, size_t size));
static void test_sort_quick  (uint32_t *array, size_t size);
static void test_execute     (test_s *test, uint32_t *array, size_t size);
/*Declaration of function to process arrays------------------------------*/
static bool array_init_rand  (uint32_t *array, size_t size, uint32_t MIN,
                              uint32_t MAX);
static void array_print      (const uint32_t *array, size_t size);
/*Declaratiion of function to set parameter by USER----------------------*/
static bool param_init_safety(const char *annotation, size_t *const param);
static bool param_init_safety(const char *annotation, uint32_t *const param);
static bool param_init_safety(const char *annotation, char *const param);
/*Declaration of sorting algorytm----------------------------------------*/
static void swap             (uint32_t *a, uint32_t *b);
static void sort_bubble      (uint32_t *array, size_t size);
static void sort_quick       (uint32_t *array, size_t begin, size_t end);
static void sort_selection   (uint32_t *array, size_t size);
static void sort_insertion   (uint32_t *array, size_t size);
/*-----------------------------------------------------------------------*/
int main() {
  /*Variable to set array length by User*/
  size_t selected_size{};
  std::cout << "Please, enter an array size to create it" << std::endl;
  std::cout << "HINT: value has to be range [ " << MIN_SIZE << " ... "
            << MAX_SIZE << " ]" << std::endl;
  /*Set array lenght by User*/
  param_init_safety("Selected size -->", &selected_size);
  /*Declaration of vatiables to set range of random number for array init*/
  size_t MAX{};
  size_t MIN{};
  std::cout << "Enter range numbers to init the array" << std::endl;
  /*Set MIN and MAX range of random number*/
  param_init_safety("MIN -->", &MIN);
  param_init_safety("MAX -->", &MAX);
  /*Declate array of tests*/
  test_s test[TEST_ARRAY_SIZE];
  /*Test init*/
  test_init(&test[e_BUBBLE], "Bubble sort", sort_bubble);
  test_init(&test[e_SELECTION], "Selection sort", sort_selection);
  test_init(&test[e_INSERTION], "Insertion sort", sort_insertion);
  test_init(&test[e_QUICK], "Quick sort", test_sort_quick);
  /*endless loop to perform the estimation*/
  while (1) {
    std::cout << "-----------------------------------------------" << std::endl;
    array_init_rand(array, selected_size, MIN, MAX);
    std::cout << "The array of " << selected_size
              << " elements, contains numbers in the range from " << MIN << " to "
              << MAX << " was generated" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Print an unsorted array?" << std::endl;
    char cmd{};
    while ((cmd != 'N') && (cmd != 'n') && (cmd != 'Y') && (cmd != 'y')) {
      param_init_safety("y/n? --> ", &cmd);
    }
    if ((cmd == 'Y') || (cmd == 'y')) {
      std::cout << "Unsorted array:" << std::endl;
      /*Print inited array*/
      array_print(array, selected_size);
    }
    cmd = '\0';
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Select a sorting method to evaluate the performance:"
              << std::endl;
    /* Print all commands to help User to choose*/
    for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
      std::cout << "[ " << i << " ]\t" << test[i].name << ";" << std::endl;
    }
    std::cout << "[OTHER]\tEXIT." << std::endl;
    /*Set command to execute*/
    uint32_t id{};
    std::cout << "-----------------------------------------------" << std::endl;
    param_init_safety("TEST --> ", &id);
    std::cout << "-----------------------------------------------" << std::endl;
    if (id >= TEST_ARRAY_SIZE) {
      break;
    }
    /*Execute selectet by User test*/
    test_execute(&test[id], array, selected_size);
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Would you like to print sorted array?" << std::endl;
    while ((cmd != 'N') && (cmd != 'n') && (cmd != 'Y') && (cmd != 'y')) {
      param_init_safety("y/n? --> ", &cmd);
    }
    if ((cmd == 'Y') || (cmd == 'y')) {
      std::cout << "Sorted array:" << std::endl;
      /*Print sorted array*/
      array_print(array, selected_size);
    }
    cmd = '\0';
  }
  std::cout << "Shutdown by User prompt" << std::endl;
  return EXIT_SUCCESS;
}

static bool test_init(test_s *obj, const char *_name,
                      void (*_function)(uint32_t *array, size_t size)) {
  if ((obj == nullptr) || (_name == nullptr) || (_function == nullptr)) {
    return false;
  }
  obj->name = _name;
  obj->function = _function;
  return true;
}

static bool array_init_rand(uint32_t *array, size_t size, uint32_t MIN,
                            uint32_t MAX) {
  if ((array == nullptr) || (size == 0)) {
    return false;
  }
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(MIN, MAX);
  for (size_t i = 0; i < size; i++) {
    // Use `distrib` to transform the random unsigned int generated by gen into
    // an int in [MIN, MAX]
    array[i] = distrib(gen);
  }
  return true;
}

static void array_print(const uint32_t *array, size_t size) {
  if ((array == nullptr) || (size == 0)) {
    return;
  }
  for (size_t i = 0; i < size; i++) {
    std::cout << array[i] << '\t';
  }
  std::cout << std::endl;
}

static bool param_init_safety(const char *annotation, size_t *const param) {
  if ((param == nullptr) || (annotation == nullptr)) {
    return false;
  }
  while (true) {
    std::cout << annotation;
    std::cin >> *param;
    if (!std::cin.fail()) {
      return true;
    }
    std::cin.clear();
    std::cin.ignore();
  }
}

static bool param_init_safety(const char *annotation, uint32_t *const param) {
  if ((param == nullptr) || (annotation == nullptr)) {
    return false;
  }
  while (true) {
    std::cout << annotation;
    std::cin >> *param;
    if (!std::cin.fail()) {
      return true;
    }
    std::cin.clear();
    std::cin.ignore();
  }
}

static bool param_init_safety(const char *annotation, char *const param) {
  if ((param == nullptr) || (annotation == nullptr)) {
    return false;
  }
  while (true) {
    std::cout << annotation;
    std::cin >> *param;
    if (!std::cin.fail()) {
      return true;
    }
    std::cin.clear();
    std::cin.ignore();
  }
}

static void swap(uint32_t *a, uint32_t *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

static void sort_bubble(uint32_t *array, size_t size) {
  if ((array == nullptr) || (size == 0)) {
    return;
  }
  for (size_t i = 0; i < size - 1; i++) {
    bool flag = false;
    for (size_t j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        flag = true;
        swap(&array[j], &array[j + 1]);
      }
    }
    if (!flag) {
      return;
    }
  }
}

static size_t partition(uint32_t *array, size_t begin, uint32_t end) {
  auto median{(begin + end) / 2};
  auto i{begin};
  auto j{end};
  while (i <= j) {
    while (array[i] < array[median]) {i++;}
    while (array[j] > array[median]) {j--;}
    if (i >= j) {
      break;
    }
    swap(&array[i++], &array[j--]);
  }
  return j;
}

static void sort_quick(uint32_t *array, size_t begin, size_t end) {
  if ((array == nullptr) || (begin >= end)) {
    return;
  }
  auto median{partition(array, begin, end)};
  sort_quick(array, begin, median);
  sort_quick(array, median + 1, end);
}

static void sort_selection(uint32_t *array, size_t size) {
  if ((array == nullptr) || (size == 0)) {
    return;
  }
  for (size_t walk{}; walk < size; walk++) {
    auto min{walk};
    for (size_t i{walk}; i < size; i++) {
      if (array[i] < array[min]) {
        min = i;
      }
    }
    if (walk != min) {
      swap(&array[walk], &array[min]);
    }
  }
}

static void sort_insertion(uint32_t *array, size_t size) {
  if ((array == nullptr) || (size == 0)) {
    return;
  }
  for (size_t i = 1; i < size; i++) {
    for (auto j{i}; j != 0; j--) {
      if (array[j - 1] > array[j]) {
        swap(&array[j - 1], &array[j]);
      }
    }
  }
}

static void test_sort_quick(uint32_t *array, size_t size) {
  if ((array == nullptr) || (size == 0)) {
    return;
  }
  sort_quick(array, 0, size - 1);
}

static void test_execute(test_s *test, uint32_t *array, size_t size) {
  if ((test == nullptr) || (array == nullptr) || (size == 0)) {
    return;
  }
  // Get the current time moment
  std::chrono::system_clock::time_point start =
      std::chrono::system_clock::now();
  // Perform the test
  test->function(array, size);
  // Get the current time moment
  std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
  // Determine the type of the interval object and calculate its value
  // std::chrono::duration<double> sec = end - start;
  std::chrono::duration<double, std::milli> msec{end - start};
  // calculate the number of ticks in the interval
  // and display the result
  std::cout << test->name << " sorted array of " << size << " elements in "
            << msec.count() << " miliseconds" << std::endl;
}