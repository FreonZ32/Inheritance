#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Vehicle
{
	int speed;
public:
	virtual void move() const = 0;
};

class GroundVehicle : public Vehicle
{

};
class WaterVehicle :public Vehicle
{

};
class AirVehicle :public Vehicle
{
	int height;
};

class Bike :GroundVehicle
{
public:
	void move() const
	{
		cout << "�������� ���� �� ���� �������" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move() const
	{
		cout << "������ ���� �� ������� �������" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move()const
	{
		cout << "����� ������� �� ������ �����������" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	//Vehical v;
	//GroundVehicle gv;
	Bike HD;
	HD.move();
	Car VW;
	VW.move();
	Boat Hesoyam;
	Hesoyam.move();
}