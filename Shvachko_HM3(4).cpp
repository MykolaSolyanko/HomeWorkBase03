#include <iostream>

int UpperCase(int ch) { return (('a' <= ch) && (ch <= 'z')) ? ch - 32 : ch; }

char *Upper(char *text) {
  char *p = text;
  for (; *p; ++p) {
    *p = UpperCase(*p);
  }
  return text;
}

int main() {
  std::cout
      << "Enter string, the program will convert the string to uppercase.\n";
  std::cout << "String--->  ";
  char text[256];
  std::cin >> text;

  std::cout << Upper(text);

  return 0;
}
