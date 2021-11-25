#pragma once
#include"Human.h"

class Professional_area :public Human
{
	string speciality;
	string type_of_stydy;	//teacher/student/
public:
	const string& get_speciality()const;
	void set_speciality(const string& speciality);
	const string& get_type_of_stydy()const;
	void set_type_of_stydy(const string& type_of_stydy);

	Professional_area();
	Professional_area(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& type_of_stydy);
	~Professional_area();
	ostream& print(ostream& os)const;
	void tofile()const;
};

istream& operator>>(istream& is, Professional_area& obj);