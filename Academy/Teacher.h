#pragma once
#include"Professional_area.h"

class Teacher :public Professional_area
{
	string academic_degree;
	unsigned int experience;

public:
	const string& get_academic_degree()const;
	void set_academic_degree(const string& academic_degree);
	unsigned int get_experience()const;
	void set_experience(unsigned int experience);

	Teacher();
	Teacher(const string& last_name, const string& first_name, unsigned int age, const string& speciality,
		const string& type_of_stydy, const string& academic_degree, const unsigned int experience);
	~Teacher();
	ostream& print(ostream& os)const;
	void tofile()const;
};