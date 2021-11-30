#pragma once
#include"Hourly_payment.h"

class Monthly_payment :public Hourly_payment
{
public:
	Monthly_payment(const string& last_name, const string& first_name, const string& profession, const unsigned int experience,
		const double payment, const unsigned int hours_worked = 160, const string& type_of_payment = "by_month");
	~Monthly_payment();

	ostream& print(ostream& os)const;
	ofstream& print(ofstream& os)const;
	istream& input(istream& is);
	ifstream& input(ifstream& is);
};