#include"Professional_area.h"

const string& Professional_area::get_speciality()const
{
	return speciality;
}
void Professional_area::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
const string& Professional_area::get_type_of_stydy()const
{
	return type_of_stydy;
}
void Professional_area::set_type_of_stydy(const string& type_of_stydy)
{
	this->type_of_stydy = type_of_stydy;
}

Professional_area::Professional_area(const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& type_of_stydy) :Human(last_name, first_name, age)//Делигируем конструктор базового класса
{
	set_speciality(speciality);
	set_type_of_stydy(type_of_stydy);
	cout << "PaConstructor:\t" << this << endl;
}
Professional_area::~Professional_area()
{
	cout << "PaDestructor:\t" << this << endl;
}
ostream& Professional_area::print(ostream& os)const
{
	Human::print(os);
	return os << "Специальность: " << speciality << ", тип обучения: " << type_of_stydy << endl;
}
void Professional_area::tofile()const
{
	Human::tofile();
	ofstream fout("File.txt", std::ios_base::app);	//Создаем и открывае поток
	fout << "Специальность: " << speciality << ", тип обучения: " << type_of_stydy << ";" << endl;
	fout.close();
}