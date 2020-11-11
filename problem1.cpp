#include <iostream>

struct Node {
  int data{};
  Node *link{};
};

struct Queue {
  Node *first{};
  Node *last{};
  size_t size{};
};

void push_queue(Queue *q);
void pop_queue(Queue *q);
int front_queue(Queue *q);
int back_queue(Queue *q);
bool empty_queue(Queue *q);

int main() {
  // create the queue of integers
  Queue q{};

  do {
    std::cout << "Enter what do you want do?\n"
              << "1 - add integer to end of queue;\n"
              << "2 - delete integer from front of queue;\n"
              << "3 - return first element;\n"
              << "4 - return last element;\n"
              << "5 - check if the queue is empty;\n"
              << "0 - Exit.\n";

    enum class List { EXIT, PUSH, POP, FRONT, BACK, EMPTY };

    int choose{};
    std::cin >> choose;

    List queue_method = static_cast<List>(choose);

    switch (queue_method) {
    case List::PUSH:
      push_queue(&q);
      break;
    case List::POP:
      pop_queue(&q);
      break;
    case List::FRONT:
      std::cout << "The first value is " << front_queue(&q) << '\n';
      break;
    case List::BACK:
      std::cout << "The last value is " << back_queue(&q) << '\n';
      break;
    case List::EMPTY:
      std::cout << ((empty_queue(&q)) ? "NO EMPTY\n" : "EMPTY\n");
      break;
    case List::EXIT:
      return 0;
    default:
      std::cout << "incorrect input\n";
      continue;
    }

  } while (true);

  return 0;
}

void push_queue(Queue *q) {
  std::cout << "Please enter the integer\n";
  int var{};
  std::cin >> var;
  if (!std::cin) {
    std::cout << "incorrect input\n";
    return;
  }
  Node *new_node = new Node;
  new_node->data = var;
  new_node->link = nullptr;
  if (q->first == nullptr) {
    q->first = new_node;
    q->last = new_node;
  } else {
    q->last->link = new_node;
    q->last = new_node;
  }
  ++q->size;
}

void pop_queue(Queue *q) {
  if (q == nullptr) {
    std::cout << "incorrect parametr\n";
    return;
  }
  Node *tmp = q->first;
  q->first = q->first->link;
  delete tmp;
}

int front_queue(Queue *q) {
  if (q == nullptr) {
    std::cout << "incorrect parametr\n";
    return -1;
  }
  return q->first->data;
}

int back_queue(Queue *q) {
  if (q == nullptr) {
    std::cout << "incorrect parametr\n";
    return -1;
  }
  return q->last->data;
}

bool empty_queue(Queue *q) { return (q->first == nullptr) ? false : true; }
