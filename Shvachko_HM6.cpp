#include <iostream>

class Shape {
public:
  virtual int calc_square(int data, int data1) = 0;
  virtual void draw() = 0;
};

class Triangle : public Shape {
public:
  void draw() override { std::cout << "Area of triangle ->"; }
  int calc_square(int a, int b) override {
    int sq = (a * b) / 2;
    std::cout << sq << std::endl;
    return sq;
  }
};

class Square : public Shape {
public:
  void draw() override { std::cout << "Area of square ->"; }
  int calc_square(int a, int b) override {
    int sq = a * a;
    std::cout << sq << std::endl;
    return sq;
  }
};

class Rectangle : public Shape {
public:
  void draw() override { std::cout << "Area of rectangle ->"; }
  int calc_square(int a, int b) override {
    int sq = a * b;
    std::cout << sq << std::endl;
    return sq;
  }
};

void test(Shape &d) {
  d.draw();
  d.calc_square(5, 6);
}

int main() {
  Triangle t;
  test(t);
  Square s;
  test(s);
  Rectangle r;
  test(r);
  return 0;
}
