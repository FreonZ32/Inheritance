#pragma once
#include"Human.h"

class Profession :public Human
{
	string profession;
	string type_of_payment;
	unsigned int experience;
public:
	const string& get_profession()const;
	const string& get_type_of_payment()const;
	const unsigned int get_experience()const;
	void set_profession(const string& profession);
	void set_type_of_payment(const string& type_of_payment);
	void set_experience(const unsigned int experience);

	Profession();
	Profession(const string& last_name, const string& first_name, const string& profession, const string& type_of_payment, const unsigned int experience);
	~Profession();

	ostream& print(ostream& os)const;
	ofstream& print(ofstream& os)const;
	istream& input(istream& is);
	ifstream& input(ifstream& is);
};