#include "list.h"

int main() {
  C_List myList{};
  int myData{5};
  myList.vPrintList();

  myList.vPushBack(myData);
  myList.vPushFront(8);
  myList.vPushBack(32);
  myList.vPrintList();

  myList.bInsertBefore(myList.FindByValue(5), 123);
  myList.bInsertAfter(myList.FindByValue(5), 456);
  myList.bInsertAfter(myList.FindByValue(32), 321);
  myList.vPrintList();

  std::cout.setf(std::ios::boolalpha);
  // test of overloaded operator < for Node
  std::cout << "First element < Last element?: "
            << (myList.FindByValue(myList.First()) <
                myList.FindByValue(myList.Last()))
            << '\n';
  std::cout << "Last element < First element?: "
            << (myList.FindByValue(myList.Last()) <
                myList.FindByValue(myList.First()))
            << '\n';

  myList.bPopBack();
  myList.bPopFront();
  myList.vPrintList();

  myList.vPushBack(45);
  myList.vPushBack(280);
  myList.bErase(myList.FindByValue(5));
  myList.vPrintList();

  myList.vClear();
  myList.vPrintList();

  return 0;
}
