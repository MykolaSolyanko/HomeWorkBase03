// sort different types (templates using)

#include <functional>
#include <iostream>
#include <random>
#include <type_traits>

constexpr size_t sizeARRAY{50};

template <typename T> constexpr short shGetMin() {
  return std::is_signed<T>::value ? -122 : 0;
}

template <typename T> constexpr bool bIsCharFamily() {
  return (std::is_same<T, char>::value || std::is_same<T, char16_t>::value ||
          std::is_same<T, char32_t>::value || std::is_same<T, wchar_t>::value ||
          std::is_same<T, unsigned char>::value ||
          std::is_same<T, signed char>::value);
}

template <typename T = short> T GetRand() {
  static_assert(std::is_arithmetic<T>::value,
                "GetRand supports only arithmetic types");
  static_assert(!std::is_const<T>::value, "GetRand doesnt support const types");
  constexpr short cshMIN{shGetMin<T>()};
  constexpr short cshMAX{122};
  static std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(cshMIN, cshMAX);
  int iRandValue{distrib(gen)};

  if (std::is_floating_point<T>::value) {
    constexpr double cdKOEF{2.5};
    return static_cast<T>(iRandValue / cdKOEF);
  }

  if (bIsCharFamily<T>()) {
    const T cChar = static_cast<T>(iRandValue);
    if (cChar < '0') {
      return '0';
    }
    if ((cChar > '9') && (cChar < 'A')) {
      return 'A';
    }
    if ((cChar > 'Z') && (cChar < 'a')) {
      return 'a';
    }
    if (cChar > 'z') {
      return 'z';
    }
    return cChar;
  }

  return static_cast<T>(iRandValue);
}

template <typename T> void FillingRand(T *Begin, T *End) {
  for (T *Elem = Begin; Elem != End; ++Elem) {
    *Elem = GetRand<T>();
    std::cout << *Elem << ' ';
  }
  std::cout << '\n';
}

template <typename T, typename Compare = std::less<T>>
void BubbleSort(T *Begin, T *End) {
  if (bIsCharFamily<T>()) {
    for (T *Elem = Begin; Elem != End; ++Elem) {
      if ((*Elem < '0') || (*Elem > '9')) {
        *Elem -= 'A';
        continue;
      }
      *Elem += 'z' - 'A';
    }
  }

  Compare cmp;
  for (T *Trying = Begin; Trying != End; ++Trying) {
    bool bChanged{false};
    for (T *Elem = Begin; Elem != (End - 1); ++Elem) {
      if (cmp(*(Elem + 1), *Elem)) {
        std::swap(*Elem, *(Elem + 1));
        bChanged = true;
      }
    }
    if (!bChanged) {
      break;
    }
  }

  if (bIsCharFamily<T>()) {
    for (T *Elem = Begin; Elem != End; ++Elem) {
      if (*Elem < 'A') {
        *Elem += 'A';
        continue;
      }
      *Elem -= 'z' - 'A';
    }
  }
}

template <typename T, typename Compare = std::less<T>> void FillAndSort() {
  T Array[sizeARRAY]{};
  std::cout << "Basic array \n";
  FillingRand<T>(Array, Array + sizeARRAY);

  std::cout << "Sorted array \n";
  BubbleSort<T, Compare>(Array, Array + sizeARRAY);
  for (T Elem : Array) {
    std::cout << Elem << ' ';
  }
  std::cout << '\n';
}

int main() {

  std::cout << "Random filling of array to sort. U - unsigned int, "
               "D - double, C - char. Enter the type: ";

  unsigned char uchTypeChoice{};
  if (!(std::cin >> uchTypeChoice)) {
    std::cout << "Uncorrect choice. \n";
    return -1;
  }

  std::cout << "Enter the sort order. D - descending, A - ascending: ";
  unsigned char uchSortOrder{};
  if (!(std::cin >> uchSortOrder)) {
    std::cout << "Uncorrect choice. \n";
    return -1;
  }

  bool bAscOrder{};
  if ((uchSortOrder == 'A') || (uchSortOrder == 'a')) {
    bAscOrder = true;
  } else if ((uchSortOrder == 'D') || (uchSortOrder == 'd')) {
    bAscOrder = false;
  } else {
    std::cout << "Unsupported choice of sort order. \n";
    return -1;
  }

  switch (uchTypeChoice) {
  case 'U':
  case 'u':
    if (bAscOrder) {
      FillAndSort<unsigned int>();
    } else {
      FillAndSort<unsigned int, std::greater<unsigned int>>();
    }
    break;
  case 'D':
  case 'd':
    if (bAscOrder) {
      FillAndSort<double>();
    } else {
      FillAndSort<double, std::greater<double>>();
    }
    break;
  case 'C':
  case 'c':
    if (bAscOrder) {
      FillAndSort<char>();
    } else {
      FillAndSort<char, std::greater<char>>();
    }
    break;
  default:
    std::cout << "Unsupported choice of type. \n";
    return -1;
  }
  std::cout << '\n';
  return 0;
}
