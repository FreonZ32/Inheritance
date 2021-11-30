#pragma once
#include"Stdafx.h"

#pragma once
#include"Stdafx.h"

class Human
{
	string last_name;
	string first_name;
public:
	const string& get_last_name()const;
	const string& get_first_name()const;
	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);

	Human();
	Human(const string& last_name, const string& first_name);
	virtual ~Human();
	virtual ostream& print(ostream& os)const;
	virtual ofstream& print(ofstream& os)const;
	virtual istream& input(istream& is);
	virtual ifstream& input(ifstream& is);
};

ostream& operator<<(ostream& os, const Human& obj);
ofstream& operator<<(ofstream& os, const Human& obj);
istream& operator>>(istream& is, Human& obj);