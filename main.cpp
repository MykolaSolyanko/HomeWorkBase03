#include "list_interface.h"

int main() {
  structList myList{};
  int myData{5};
  vPrintList(myList);

  vPushBack(myList, myData);
  vPushFront(myList, 8);
  vPushBack(myList, 32);
  vPrintList(myList);

  bInsert(myList, FindByValue(myList, 5), 123);
  vPrintList(myList);

  std::cout.setf(std::ios::boolalpha);
  std::cout << "First element < Last element?: "
            << bCmp(GetFirstEl(myList), GetLastEl(myList)) << '\n';

  bPopBack(myList);
  bPopFront(myList);
  vPrintList(myList);

  vPushBack(myList, 45);
  vPushBack(myList, 280);
  bErase(myList, FindByValue(myList, 5));
  vPrintList(myList);

  vClear(myList);
  vPrintList(myList);

  return 0;
}
