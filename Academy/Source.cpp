#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstrucror:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " ���.\n";
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{return speciality;}
	const string& get_group()const
	{return group;}
	double get_rating()const
	{return rating;}
	void set_speciality(const string& speciality)
	{this->speciality = speciality;}
	void set_group(const string& group)
	{this->group = group;}
	void set_rating(double rating)
	{this->rating = rating;}

	Student(const string& last_name, const string& first_name, unsigned int age,
			const string& speciality, const string& group, double rating):Human(last_name, first_name, age)//���������� ����������� �������� ������
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void print()const
	{
		Human::print();
		cout << "�������������: " << speciality << ", ������: " << group << ", ������������: " << rating << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	Human h("Montana", "Antonio", 35);
	h.print();

	Student s("Pinkman", "Jessy", 22, "Methamphimamine manufacture", "WW_01", 93);
	s.print();
}