#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include<string>
#include<windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define хы endl 

int getXcoord()
{
	CONSOLE_SCREEN_BUFFER_INFO info_x;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_x);
	return info_x.dwCursorPosition.X;
}

int getYcoord()
{
	CONSOLE_SCREEN_BUFFER_INFO info_y;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_y);
	return info_y.dwCursorPosition.Y;
}

int pth(int x, int y)
{
	return (int)sqrt(pow(x, 2) + pow(y, 2));
}

enum class Color
{
	/*consol_gray = 0x88,console_blue = 0x99,console_green = 0xAA,console_red = 0xCC,console_white = 0xFF*/
	consol_gray,console_blue,console_green,console_red,console_white,
	red = 0x000000FF, green = 0x0000FF00, blue = 0x00FF0000,yellow = 0x0000FFFF
};

const char* console_color[] =
{
	"88","99","AA","CC","FF"
};

namespace Geometry
{
	class FlatShape
	{
	protected:
		Color color;
	public:
		const Color get_color()const
		{
			return this->color;
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
		virtual void type_space()const = 0;
		virtual void type_perimeter()const = 0;
	};

	class Circle :public FlatShape
	{
		double radius;
	public:
		const double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		Circle(double radius, Color color) :FlatShape(color)
		{
			set_color(color);
			set_radius(radius);
		}
		~Circle() {}
		double get_space()const
		{
			return 3.14 * pow(get_radius(), 2);
		}
		double get_perimeter()const	//Длинна окружности, а не площадь.
		{
			return (2 * 3.14 * get_radius());
		}
		void draw()const
		{
			HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN);
			double r = int(radius - 1);
			const double length = r;
			const double width = r;
			for (double y = width; y >= -width; y--)
			{
				for (double x = -length; x <= length; x++)
				{
					if ((int)pth(x, y) == r) cout << "* ";
					else cout << "  ";
				}cout << хы;
			}
			SetConsoleTextAttribute(hwnd, 15);
		}
		void type_space()const
		{
			cout << "Площадь круга равна: ";
		}
		void type_perimeter()const
		{
			cout << "Длинна окружности равна: ";
		}
	};

	class Polygons :public FlatShape
	{
	protected:
		vector<double> number_of_sides{};
	public:
		vector<double> get_number_of_sides()const
		{
			return number_of_sides;
		}

		double get_number_of_sides(int n)const
		{
			return number_of_sides[n];
		}

		void set_number_of_sides(int number)
		{
			this->number_of_sides.resize(number);
		}

		void set_value_of_sides(vector<double> numbers)
		{
			for (int i = 0; i < size(numbers); i++)
			{
				this->number_of_sides[i] = numbers[i];
			}
		}

		Polygons(Color color, int how_many_sides) :FlatShape(color)
		{
			set_number_of_sides(how_many_sides);
			cout << "PConstructor1:\t" << this << хы;
		}
		~Polygons() {}
	};

	class Rectangle :public Polygons
	{
		double width;
		double length;
	public:
		double get_width()const
		{
			return width;
		}

		double get_length()const
		{
			return length;
		}

		void set_width(double width)
		{
			this->width = width;
		}

		void set_length(double length)
		{
			this->length = length;
		}

		void set_side_rectangle(double width, double length)
		{
			if (width <= 0)width = 1;
			if (length <= 0)length = 1;
			vector<double> buffer{ width, length,width,length };
			set_value_of_sides(buffer);
		}

		Rectangle(double width, double length, Color color) :Polygons(color, 4)
		{
			set_width(width);
			set_length(length);
			set_side_rectangle(width, length);
			cout << "RConstructor1:\t" << this << хы;
		}
		~Rectangle() {}
		double get_space()const
		{
			return width * length;
		}
		double get_perimeter()const
		{
			return accumulate(number_of_sides.begin(), number_of_sides.end(), 0.0);
		}
		void draw()const 
		{
			/*HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE);*/
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			//HDC hdc = GetDC(NULL);

			/*HANDLE hWndConsole;
			if (hWndConsole = GetStdHandle(-12))
			{
				CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
				if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
				{
					int widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
					int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
					printf("Widht: %d\n", widht);
					printf("Height: %d\n", height);
				}
				else
					printf("Error: %d\n", GetLastError());
			}
			else
				printf("Error: %d\n", GetLastError());*/
			int x = getXcoord();
			int y = getYcoord();
			//cout << getXcoord() << endl; cout << getYcoord() << endl;
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);	//тип отрисовки/толщина/цвет
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);

