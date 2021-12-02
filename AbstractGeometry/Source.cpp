#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define хы endl 

enum Color
{
	consol_gray = 0x88,
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_white = 0xFF
};

class FlatShape
{
protected:
	Color color;
public:
	const Color get_color()const
	{
		return color;
	}
	void set_color(Color color)
	{
		this->color = color;
	}
	FlatShape(Color color) :color(color)
	{
		this->color = color;
		cout << "FSConstructor:\t" << this << хы;
	}
	virtual ~FlatShape()
	{
		cout << "FSDestructor:\t" << this << хы;
	}

	virtual double get_space()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Circle :public FlatShape
{
	double radius;
public:
	const double get_radius()const
	{
		return radius;
	}
	void set_radius(double raduis)
	{
		if (radius <= 0)radius = 1;
		this->radius = radius;
	}
	Circle(double radius, Color color) :FlatShape(color)
	{
		set_color(color);
		set_radius(radius);
	}
	~Circle(){}
	double get_space()const
	{
		return 3.14*pow(get_radius(),2);
	}
	double get_perimeter()const	//Длинна окружности, а не площадь.
	{
		return (2*3.14*get_radius());
	}
	void draw()const
	{
		
	}

};

class Polygons :public FlatShape
{
protected:
	vector<double> number_of_sides{};
public:
	vector<double> get_number_of_sides()const
	{return number_of_sides;}

	double get_number_of_sides(int n)const
	{return number_of_sides[n];}

	void set_number_of_sides(int number)
	{this->number_of_sides.resize(number);}

	void set_value_of_sides(vector<double> numbers)
	{
		for (int i = 0; i < size(numbers); i++)
		{
			this->number_of_sides[i] = numbers[i];
		}
	}

	Polygons(Color color,int how_many_sides) :FlatShape(color)
	{
		set_number_of_sides(how_many_sides);
		cout << "PConstructor1:\t" << this << хы;
	}
	~Polygons(){}
};

class Rectangle :public Polygons
{
	double width;
	double length;
public:
	double get_width()const
	{return width;}

	double get_length()const
	{return length;}

	void set_width(double width)
	{this->width = width; }

	void set_length(double length)
	{this->length = length;}

	void set_side_rectangle(double width, double length)
	{
		if (width <= 0)width = 1;
		if (length <= 0)length = 1;
		vector<double> buffer{width, length,width,length};
		set_value_of_sides(buffer);
	}

	Rectangle(double width, double length, Color color) :Polygons(color,4)
	{
		set_width(width);
		set_length(length);
		set_side_rectangle(width, length);
		cout << "RConstructor1:\t" << this << хы;
	}
	~Rectangle(){}
	double get_space()const
	{
		return width*length;
	}
	double get_perimeter()const
	{
		return accumulate(number_of_sides.begin(), number_of_sides.end(), 0.0);
	}
	void draw()const
	{
		for (int i = 0; i < width; i++)
		{
			for (int i = 0; i < length; i++)
			{
				cout << "* ";
			}cout << хы;
		}
	}
};
class RegularFigure :public Polygons
{
protected:
	double side;
public:
	double get_side()const
	{
		return get_number_of_sides(0);
	}
	void set_side_figure(double side, int number)
	{
		if (side <= 0) side = 1;
		vector<double> buffer;
		buffer.resize(number);
		for (int i = 0; i < number;buffer[i] = side, i++)
		set_value_of_sides(buffer);
	}

	RegularFigure(double side, Color color, int how_many_sides) :Polygons(color, how_many_sides)
	{
		this->side = side;
		set_side_figure(side, how_many_sides);
		cout << "RFConstructor1:\t" << this << хы;
	}
	~RegularFigure() {}

	double get_perimeter()const
	{
		return side * size(number_of_sides);
	}
};

class Square :public RegularFigure
{
public:
	Square(double side, Color color, int how_many_sides = 4) :RegularFigure(side, color, how_many_sides)
	{
		this->side = side;
		set_side_figure(side, how_many_sides);
		cout << "SConstructor1:\t" << this << хы;
	}
	~Square(){}

	double get_space()const
	{
		return side * side;
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

class RegularTriangle :public RegularFigure
{
public:
	RegularTriangle(double side, Color color, int how_many_sides = 3) :RegularFigure(side, color, how_many_sides)
	{
		this->side = side;
		set_side_figure(side, how_many_sides);
		cout << "RTConstructor1:\t" << this << хы;
	}
	~RegularTriangle() {}
	double get_space()const
	{
		return (pow(side,2)*sqrt(3))/4;
	}
	void draw()const
	{
		double k = 1;
		for (double i = 0; i < side / 2; i += 0.5)
		{
			if ((int)side & 1)
			{
				for (int j = side / 2 - i; j > 0; j--)cout << "  ";
				for (int j = i + (int)k; j > 0; j--)cout << "* ";
			}
			else
			{
				double l = -0.5;
				if ((int)side != side)l = 0.5;
				for (int j = side / 2 - i + l; j > 0; j--)cout << "  ";
				for (double j = i + (int)k; j >= 0; j--)cout << "* ";
			}k += 0.5;
			cout << хы;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	Square Squ(6, Color::console_red);
	cout << "Площадь квадрата: " << Squ.get_space() << хы;
	cout << "Периметр квадрата: " << Squ.get_perimeter() << хы;
	Squ.draw();
	Rectangle Rec(5, 10, Color::console_red);
	cout << "Площадь прямоугольника: " << Rec.get_space() << хы;
	cout << "Периметр прямоугольника: " << Rec.get_perimeter() << хы;
	Rec.draw();
	RegularTriangle Tre(21.2, Color::console_red);
	cout << "Площадь правильного треугольника: " << Tre.get_space() << хы;
	cout << "Периметр правильного треугольника: " << Tre.get_perimeter() << хы;
	Tre.draw();
	Circle Cru(10, Color::console_red);
	cout << "Площадь круга: " << Cru.get_space() << хы;
	cout << "Длинна окружности: " << Cru.get_perimeter() << хы;
	Cru.draw();
}