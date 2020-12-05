#include <iostream>

class Stack_Singleton {
public:
  static Stack_Singleton& get_instance() {
    static Stack_Singleton stack{};
    return stack;
  }

  bool push_stack(int a);
  bool pop_stack();
  bool empty_stack() const { return current < 0; }
  int top_stack() const;
  void print_stack() const;

private:
  inline static int *array{nullptr};
  static constexpr size_t Size_Array{10};
  int current{-1};

  Stack_Singleton();
  ~Stack_Singleton();
  Stack_Singleton(const Stack_Singleton &other) = delete;
  Stack_Singleton operator=(const Stack_Singleton &other) = delete;
};

Stack_Singleton::Stack_Singleton() : current{-1} {
  if (Size_Array > 0) {
    array = new int[Size_Array];
  }
}

Stack_Singleton::~Stack_Singleton() {
  if (array != nullptr) {
    delete[] array;
  }
}

bool Stack_Singleton::push_stack(int a) {
  if (Size_Array == current + 1 || array == nullptr) {
      std::cout << "invalid operation\n";
    return false;
  }
  array[++current] = a;
  return true;
}

bool Stack_Singleton::pop_stack() {
    if (current < 0 || array == nullptr) {
	std::cout << "invalid operation\n";
    return false;
  } 
  --current;
  return true;
}

int Stack_Singleton::top_stack() const {
  if (array == nullptr || Size_Array <= 0) {
    std::cout << "invalid operation\n";
    return 0;
  }
  return array[current];
}

void Stack_Singleton::print_stack() const {
  if (!empty_stack() && array != nullptr) {
    for (int i = 0; i <= current; ++i) {
      std::cout << array[i] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {

  Stack_Singleton &st = Stack_Singleton::get_instance();

  st.push_stack(100);
  st.push_stack(150);
  st.pop_stack();
  st.push_stack(-25);
  st.push_stack(50);

  std::cout << "Stack st contains: ";
  st.print_stack();

  Stack_Singleton &st2 = Stack_Singleton::get_instance();

  st2.pop_stack();
  st2.push_stack(200);

  std::cout << "Stack st2 contains: ";
  st.print_stack();

  std::cout << "Top st2 equal: " << st2.top_stack() << '\n';

  return 0;
}
