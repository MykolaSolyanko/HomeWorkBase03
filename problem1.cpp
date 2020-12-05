#include <iostream>

struct Node {
  int data;
  Node *link;
};

class List {
public:
  List();
  List(int _data);
  List(const List &other);
  ~List();

  int get_front() const;
  int get_back() const;
  void print() const;
  size_t size() const { return count; }
  bool is_empty() const { return first == nullptr; }

  void push_back(int a);
  void push_front(int a);
  void pop_front();

private:
  Node *first{};
  Node *last{};
  size_t count{};
};

List::List() : count{1} {
  first = new Node;
  first->data = 0;
  first->link = nullptr;
  last = first;
}

List::List(int _data) : count{1} {
  first = new Node;
  first->data = _data;
  first->link = nullptr;
  last = first;
}

List::List(const List &other) : count{other.count} {
  if (other.first == nullptr) {
    List();
  } else {
    Node *tmp_other_first = other.first;
    while (tmp_other_first != nullptr) {
      Node *new_node = new Node;
      new_node->data = tmp_other_first->data;
      new_node->link = nullptr;
      if (first == nullptr) {
        first = new_node;
        last = new_node;
      } else {
        last->link = new_node;
        last = new_node;
      }
      tmp_other_first = tmp_other_first->link;
    }
  }
}

List::~List() {
  while (first != nullptr) {
    Node *tmp = first;
    first = first->link;
    delete tmp;
  }
}

void List::push_back(int a) {
  Node *new_node = new Node;
  new_node->data = a;
  new_node->link = nullptr;
  if (first == nullptr) {
    first = new_node;
    last = new_node;
  } else {
    last->link = new_node;
    last = new_node;
  }
  ++count;
}

void List::push_front(int a) {
  Node *new_node = new Node;
  new_node->data = a;
  new_node->link = first;
  if (is_empty()) {
    last = new_node;
  }
  first = new_node;
  ++count;
}

void List::pop_front() {
  if (is_empty()) {
    std::cout << "List is empty\n";
    return;
  }
  Node *tmp = first;
  first = first->link;
  if (count == 1) {
    last = nullptr;
  }
  delete tmp;
  --count;
}

int List::get_front() const {
  if (is_empty()) {
    std::cout << "List is empty\n";
    return 0;
  }
  return first->data;
}

int List::get_back() const {
  if (is_empty()) {
    std::cout << "List is empty\n";
    return 0;
  }
  return last->data;
}

void List::print() const {
  if (is_empty()) {
    std::cout << "List is empty\n";
    return;
  }
  Node *tmp = first;
  while (tmp != nullptr) {
    std::cout << tmp->data << ' ';
    tmp = tmp->link;
  }
  std::cout << '\n';
}

int main() {

  List l{27};

  l.push_back(100);
  l.push_back(120);
  l.push_front(200);
  l.push_front(250);

  std::cout << "List l: ";
  l.print();

  std::cout << "Deleting first element l\n";
  l.pop_front();
  l.print();

  std::cout << "Create list l2 copy l\n";
  List l2{l};

  std::cout << "First element l2 = " << l2.get_front() << '\n'
            << "Last element l2 = " << l2.get_back() << '\n'
            << "List l2: ";
  l2.print();

  std::cout << "List l2 has " << l2.size() << " elements\n";

  return 0;
}
