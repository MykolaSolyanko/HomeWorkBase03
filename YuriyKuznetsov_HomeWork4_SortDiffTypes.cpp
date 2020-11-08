#include <functional>
#include <iostream>
#include <random>

constexpr size_t sizeARRAY{50};

void vFillAndSortUI(bool bASC);
void vFillAndSortDOUBLE(bool bASC);
void vFillAndSortUCHAR(bool bASC);
void vFillingRand(uint32_t *uiBegin, uint32_t *uiEnd);
void vFillingRand(double *dBegin, double *uiEnd);
void vFillingRand(unsigned char *uchBegin, unsigned char *uchEnd);
void vBubbleSort(uint32_t *uiBegin, uint32_t *uiEnd,
                 std::function<bool(uint32_t a, uint32_t b)> predicat);
void vBubbleSort(double *dBegin, double *dEnd,
                 std::function<bool(double a, double b)> predicat);
void vBubbleSort(
    unsigned char *uchBegin, unsigned char *uchEnd,
    std::function<bool(unsigned char a, unsigned char b)> predicat);
unsigned char ucMakeChar(const int32_t ciInt);
int32_t iGetRand();

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

  bool bAsc{};
  if ((uchSortOrder == 'A') || (uchSortOrder == 'a')) {
    bAsc = true;
  } else if ((uchSortOrder == 'D') || (uchSortOrder == 'd')) {
    bAsc = false;
  } else {
    std::cout << "Unsupported choice of sort order. \n";
    return -1;
  }

  switch (uchTypeChoice) {
  case 'U':
  case 'u':
    vFillAndSortUI(bAsc);
    break;
  case 'D':
  case 'd':
    vFillAndSortDOUBLE(bAsc);
    break;
  case 'C':
  case 'c':
    vFillAndSortUCHAR(bAsc);
    break;
  default:
    std::cout << "Unsupported choice of type. \n";
    return -1;
  }
  std::cout << '\n';
  return 0;
}

void vFillAndSortUI(bool bAsc) {
  uint32_t uiArray[sizeARRAY]{};
  std::cout << "Basic array \n";
  vFillingRand(uiArray, (uiArray + sizeARRAY));

  std::cout << "Sorted array \n";
  bAsc ? vBubbleSort(uiArray, (uiArray + sizeARRAY),
                     [](uint32_t a, uint32_t b) { return a <= b; })
       : vBubbleSort(uiArray, (uiArray + sizeARRAY),
                     [](uint32_t a, uint32_t b) { return a >= b; });
  for (uint32_t uiElem : uiArray) {
    std::cout << uiElem << ' ';
  }
  std::cout << '\n';
}

void vFillAndSortDOUBLE(bool bAsc) {
  double dArray[sizeARRAY]{};
  std::cout << "Basic array \n";
  vFillingRand(dArray, (dArray + sizeARRAY));

  std::cout << "Sorted array \n";
  bAsc ? vBubbleSort(dArray, (dArray + sizeARRAY),
                     [](double a, double b) { return a <= b; })
       : vBubbleSort(dArray, (dArray + sizeARRAY),
                     [](double a, double b) { return a >= b; });
  for (double dElem : dArray) {
    std::cout << dElem << ' ';
  }
  std::cout << '\n';
}

void vFillAndSortUCHAR(bool bAsc) {
  unsigned char uchArray[sizeARRAY]{};
  std::cout << "Basic array \n";
  vFillingRand(uchArray, (uchArray + sizeARRAY));

  std::cout << "Sorted array \n";
  bAsc ? vBubbleSort(uchArray, (uchArray + sizeARRAY),
                     [](unsigned char a, unsigned char b) { return a <= b; })
       : vBubbleSort(uchArray, (uchArray + sizeARRAY),
                     [](unsigned char a, unsigned char b) { return a >= b; });
  for (unsigned char uchElem : uchArray) {
    std::cout << uchElem << ' ';
  }
}

