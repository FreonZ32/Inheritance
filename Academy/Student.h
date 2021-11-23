#pragma once
#include"Professional_area.h"

class Student :public Professional_area
{
	string group;
	double rating;
public:
	const string& get_group()const;
	double get_rating()const;
	void set_group(const string& group);
	void set_rating(double rating);

	Student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& type_of_stydy,
		const string& group, double rating);
	~Student();

	void print(ostream& os)const;
	void tofile()const;
};