#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <random>

constexpr size_t sizeARRAY{100};
using YuArray = std::array<int32_t, sizeARRAY>;

bool bFillingManual(YuArray &in_out_Array);
bool bFillingRand(YuArray &in_out_Array);
void vBubbleSort(YuArray *out_Array);
bool bQuickSort(const YuArray::iterator citBeg, const YuArray::iterator citEnd);
void vPrintRes(const YuArray &cout_Array);

int main() {
  YuArray arInArray{};

  std::cout << "Fill the integer array to sort. M - manual filling; "
               "R - random values filling. Enter your choice: ";

  unsigned char uchChoice{};
  if (!(std::cin >> uchChoice)) {
    std::cout << "Uncorrect choice. \n";
    return -1;
  }

  switch (uchChoice) {
  case 'M':
  case 'm':
    if (!bFillingManual(arInArray)) {
      std::cout << "Uncorrect manual filling of array. \n";
      return -1;
    }
    break;
  case 'R':
  case 'r':
    if (!bFillingRand(arInArray)) {
      std::cout << "Error while filling of array. \n";
      return -1;
    }
    break;
  default:
    std::cout << "Unsupported choice. \n";
    return -1;
  }

  // Bubble sort
  YuArray arOutArray{arInArray};
  auto timeBegin = std::chrono::steady_clock::now();
  vBubbleSort(&arOutArray);
  auto timeDuration = std::chrono::steady_clock::now() - timeBegin;
  std::cout << "Bubble sort time: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(
                   timeDuration)
                   .count()
            << " ns\n";
  vPrintRes(arOutArray);

  // Quick sort
  arOutArray = arInArray;
  timeBegin = std::chrono::steady_clock::now();
  bQuickSort(arOutArray.begin(), arOutArray.end());
  timeDuration = std::chrono::steady_clock::now() - timeBegin;
  std::cout << "Quicksort time: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(
                   timeDuration)
                   .count()
            << " ns\n";
  vPrintRes(arOutArray);

  // STL sort
  arOutArray = arInArray;
  timeBegin = std::chrono::steady_clock::now();
  std::sort(arOutArray.begin(), arOutArray.end());
  timeDuration = std::chrono::steady_clock::now() - timeBegin;
  std::cout << "STL sort time: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(
                   timeDuration)
                   .count()
            << " ns\n";
  vPrintRes(arOutArray);

  return 0;
}

bool bFillingManual(YuArray &in_out_Array) {
  for (size_t sizeIndex = 0; sizeIndex != sizeARRAY; ++sizeIndex) {
    std::cout << "Enter integer value for [" << sizeIndex << "] array member: ";
    if (!(std::cin >> in_out_Array.at(sizeIndex))) { // skip other checkings
      return false;
    }
  }
  return true;
}

bool bFillingRand(YuArray &in_out_Array) {
  constexpr int32_t ciMIN{-200};
  constexpr int32_t ciMAX{200};
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(ciMIN, ciMAX);

  for (size_t sizeIndex = 0; sizeIndex != sizeARRAY; ++sizeIndex) {
    in_out_Array.at(sizeIndex) = distrib(gen);
    std::cout << in_out_Array.at(sizeIndex) << ' ';
  }
  std::cout << '\n';
  return true;
}

void vBubbleSort(YuArray *out_Array) {
  for (size_t sizeTrying = 0; sizeTrying < out_Array->size(); ++sizeTrying) {
    bool bChanged = false;
    for (size_t sizeIndex = 0; sizeIndex < (out_Array->size() - 1); ++sizeIndex) {
      if (out_Array->at(sizeIndex) <= out_Array->at(sizeIndex + 1)) {
        continue;
      }
      std::swap(out_Array->at(sizeIndex), out_Array->at(sizeIndex + 1));
      bChanged = true;
    }
    if (!bChanged) {
      break;
    }
  }
}

bool bQuickSort(const YuArray::iterator citBeg,
                const YuArray::iterator citEnd) {
  constexpr uint32_t cuiDOUBLE{2};
  static uint32_t uiControl{0};
  ++uiControl;
  if (uiControl > (cuiDOUBLE * sizeARRAY)) {
    uiControl = 0;
    return false;
  }

  auto itREl = citEnd - 1;
  auto itEl = citBeg;
  while (itREl != itEl) {
    if (*itREl >= *itEl) {
      ++itEl;
      continue;
    }
    if ((itREl - 1) == itEl) {
      std::swap(*itREl, *itEl);
      --itREl;
      break;
    }
    std::swap(*itREl, *(itREl - 1));
    std::swap(*itREl, *itEl);
    --itREl;
  }
  if ((itEl - citBeg) > 1) {
    if (!bQuickSort(citBeg, itEl)) {
      return false;
    }
  }
  if ((citEnd - itEl) > 1) {
    if (!bQuickSort(itEl, citEnd)) {
      return false;
    }
  }
  --uiControl;
  return true;
}

void vPrintRes(const YuArray &cout_Array) {
  for (int32_t iCurValue : cout_Array) {
    std::cout << iCurValue << ' ';
  }
  std::cout << '\n';
}
