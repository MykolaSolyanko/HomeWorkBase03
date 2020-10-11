// Обратные числа
#include <iostream>

int main(int argc, char *argv[]) {
  constexpr std::int32_t ci_KOEF{10};
  std::int32_t iInNumber{};

  std::cout << "Enter integer number: ";
  if (!(std::cin >> iInNumber)) {
    std::cout << "Uncorrect number!";
    return -1;
  }

  // Алгоритм честно подсмотрел в интернете :)
  // Изначально хотел все запихать в вектор или строку и прочитать реверсным
  // итератором
  std::int32_t iRevNumber{};
  while (iInNumber) {
    iRevNumber = iRevNumber * ci_KOEF + iInNumber % ci_KOEF;
    iInNumber /= ci_KOEF;
  }

  std::cout << iRevNumber << '\n';
  return 0;
}
