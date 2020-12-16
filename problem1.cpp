#include <cmath>
#include <iostream>

class Shape {
public:
  virtual ~Shape() {}
  
  virtual void calc_square() const = 0;
  virtual void draw() const = 0;
};

class Square : public Shape {
public:
  Square() = default;
  Square(uint32_t _a) : a{_a} {}

  void calc_square() const {
    long square = a * a;
    std::cout << "The square area equal " << square << '\n';
  }
    
  void draw() const {
    for (size_t i = 0; i < a; ++i) {
      std::cout << '*' << ' ';
      for (size_t n = 0; n < a - 2; ++n) {
        std::cout << ((i == 0 || i == (a - 1)) ? "* " : "  ");
      }
      std::cout << "*\n";
    }
  }

private:
  uint32_t a{};
};

class Rectangle : public Shape {
public:
  Rectangle() = default;
  Rectangle(uint32_t a, uint32_t b) : l{a}, w{b} {}

  void calc_square() const {
    long square = l * w;
    std::cout << "The rectangle area equal " << square << '\n';
  }
  void draw() const {
    for (size_t i = 0; i < w; ++i) {
      std::cout << '*' << ' ';
      for (size_t n = 0; n < l - 2; ++n) {
        std::cout << ((i == 0 || i == (w - 1)) ? "* " : "  ");
      }
      std::cout << "*\n";
    }
  }

private:
  uint32_t l{};
  uint32_t w{};
};

class Triangle : public Shape {
public:
  class Invalid {};
  Triangle(uint32_t _a, uint32_t _b, uint32_t _c) : a{_a}, b{_b}, c{_c} {
    if ((a + b) <= c || (a + c) <= b || (b + c) <= a) {
      throw Invalid{};
    }
  }

  void calc_square() const {
    long p = (a + b + c) / 2;
    long square = std::pow((p * (p - a) * (p - b) * (p - c)), 0.5);
    std::cout << "The triangle area equal " << square << '\n';
  }
    
  void draw() const {
    uint32_t max_side{};
    if (a >= b && a >= c) {
      max_side = a;
    } else if (b >= c && b >= a) {
      max_side = b;
    } else {
      max_side = c;
    }
    uint32_t half_side = max_side / 2 + 1;
    for (size_t i = 0; i < half_side; ++i) {
      for (size_t n = 0; n < half_side - i; ++n) {
        std::cout << "  ";
      }
      std::cout << "*";

      for (size_t k = max_side; k > (max_side - 2 * i); --k) {
        if (i == half_side - 1) {
          std::cout << "* ";
        } else {
          std::cout << "  ";
        }
      }
      if (i != 0) {
        std::cout << "*";
      }
      std::cout << '\n';
    }
  }

private:
  uint32_t a{};
  uint32_t b{};
  uint32_t c{};
};

void work_with_shape(const Shape *sh) {
  sh->calc_square();
  sh->draw();
}

int main() {

  Shape *sh = new Square{12};
  work_with_shape(sh);

  Rectangle rect{20, 12};
  Shape *sh2 = &rect;
  work_with_shape(sh2);

  Shape *sh3 = new Triangle{21, 17, 18};
  work_with_shape(sh3);
  
  delete sh3;
  delete sh;

  return 0;
}
