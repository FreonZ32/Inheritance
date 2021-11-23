#include"Teacher.h"

const string& Teacher::get_academic_degree()const
{
	return academic_degree;
}
void Teacher::set_academic_degree(const string& academic_degree)
{
	this->academic_degree = academic_degree;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}

Teacher::Teacher(const string& last_name, const string& first_name, unsigned int age, const string& speciality,
	const string& type_of_stydy, const string& academic_degree, const unsigned int experience)
	:Professional_area(last_name, first_name, age, speciality, type_of_stydy)//Делигируем конструктор класса проф_сфера
{
	set_academic_degree(academic_degree);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}
ostream& Teacher::print(ostream& os)const
{
	Professional_area::print(os);
	return os << /*"Ученая степень: "*/" " << academic_degree << /*", стаж: "*/" " << experience << endl;
}
void Teacher::tofile()const
{
	Professional_area::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout << /*"Ученая степень: "*/" " << academic_degree << /*", стаж: "*/" " << experience << ";" << endl;
	fout.close();
}