void vFillingRand(uint32_t *uiBegin, uint32_t *uiEnd) {
  for (uint32_t *uiElem = uiBegin; uiElem != uiEnd; ++uiElem) {
    int32_t iGenValue = iGetRand();
    *uiElem = (iGenValue < 0) ? (iGenValue * (-1)) : iGenValue;
    std::cout << *uiElem << ' ';
  }
  std::cout << '\n';
}

void vFillingRand(double *dBegin, double *dEnd) {
  constexpr double cdKOEF{2.5};
  for (double *dElem = dBegin; dElem != dEnd; ++dElem) {
    *dElem = static_cast<double>(iGetRand()) / cdKOEF;
    std::cout << *dElem << ' ';
  }
  std::cout << '\n';
}

void vFillingRand(unsigned char *uchBegin, unsigned char *uchEnd) {
  for (unsigned char *uchElem = uchBegin; uchElem != uchEnd; ++uchElem) {
    *uchElem = ucMakeChar(iGetRand());
    std::cout << *uchElem << ' ';
  }
  std::cout << '\n';
}

void vBubbleSort(uint32_t *uiBegin, uint32_t *uiEnd,
                 std::function<bool(uint32_t a, uint32_t b)> predicat) {
  for (uint32_t *uiTrying = uiBegin; uiTrying != uiEnd; ++uiTrying) {
    bool bChanged = false;
    for (uint32_t *uiElem = uiBegin; uiElem != (uiEnd - 1); ++uiElem) {
      if (predicat(*uiElem, *(uiElem + 1))) {
        continue;
      }
      std::swap(*uiElem, *(uiElem + 1));
      bChanged = true;
    }
    if (!bChanged) {
      break;
    }
  }
}

void vBubbleSort(double *dBegin, double *dEnd,
                 std::function<bool(double a, double b)> predicat) {
  for (double *dTrying = dBegin; dTrying != dEnd; ++dTrying) {
    bool bChanged = false;
    for (double *dElem = dBegin; dElem != (dEnd - 1); ++dElem) {
      if (predicat(*dElem, *(dElem + 1))) {
        continue;
      }
      std::swap(*dElem, *(dElem + 1));
      bChanged = true;
    }
    if (!bChanged) {
      break;
    }
  }
}

void vBubbleSort(
    unsigned char *uchBegin, unsigned char *uchEnd,
    std::function<bool(unsigned char a, unsigned char b)> predicat) {
  for (unsigned char *uchElem = uchBegin; uchElem != uchEnd; ++uchElem) {
    if ((*uchElem < '0') || (*uchElem > '9')) {
      continue;
    }
    *uchElem += 'z';
  }

  for (unsigned char *uchTrying = uchBegin; uchTrying != uchEnd; ++uchTrying) {
    bool bChanged = false;
    for (unsigned char *uchElem = uchBegin; uchElem != (uchEnd - 1);
         ++uchElem) {
      if (predicat(*uchElem, *(uchElem + 1))) {
        continue;
      }
      std::swap(*uchElem, *(uchElem + 1));
      bChanged = true;
    }
    if (!bChanged) {
      break;
    }
  }

  for (unsigned char *uchElem = uchBegin; uchElem != uchEnd; ++uchElem) {
    if (*uchElem <= 'z') {
      continue;
    }
    *uchElem -= 'z';
  }
}

int32_t iGetRand() {
  constexpr int32_t ciMIN{-122};
  constexpr int32_t ciMAX{122};
  static std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(ciMIN, ciMAX);

  return distrib(gen);
}

unsigned char ucMakeChar(const int32_t ciInt) {
  const unsigned char cucChar = static_cast<unsigned char>(ciInt);
  if (cucChar < '0') {
    return '0';
  }
  if ((cucChar > '9') && (cucChar < 'A')) {
    return 'A';
  }
  if ((cucChar > 'Z') && (cucChar < 'a')) {
    return 'a';
  }
  if (cucChar > 'z') {
    return 'z';
  }
  return cucChar;
}
