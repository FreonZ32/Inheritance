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

Professional_area::Professional_area():Human()
{
	set_speciality("speciality");
	set_type_of_stydy("type_of_stydy");
}
Professional_area::Professional_area(const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& type_of_stydy) :Human(last_name, first_name, age)//Делигируем конструктор базового класса
{
	set_speciality(speciality);
	set_type_of_stydy(type_of_stydy);
#ifdef CONSTRUCT_DEBUG
	cout << "PaConstructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Professional_area::~Professional_area()
{
#ifdef CONSTRUCT_DEBUG
	cout << "PaDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
ostream& Professional_area::print(ostream& os)const
{
	Human::print(os);
	return os.width(30),os << left << speciality, os.width(10), os << left << type_of_stydy;
}
ofstream& Professional_area::print(ofstream& os)const
{
	Human::print(os);
	os.width(30), os << left << speciality << "|", os.width(10), os << left << type_of_stydy << "|";
	return os;
}
istream& Professional_area::input(istream& is)
{
	Human::input(is);
	is >> speciality >> type_of_stydy;
	return is;
}
void Professional_area::tofile()const
{
	Human::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout /* "Специальность: "*/ << speciality << /*", тип обучения: "*/" " << type_of_stydy << ";" << endl;
	fout.close();
}