			::Rectangle(hdc, x, y*30, x+width*100, y * 30+length*100);
		
			DeleteObject(hPen);
			DeleteObject(hBrush);
			/*for (int i = 0; i < width; i++)
			{
				for (int i = 0; i < length; i++)
				{
					cout << "* ";
				}cout << хы;
			}*/
			/*SetConsoleTextAttribute(hwnd, 15);*/
		}
		void type_space()const
		{
			cout << "Площадь прямоугольника равна: ";
		}
		void type_perimeter()const
		{
			cout << "Периметр прямоугольника равен: ";
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
			for (int i = 0; i < number; buffer[i] = side, i++)
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
		~Square() {}

		double get_space()const
		{
			return side * side;
		}
		void draw()const
		{
			HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hwnd, FOREGROUND_RED);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}cout << endl;
			}
			SetConsoleTextAttribute(hwnd, 15);
		}
		void type_space()const
		{
			cout << "Площадь квадрата равна: ";
		}
		void type_perimeter()const
		{
			cout << "Периметр квадрата равен: ";
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
			return (pow(side, 2) * sqrt(3)) / 4;
		}
		void draw()const
		{
			HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY);
			double k = 1;
			for (double i = 0; i < side / 2; i += 0.5)
			{
				if ((int)side & 1)
				{
					for (int j = int(side / 2 - i); j > 0; j--)cout << "  ";
					for (int j = int(i + (int)k); j > 0; j--)cout << "* ";
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
			SetConsoleTextAttribute(hwnd, 15);
		}
		void type_space()const
		{
			cout << "Площадь правильного треугольника равна: ";
		}
		void type_perimeter()const
		{
			cout << "Периметр правильного треугольника равен: ";
		}
	};

}
//#define SIMPLE_CREATING
//#define RANDOM_GENERATING

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef SIMPLE_CREATING
	Geometry::Square Squ(6, Color::console_red);
	cout << "Площадь квадрата: " << Squ.get_space() << хы;
	cout << "Периметр квадрата: " << Squ.get_perimeter() << хы;
	Squ.draw();
	Geometry::RectangleC Rec(5, 10, Color::console_red);
	cout << "Площадь прямоугольника: " << Rec.get_space() << хы;
	cout << "Периметр прямоугольника: " << Rec.get_perimeter() << хы;
	Rec.draw();
	Geometry::RegularTriangle Tre(18.5, Color::console_red);
	cout << "Площадь правильного треугольника: " << Tre.get_space() << хы;
	cout << "Периметр правильного треугольника: " << Tre.get_perimeter() << хы;
	Tre.draw();
	Geometry::Circle Cru(25, Color::console_red);
	cout << "Площадь круга: " << Cru.get_space() << хы;
	cout << "Длинна окружности: " << Cru.get_perimeter() << хы;
	Cru.draw();
#endif // SIMPLE_CREATING

	
#ifdef RANDOM_GENERATING
	int l;
	cout << "Сколько фигур создать? "; cin >> l;
	Geometry::FlatShape** group;
	group = new FlatShape * [l];
	for (int i = 0; i < l; i++)
	{
		double rand1 = 4 + rand() % 30 * 0.12;
		double rand2 = 4 + rand() % 30 * 0.12;
		int k = rand() % 3;
		switch (k)
		{
		case 0:group[i] = new Geometry::Circle(rand1, Color::console_red); break;
		case 1:group[i] = new Geometry::RegularTriangle(rand1, Color::console_red); break;
		case 2:group[i] = new Geometry::Rectangle(rand1, rand2, Color::console_red); break;
		case 3:group[i] = new Geometry::Square(rand1, Color::console_red); break;
		default:break;
		}
	}
	for (int i = 0; i < l; i++)
	{
		group[i]->type_space(); cout << group[i]->get_space() << хы;
		group[i]->type_perimeter(); cout << group[i]->get_perimeter() << хы;
		group[i]->draw();
		cout << хы;
	}
#endif // RANDOM_GENERATING

	Geometry::Rectangle Rec(5, 10, Color::yellow);
	cout << "Площадь прямоугольника: " << Rec.get_space() << хы;
	cout << "Периметр прямоугольника: " << Rec.get_perimeter() << хы;
	Rec.draw();
}