#pragma once
#include"Profession.h"

class Hourly_payment :public Profession
{
	double payment;
	unsigned int hours_worked;
	double final_pay;
public:
	const double get_payment()const;
	const unsigned int get_hours_worked()const;
	const double get_final_pay()const;
	void set_payment(const double payment);
	void set_hours_worked(const unsigned int hours_worked);
	void set_final_pay();

	Hourly_payment();
	Hourly_payment(const string& last_name, const string& first_name, const string& profession, const string& type_of_payment,
		const unsigned int experience, const double payment, const unsigned int hours_worked);
	~Hourly_payment();

	ostream& print(ostream& os)const;
	ofstream& print(ofstream& os)const;
	istream& input(istream& is);
	ifstream& input(ifstream& is);
};