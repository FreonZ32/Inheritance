#pragma once
#include"Student.h"

class Graduate :public Student
{
	string thesis;
	string curator;
public:
	const string& get_thesis()const;
	void set_thesis(const string& thesis);
	const string& get_curator()const;
	void set_curator(const string& curator);

	Graduate(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& type_of_stydy,
		const string& group, double rating, const string& thesis, const string& curator);
	~Graduate();
	void print()const;
};