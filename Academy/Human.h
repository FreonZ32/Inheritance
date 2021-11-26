#pragma once
#include"Stdafx.h"

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const;
	const string& get_first_name()const;
	unsigned int get_age()const;
	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	void set_age(unsigned int age);

	Human();
	Human(const string& last_name, const string& first_name, unsigned int age);
	virtual ~Human();
	virtual ostream& print(ostream& os)const;
	virtual ofstream& print(ofstream& os)const;
	virtual istream& input(istream& is);
	virtual ifstream& input(ifstream& is);
	virtual void tofile()const;
};

ostream& operator<<(ostream& os, const Human& obj);
ofstream& operator<<(ofstream& os, const Human& obj);
istream& operator>>(istream& is, Human& obj);