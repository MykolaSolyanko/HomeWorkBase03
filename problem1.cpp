#include <iostream>

template <typename T>
struct Node {
  T data{};
  Node *prev{};
  Node *next{};
};

template <typename T>
class Stack {
public:
  Stack(T a);
  ~Stack();
  Stack(const Stack &other);
  T top() const { return (head != nullptr) ? current->data : -1; }
  bool empty() const { return (head == nullptr) ? true : false; }
  void print() const;
  void push(T val);
  void pop();

private:
  Node<T> *head{};
  Node<T> *current{};
};

template <typename T>
Stack<T>::Stack(T a) {
  Node<T> *tmp = new Node<T>;
  tmp->data = a;
  tmp->prev = head;
  tmp->next = nullptr;
  head = tmp;
  current = tmp;
}

template <typename T>
Stack<T>::~Stack() {
  if (head != nullptr) {
    while (head != nullptr) {
      Node<T> *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
}

template <typename T>
Stack<T>::Stack(const Stack &other) {
  Node<T> *tmp_head = other.head;
  while (tmp_head != nullptr) {
    Node<T> *tmp = new Node<T>;
    if (head == nullptr) {
      tmp->data = tmp_head->data;
      tmp->prev = head;
      tmp->next = nullptr;
      head = tmp;
      current = tmp;
    } else {
      tmp->data = tmp_head->data;
      tmp->prev = current;
      tmp->next = nullptr;
      current->next = tmp;
      current = tmp;
    }
    tmp_head = tmp_head->next;
  }
}

template <typename T>
void Stack<T>::print() const {
  if (head == nullptr) {
    std::cout << "Stack is empty\n";
    return;
  }
  Node<T> *tmp = head;
  while (tmp != nullptr) {
    std::cout << tmp->data << ' ';
    tmp = tmp->next;
  }
  std::cout << '\n';
}

template <typename T>
void Stack<T>::push(T val) {
  if (head == nullptr) {
    std::cout << "Stack is not allocated\n";
    return;
  }
  Node<T> *tmp = new Node<T>;
  tmp->data = val;
  tmp->prev = current;
  tmp->next = nullptr;
  current->next = tmp;
  current = tmp;
}

template <typename T>
void Stack<T>::pop() {
  if (head == nullptr) {
    std::cout << "Stack is not allocated\n";
    return;
  }
  Node<T> *tmp = current;
  if (head == current) {
    head = nullptr;
    current = nullptr;
  } else {
    current = current->prev;
    current->next = nullptr;
  }
  delete tmp;
}

int main() {
  Stack<int> st{12};
  st.push(25);
  st.push(35);
  st.push(45);
  std::cout << "Top stack value is " << st.top() << '\n';
  std::cout << std::boolalpha << st.empty() << '\n';
  st.pop();
  st.print();

  Stack<char> st_char{'H'};
  st_char.push('!');
  std::cout << "Top stack value is " << st_char.top() << '\n';
  st_char.pop();
  st_char.pop();
  std::cout << std::boolalpha << st_char.empty() << '\n';

  Stack<int> st_int{st};
  st_int.push(100);
  st_int.print();

  return 0;
}
