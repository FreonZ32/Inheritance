#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

enum Color
{
	consol_gray = 0x88,
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_white = 0xFF
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color)
	{
		cout << "ShConstructor:\t" << this << endl;
	}
	virtual ~Shape()
	{
		cout << "ShDestructor:\t" << this << endl;
	}
	virtual double get_Area()const = 0;
	virtual double get_Perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side <= 0) side = 1;
		this->side = side;
	}
	Square(double side, Color color) : Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}
	double get_Area()const
	{
		return side * side;
	}
	double get_Perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	Square Squ(5, Color::console_red);
	cout << "Площадь квадрата: " << Squ.get_Area() << endl;
	cout << "Периметр квадрата: " << Squ.get_Perimeter() << endl;
	Squ.draw();
}