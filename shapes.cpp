#include <iostream>
using namespace std;

class shape {
protected:
	int width, height;
public:
	void create(int a, int b)
	{
		width = a; height = b;
	}
};

class rectangle : public shape {
public:
	int area()
	{
		return width * height;
	}
};

class triangle : public shape {
public:
	int area()
	{
		return width * height / 2;
	}
};

int main() {
	rectangle rectangle1;
	triangle triangle1;

	rectangle1.create(10, 20);
	triangle1.create(10, 20);

	cout << rectangle1.area() << '\n';
	cout << triangle1.area() << '\n';
	return 0;
}