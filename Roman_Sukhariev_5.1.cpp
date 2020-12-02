#include <iostream>
struct Node {
  Node* previous;
  int data;
  Node* next;
};
class List {
 public:
  Node* tail{nullptr};
  Node* head{nullptr};
  void add_elem(int elem);
  void delete_elem();
  void print_elem();
  Node* search_elem();
  void erase_elem(Node* found_elem);
  void elem_quantity();
  void emptiness_test();
};
void List::add_elem(int elem) {
  Node* t = new Node;
  t->data = elem;
  t->previous = tail;
  t->next = nullptr;
  if (tail == nullptr) {
    tail = head = t;
    return;
  }
  tail->next = t;
  tail = head = t;
  return;
}
void List::delete_elem() {
  if (head == nullptr) {
    std::cerr << "Delete_elem. There are no elements to delete" << '\n';
    return;
  }
  Node* t = head;
  head = head->previous;
  delete t;
  head->next = nullptr;
}
void List::print_elem() {
  std::cout << "Print_elem. Here is a list of your numbers" << '\n';
  tail = head;
  while (tail != nullptr) {
    std::cout << tail->data << '\n';
    tail = tail->previous;
  }
  return;
}
Node* List::search_elem() {
  if (head == nullptr) {
    std::cerr << "Search_elem. There are no numbers in your list" << '\n';
    return 0;
  }
  Node* t = head;
  std::cout << "Search_elem. Enter number you want to find" << '\n';
  int elem{0};
  std::cin >> elem;
  while (t != nullptr) {
    if (elem == t->data) {
      break;
    }
    t = t->previous;
  }
  if (t == nullptr) {
    std::cerr << "Search_elem. No matches found" << '\n';
    return 0;
  }
  std::cout << "Search_elem. Your number was found" << '\n';
  return t;
}
void List::erase_elem(Node* found_elem) {
  if (found_elem == nullptr) {
    std::cerr << "Erase_elem. Error. There are no elements to delete" << '\n';
    return;
  }
  if (found_elem->previous == nullptr && found_elem->next == nullptr) {
    delete found_elem;
    std::cout << "Erase_elem. Element was deleted" << '\n';
    return;
  }
  if (found_elem->previous == nullptr && found_elem->next != nullptr) {
    Node* t = found_elem->next;
    t->previous = nullptr;
    delete found_elem;
    std::cout << "Erase_elem. Element was deleted" << '\n';
    return;
  }
  if (found_elem->next == nullptr && found_elem->previous != nullptr) {
    Node* t = found_elem->previous;
    t->next = nullptr;
    delete found_elem;
    std::cout << "Erase_elem. Element was deleted" << '\n';
    return;
  }
  Node* t = found_elem->previous;
  t->next = found_elem->next;
  t = found_elem->next;
  t->previous = found_elem->previous;
  delete found_elem;
  std::cout << "Erase_elem. Element was deleted" << '\n';
  return;
}
void List::elem_quantity() {
  if (head == nullptr) {
    std::cout << "Elem_quantity. You have no elements in your list" << '\n';
    return;
  }
  Node* t = head;
  size_t counter = 1;
  for (; t->previous != nullptr; ++counter) {
    t = t->previous;
  }
  std::cout << "Elem_quantity. Quantity of elements: " << counter << '\n';
  return;
}
void List::emptiness_test() {
  if (head == nullptr) {
    std::cout << "Emptiness_test. Your list is empty" << '\n';
  }
  std::cout << "Emptiness_test. Your list contains some numbers" << '\n';
  return;
}
int main() {
  int elem{0};
  std::cout << "Enter your numbers. If you want to finish, press any letter"
            << '\n';
  List list;
  while (std::cin >> elem) {
    list.add_elem(elem);
  }
  std::cin.clear();
  std::cin.ignore(100, '\n');
  Node* found_elem = list.search_elem();
  list.emptiness_test();
  list.erase_elem(found_elem);
  found_elem = nullptr;
  list.elem_quantity();
  list.print_elem();
  return 0;
}