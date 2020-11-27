#include <iostream>

class Shape {
public:
	virtual void Draw() = 0;
	virtual void Calc_square() = 0;
};

class Square : public Shape {
	void Draw() { std::cout << "This is a Square" << std::endl; }
	void Calc_square() { std::cout << "The square = side*side" << std::endl; }
};

class Triangle : public Shape {
	void Draw() { std::cout << "This is Triangle" << std::endl; }
	void Calc_square() { std::cout << "The square = (h*a)/2" << std::endl; }
};

class Rectangle : public Shape {
	void Draw() { std::cout << "This is Rectangle" << std::endl; }
	void Calc_square() { std::cout << "The square = a*b" << std::endl; }
};

void test(Shape* sh) {
	sh->Draw();
	sh->Calc_square();
}

int main() {
	Square sq{};
	test(&sq);
	std::cout << std::endl;

	Triangle tr{};
	test(&tr);
	std::cout << std::endl;

	Rectangle re{};
	test(&re);

	return 0;
}
