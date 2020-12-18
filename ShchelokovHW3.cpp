№1
#include <iostream>
int main() {
  char string[] = "Hello world!";
  std::cout << "Your string: " << string << std::endl;
  int lenght = strlen(string);
  int temp{0}, i{0}, j{0};
  for (i = 0, j = lenght - 1; i < j; i++, j--) {
    temp = string[i];
    string[i] = string[j];
    string[j] = temp;
  }
  std::cout << "Your reversed string: " << string << std::endl;
  return 0;
}

№2
#include <iostream>
int main() {
  int arr[5];
  std::cout << "Enter a values of arr:" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << "arr[" << i << "] = ";
    std::cin >> arr[i];
  }
  int temp;
  for (int i = 0; i < 5 - 1; i++) {
    for (int j = 0; j < 5 - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  std::cout << "Your sort arr:" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << "arr[" << i << "] = ";
    std::cout << arr[i] << std::endl;
  }
  return 0;
}
