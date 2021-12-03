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
int getStringHeight()
{
	int width = 0;
	int height = 0;

	HANDLE hWndConsole;
	if (hWndConsole = GetStdHandle(-12))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
		{
			//widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
			//printf("Widht: %d\n", widht);printf("Height: %d\n", height);
		}
		else printf("Error: %d\n", GetLastError());
	}
	else printf("Error: %d\n", GetLastError());
	return height;
}
void FullScreenOn()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80,50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);
	Sleep(100);
}
void AnalogPause()
{
	cout << "Press enter to continue!\n";
	cin.ignore();
}
void setCousorPosition(int x,int y)
{
	COORD position = { x,y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}
int pth(int x, int y)
{
	return (int)sqrt(pow(x, 2) + pow(y, 2));
}

enum class Color
{
	pink = 0x00AA00FF,
	grass = 0x0000F0C0,
	light_blue = 0x00FFFF00,
	sea_wave = 0x00AFAA0C,
	white = 0x00FFFFFF,
	red = 0x000000FF,
	green = 0x0000FF00,
	blue = 0x00FF0000,
	yellow = 0x0000FFFF,
	grey = 0x00AAAAAA,
	orange = 0x000AAFFA,
	sky = 0x00FFADAA
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
			//cout << "FSConstructor:\t" << this << хы;
		}
		virtual ~FlatShape()
		{
			//cout << "FSDestructor:\t" << this << хы;
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
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);	//тип отрисовки/толщина/цвет
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);
			int x = getXcoord(); 
			int y = getYcoord(); 
			setCousorPosition(0,((y+((radius * 2) / 0.258*10)/ 30)*2));
			Sleep(200);
			::Ellipse(hdc, 0, y * 30, 0 + (radius*2) / 0.258 * 10, y * 30 + (radius*2) / 0.258 * 10);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			/*HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
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
			SetConsoleTextAttribute(hwnd, 15);*/
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
			//cout << "PConstructor1:\t" << this << хы;
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
			if (width <= 0)width = 1;
			this->width = width;
		}

		void set_length(double length)
		{
			if (length <= 0)length = 1;
			this->length = length;
		}

		void set_side_rectangle(double width, double length)
		{
			vector<double> buffer{ width, length,width,length };
			set_value_of_sides(buffer);
		}

		Rectangle(double width, double length, Color color) :Polygons(color, 4)
		{
			set_width(width);
			set_length(length);
			set_side_rectangle(width, length);
			//cout << "RConstructor1:\t" << this << хы;
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
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);
			int x = getXcoord();
			int y = getYcoord(); 
			setCousorPosition(0, (y + ((width * 2) / 0.258 * 10) / 30)+2);
			Sleep(200);
			::Rectangle(hdc, 0, y*30, 0 + (length/0.258)* 10, y * 30 + (width/0.258) * 10);
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
		void set_side(double side)
		{
			this->side = side;
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
			set_side(side);
			set_side_figure(side, how_many_sides);
			//cout << "RFConstructor1:\t" << this << хы;
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
			//cout << "SConstructor1:\t" << this << хы;
		}
		~Square() {}

		double get_space()const
		{
			return side * side;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);
			int x = getXcoord();
			int y = getYcoord();
			setCousorPosition(0, (y + ((side * 2) / 0.258 * 10) / 30) + 2);
			Sleep(200);
			::Rectangle(hdc, 0, y * 30, 0 + (side / 0.258) * 10, y * 30 + (side / 0.258) * 10);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			/*for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}cout << endl;
			}*/
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
			//cout << "RTConstructor1:\t" << this << хы;
		}
		~RegularTriangle() {}
		double get_space()const
		{
			return (pow(side, 2) * sqrt(3)) / 4;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);
			int x = getXcoord();
			int y = getYcoord();
			//cout << getXcoord() << " " << getYcoord();
			setCousorPosition(0, ( y + ((side*sqrt(3)/2) / 0.3)));
			Sleep(200);
			const int N = 3;
			POINT Pt[N];
			Pt[0].x = (side/2)/0.258*10;Pt[0].y = y*30;
			Pt[1].x = 0;Pt[1].y = y * 30+(side*sqrt(3)/2)/0.258*10;
			Pt[2].x = side/0.259*10;Pt[2].y = y * 30+(side * sqrt(3) / 2) / 0.258*10;
			Polygon(hdc,Pt, N);
			DeleteObject(hPen);DeleteObject(hBrush);
			/*double k = 1;
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
			}*/
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
	class IsoscalesTriangle :public Polygons
	{
		double equal_side;
		double base;
		double hight;
	public:
		double get_equal_side()const
		{
			return equal_side;
		}
		double get_base()const
		{
			return base;
		}
		double get_hight()const
		{
			return hight;
		}
		void set_equal_side(double equal_side)
		{
			if (equal_side * 2 <= base)equal_side = base / 2 + 1;
			this->equal_side = equal_side;
		}
		void set_base(double base)
		{
			if (base <= 0)base = 1;
			this->base = base;
		}
		void set_hight(double equal_side, double base)
		{
			this->hight = 0.5 * sqrt(4 * pow(equal_side, 2) - pow(base, 2));
		}
		void set_side_triangle(double equal_side, double base)
		{
			vector<double> buffer{ equal_side,equal_side, base };
			set_value_of_sides(buffer);
		}
		IsoscalesTriangle(double equal_side, double base, Color color) :Polygons(color, 3)
		{
			set_base(base);
			set_equal_side(equal_side);
			set_side_triangle(equal_side, base);
			set_hight(equal_side, base);
			//cout << "ITConstructor1:\t" << this << хы;
		}
		~IsoscalesTriangle() {}

		double get_space()const
		{
			return hight * (base / 2);
		}
		double get_perimeter()const
		{
			return accumulate(number_of_sides.begin(), number_of_sides.end(), 0.0);
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);
			int x = getXcoord();
			int y = getYcoord();
			setCousorPosition(0, (y*30 + hight / 0.258*10)/15);
			Sleep(200);
			const int N = 3;
			POINT Pt[N];
			Pt[0].x = (base / 2) / 0.258 * 10; Pt[0].y = y * 30;
			Pt[1].x = 0; Pt[1].y = (y * 30 + hight / 0.258 * 10);
			Pt[2].x = base / 0.259 * 10; Pt[2].y = (y * 30 + hight / 0.258 * 10);
			Polygon(hdc, Pt, N);
			DeleteObject(hPen); DeleteObject(hBrush);
		}
		void type_space()const
		{
			cout << "Площадь равнобедренного треугольника равна: ";
		}
		void type_perimeter()const
		{
			cout << "Периметр равнобедренного треугольника равен: ";
		}
	};
	class RightTriangle :public Polygons
	{
		double side;
		double base_side;
		double hypotenuse;
	public:
		double get_side()const
		{
			return side;
		}
		double get_base_side()const
		{
			return base_side;
		}
		double get_hypotenuse()const
		{
			return hypotenuse;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		void set_base_side(double base_side)
		{
			if (base_side <= 0)base_side = 1;
			this->base_side = base_side;
		}
		void set_hypotenuse(double hypotenuse)
		{
			if (pow(hypotenuse, 2) != pow(base_side, 2) + pow(side, 2))hypotenuse = sqrt(pow(base_side, 2) + pow(side, 2));
			this->hypotenuse = hypotenuse;
		}
		void set_side_triangle(double side, double base_side, double hypotenuse)
		{
			vector<double> buffer{ side,base_side,hypotenuse };
			set_value_of_sides(buffer);
		}
		RightTriangle(double side, double base_side, double hypotenuse, Color color) :Polygons(color, 3)
		{
			set_side(side);
			set_base_side(base_side);
			set_hypotenuse(hypotenuse);
			set_side_triangle(side, base_side, hypotenuse);
			//cout << "ITConstructor1:\t" << this << хы;
		}
		~RightTriangle(){}
		double get_space()const
		{
			return (side*base_side)/2;
		}
		double get_perimeter()const
		{
			return accumulate(number_of_sides.begin(), number_of_sides.end(), 0.0);
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HBRUSH hBrush = CreateSolidBrush((COLORREF)color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			HPEN hPen = CreatePen(PS_SOLID, 1, (COLORREF)color);
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
			SelectObject(hdc, hPen);
			int x = getXcoord();
			int y = getYcoord();
			setCousorPosition(0, (y * 30 + side / 0.258 * 10) / 15);
			Sleep(200);
			const int N = 3;
			POINT Pt[N];
			Pt[0].x = 0; Pt[0].y = y * 30;
			Pt[1].x = 0; Pt[1].y = y * 30 + side / 0.258 * 10;
			Pt[2].x = base_side / 0.258 * 10; Pt[2].y = y * 30 + side / 0.258 * 10;
			Polygon(hdc, Pt, N);
			DeleteObject(hPen); DeleteObject(hBrush);
		}
		void type_space()const
		{
			cout << "Площадь прямоугольного треугольника равна: ";
		}
		void type_perimeter()const
		{
			cout << "Периметр прямоугольного треугольника равен: ";
		}
	};
}
#define SIMPLE_CREATING
//#define RANDOM_GENERATING
//#define RANDOM_GENERATE
void main()
{
	setlocale(LC_ALL, "rus");
#ifdef SIMPLE_CREATING
	Geometry::Circle Cru(4, Color::pink);
	Cru.type_space();cout << Cru.get_space() << хы;
	Cru.type_perimeter(); cout << Cru.get_perimeter() << хы;
	Cru.draw();
	AnalogPause();
	system("CLS");
	Geometry::Rectangle Rec(5, 8, Color::sky);
	Rec.type_space(); cout << Rec.get_space() << хы;
	Rec.type_perimeter(); cout << Rec.get_perimeter() << хы;
	Rec.draw();
	AnalogPause();
	system("CLS");
	Geometry::Square Squ(6, Color::grass);
	Squ.type_space(); cout << Squ.get_space() << хы;
	Squ.type_perimeter(); cout << Squ.get_perimeter() << хы;
	Squ.draw();
	AnalogPause();
	system("CLS");
	Geometry::RegularTriangle Tre(7, Color::light_blue);
	Tre.type_space(); cout << Tre.get_space() << хы;
	Tre.type_perimeter(); cout << Tre.get_perimeter() << хы;
	Tre.draw();
	AnalogPause();
	system("CLS");
	Geometry::IsoscalesTriangle IsTre(10,7, Color::sea_wave);
	IsTre.type_space(); cout << IsTre.get_space() << хы;
	IsTre.type_perimeter(); cout << IsTre.get_perimeter() << хы;
	IsTre.draw();
	AnalogPause();
	system("CLS");
	Geometry::RightTriangle RTre(12, 5, 13, Color::orange);	//Пифагоровы тройки (3, 4, 5)(5, 12, 13)(8, 15, 17)(7, 24, 25)(20, 21, 29)
	RTre.type_space(); cout << RTre.get_space() << хы;
	RTre.type_perimeter(); cout << RTre.get_perimeter() << хы;
	RTre.draw();
	//cout << RTre.get_side() << " " << RTre.get_base_side() << " " << RTre.get_hypotenuse() << endl;
	AnalogPause();
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

#ifdef RANDOM_GENERATE
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	int i = 0;
	while (i < 200)
	{
		int red = rand() % 256;
		int green = rand() % 256;
		int blue = rand() % 256;
		HBRUSH hBrush = CreateSolidBrush(RGB(red, green, blue));
		HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		HPEN hPen = CreatePen(PS_SOLID, 1, RGB(red, green, blue));	//тип отрисовки/толщина/цвет
		HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
		SelectObject(hdc, hPen);
		Sleep(200);
		double rand1 = 0 + rand() % 30;
		double rand2 = 0 + rand() % 100;
		int k = rand() % 20;
		setCousorPosition(0, k);
		::Ellipse(hdc, rand2, rand1 * 30, rand2 + (k * 2) / 0.258 * 10, rand1 * 30 + (k * 2) / 0.258 * 10);
		Sleep(200);
		i++;
		system("CLS");
		DeleteObject(hPen);
		DeleteObject(hBrush);
	}
#endif // RANDOM_GENERATE

		
}