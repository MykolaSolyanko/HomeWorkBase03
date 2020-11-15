#include <ctime>
#include <iostream>

using namespace std;

class Array {
private:
  int *arr;
  int N;

public:
  Array() //конструктор без параметров
  {
    N = 1;
    arr = new int[N];
    for (int i = 0; i < N; i++)
      arr[i] = 0;
  }
  Array(int n) //конструктор с одним параметром
  {
    N = n;
    arr = new int[N];
    set();
  }

  Array(const Array &source) //конструктор копирования
  {
    N = source.N;
    arr = new int[N];
    for (int i = 0; i < N; i++)
      arr[i] = source.arr[i];
  }

  ~Array() //деструктор
  {
    delete[] arr; //освобождение памяти
  }
  int getsize() //возвращение размера массива
  {
    return N;
  }

  void print() //показать массив
  {
    for (int i = 0; i < N; i++)
      cout << arr[i] << "  ";
    cout << endl;
  }

  void set() //ввод случайных элементов массива
  {
    srand(time(0));
    for (int i = 0; i < N; i++)
      arr[i] = rand() % 100;
  }

  void sort() //сортировка массива по возрастанию
  {
    int temp; // переменные для хранения мин-ного значения и индекса массива
    for (int i = 0; i < N; i++) {
      temp = arr[i]; //инициализируем врем. переменную
      for (int j = i; j < N; j++)
        if (temp > arr[j]) //находим минимальный элемент
        {
          temp = arr[j]; //делаем перестановку
          arr[j] = arr[i];
          arr[i] = temp;
        }
    }
  }
  int max() {
    sort();
    return arr[N - 1];
  }
  int min() {
    sort();
    return arr[0];
  }
};

int main() {
  setlocale(LC_CTYPE, "rus");
  int n;
  cout << "Введите размер массива: ";
  cin >> n;
  Array array(n);
  cout << "Массив" << endl;
  array.print();
  array.sort();
  array.print();
  cout << "Max=" << array.max() << " Min=" << array.min() << endl;

  system("pause");
  return 0;
}
