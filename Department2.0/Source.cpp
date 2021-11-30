#include<iostream>
#include<fstream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

enum type_of_pay
{
	NOU_WORKING_YET,BY_HOUR,BY_MONTH
};

string get_type_of_pay(type_of_pay obj)
{
	switch (obj)
	{
	case 0:return string("Not_working_yet"); break;
	case 1:return string("By_Hour"); break;
	case 2:return string("By_month"); break;
	default: break;
	}
}

class Human
{
	string last_name;
	string first_name;
public:
	const string& get_last_name()const
	{return last_name;}

	const string& get_first_name()const
	{return first_name;}

	void set_last_name(const string& last_name)
	{this->last_name = last_name;}

	void set_first_name(const string& first_name)
	{this->first_name = first_name;}
	
	Human()
	{
		set_last_name("last_name");
		set_first_name("first_name");
	}
	Human(const string& last_name, const string& first_name)
	{
		set_last_name(last_name);
		set_first_name(first_name);
	}
	virtual~Human() {};

	virtual void print()const
	{
		cout << last_name << "," << first_name;
	}
	virtual ofstream print_in_file(ofstream& os)const
	{
		os << typeid(*this).name() << "," << last_name << "," << first_name;
	}
};

class Worker :public Human
{
	string profession;
	unsigned int experience;
	type_of_pay pay;
public:
	const string& get_profession()const
	{return profession;}

	unsigned int get_experience()const
	{return experience;}

	const type_of_pay get_pay()const
	{return pay;}

	void set_profession(const string& profession)
	{this->profession = profession;}

	void set_experience(unsigned int experience)
	{this->experience = experience;}

	void set_pay(type_of_pay pay)
	{this->pay = pay;}

	Worker():Human()
	{
		set_profession("profession");
		set_experience(0);
		set_pay(NOU_WORKING_YET);
	}
	Worker(const string& last_name, const string& first_name, const string& profession, unsigned int experience,type_of_pay pay = NOU_WORKING_YET)
		:Human(last_name,first_name)
	{
		set_profession(profession);
		set_pay(pay);
		set_experience(experience);
	}
	~Worker() {};

	void print()const
	{
		Human::print();
		cout << "," << profession << "," << get_type_of_pay(pay) << "," << experience;
	}
	ofstream print_to_file(ofstream& os)
	{
		Human::print_in_file(os);
		os << "," << profession << "," << get_type_of_pay(pay) << "," << experience;
	}
};

class Worker_by_hour :Worker
{
	double salary;
	unsigned int hours;
	double final_pay;
public:
	const double get_salary()const
	{return salary;}
	const unsigned int get_hours()const
	{return hours;}
	const double get_final_pay()const
	{return final_pay;}
};
 

void main()
{
	setlocale(LC_ALL, "rus");
}