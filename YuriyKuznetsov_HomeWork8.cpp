// Реализовать переопределение метода базового класса в
//производных классах применив виртуальные функциии

#include <cmath>
#include <iostream>

class Shape {
public:
  virtual void Draw() = 0;
  virtual double CalcSquare() = 0;
};

class Square : public Shape {
public:
  void Draw() override;
  double CalcSquare() override;

  void Side(const unsigned int in_uiSide) { uiSide__ = in_uiSide; }
  unsigned int Side() { return uiSide__; }

private:
  unsigned int uiSide__{};
};

struct RectSides {
  unsigned int uiSideOne;
  unsigned int uiSideTwo;

  RectSides &operator=(const RectSides &in_Sides) {
    uiSideOne = in_Sides.uiSideOne;
    uiSideTwo = in_Sides.uiSideTwo;
    return *this;
  }
};

class Rectangle : public Shape {
public:
  void Draw() override;
  double CalcSquare() override;

  void Sides(const RectSides in_Sides) { Sides__ = in_Sides; }
  RectSides Sides() { return Sides__; }

private:
  RectSides Sides__{};
};

struct TriangleSides {
  unsigned int uiSideOne;
  unsigned int uiSideTwo;
  unsigned int uiSideThree;

  TriangleSides &operator=(const TriangleSides &in_Sides) {
    uiSideOne = in_Sides.uiSideOne;
    uiSideTwo = in_Sides.uiSideTwo;
    uiSideThree = in_Sides.uiSideThree;
    return *this;
  }
};

class Triangle : public Shape {
public:
  void Draw() override;
  double CalcSquare() override;

  void Sides(const TriangleSides in_Sides) { Sides__ = in_Sides; }
  TriangleSides Sides() { return Sides__; }

  Triangle() = default;
  Triangle(TriangleSides in_Sides) { Sides__ = in_Sides; }

private:
  TriangleSides Sides__{};
};

void f(Shape *in_Shape) {
  in_Shape->Draw();
  in_Shape->CalcSquare();
}

int main() {
  Square mySquare{};
  mySquare.Side(20);

  RectSides SidesForRect{20, 50};
  Rectangle myRect{};
  myRect.Sides(SidesForRect);

  TriangleSides SidesForTriangle{17, 20, 30};
  Triangle myTrian(SidesForTriangle);

  f(&mySquare);
  f(&myRect);
  f(&myTrian);

  return 0;
}

void Square::Draw() {
  std::cout << "Drawing a square with a side: " << uiSide__ << '\n';
}

double Square::CalcSquare() {
  double dArea{static_cast<double>(uiSide__) *
               uiSide__}; // without checking for overlimit
  std::cout << "The area of the square with a side: " << uiSide__
            << " is: " << dArea << '\n';
  return dArea;
}

void Rectangle::Draw() {
  std::cout << "Drawing a rectangle with sides: " << Sides__.uiSideOne
            << " and " << Sides__.uiSideTwo << '\n';
}

double Rectangle::CalcSquare() {
  double dArea{static_cast<double>(Sides__.uiSideOne) *
               Sides__.uiSideTwo}; // without checking for overlimit
  std::cout << "The area of the rectangle with sides: " << Sides__.uiSideOne
            << " and " << Sides__.uiSideTwo << " is " << dArea << '\n';
  return dArea;
}

void Triangle::Draw() {
  std::cout << "Drawing a triangle with sides: " << Sides__.uiSideOne << " , "
            << Sides__.uiSideTwo << " and " << Sides__.uiSideThree << '\n';
}

double Triangle::CalcSquare() {
  constexpr double dHalf{1/2};
  double dHalfPerimeter{
      dHalf * (Sides__.uiSideOne + Sides__.uiSideTwo +
             Sides__.uiSideThree)}; // without checking for overlimit
  double dArea{std::sqrt(dHalfPerimeter * (dHalfPerimeter - Sides__.uiSideOne) *
                         (dHalfPerimeter - Sides__.uiSideTwo) *
                         (dHalfPerimeter - Sides__.uiSideThree))};
  std::cout << "The area of the triangle with sides: " << Sides__.uiSideOne
            << " , " << Sides__.uiSideTwo << " and " << Sides__.uiSideThree
            << " is " << dArea << '\n';
  return dArea;
}
