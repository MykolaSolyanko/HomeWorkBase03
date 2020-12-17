#include "list.h"

struct myStruct {
  int a;
  double b;

  bool operator==(const myStruct &RHStr) { return (a == RHStr.a); };
  bool operator==(const int RHValue) { return (a == RHValue); };
  bool operator<(const myStruct &RHStr) { return (a < RHStr.a); };
  bool operator<(const int RHValue) { return (a < RHValue); };
};

std::ostream &operator<<(std::ostream &os, const myStruct &nv) {
  return os << '{' << nv.a << ':' << nv.b << '}';
}

int main() {

  T_List<myStruct> myList{};
  myStruct myData{};
  myData.a = 5;

  myList.vPrintList();

  myList.vPushBack(myData);

  myData.a = 8;
  myList.vPushFront(myData);

  myData.a = 32;
  myList.vPushBack(myData);
  myList.vPrintList();

  myStruct findData{5, 10.1};
  myData.a = 123;
  myList.bInsertBefore(myList.FindByValue(findData), myData);
  myData.a = 456;
  myList.bInsertAfter(myList.FindByValue(findData), myData);
  findData.a = 32;
  myData.a = 321;
  myList.bInsertAfter(myList.FindByValue(findData), myData);
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

  myList.vClear();
  myList.vPrintList();

  return 0;
}
