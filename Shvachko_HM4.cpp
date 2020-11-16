#include <ctime>
#include <iostream>

using namespace std;

class Array {
private:
  int *arr;
  int size;

public:
  Array() //конструктор без параметров
  {
    size = 1;
    arr = new int[size];
    for (int i = 0; i < size; i++)
      arr[i] = 0;
  }
  Array(int s) //конструктор с одним параметром
  {
    size = s;
    arr = new int[size];
    set();
  }

  Array(const Array &source) //конструктор копирования
  {
    size = source.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
      arr[i] = source.arr[i];
  }

  ~Array() //деструктор
  {
    delete[] arr; //освобождение памяти
  }
  int getsize() //возвращение размера массива
  {
    return size;
  }

  void print() //показать массив
  {
    for (int i = 0; i < size; i++)
      cout << arr[i] << "  ";
    cout << endl;
  }

  void set() //ввод случайных элементов массива
  {
    srand(time(0));
    for (int i = 0; i < size; i++)
      arr[i] = rand() % 100;
  }

  void sort() //сортировка массива по возрастанию
  {
    int temp;
    for (int i = 0; i < size; i++) {
      temp = arr[i];
      for (int j = i; j < size; j++)
        if (temp > arr[j]) {
          temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
        }
    }
  }
  int max() {
    sort();
    return arr[size - 1];
  }
  int min() {
    sort();
    return arr[0];
  }
};

int main() {
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  Array array(n);
  cout << "Array:" << endl;
  array.print();
  array.sort();
  array.print();
  cout << "Max=" << array.max() << " Min=" << array.min() << endl;

  system("pause");
  return 0;
}
