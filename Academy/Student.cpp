#include"Student.h"

const string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}

Student::Student():Professional_area()
{
	set_group("group");
	set_rating(0);
}
Student::Student(const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& type_of_stydy,
	const string& group, double rating)
	:Professional_area(last_name, first_name, age, speciality, type_of_stydy)//Делигируем конструктор класса проф_сфера
{
	set_group(group);
	set_rating(rating);
#ifdef CONSTRUCT_DEBUG
	cout << "SConstructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Student::~Student()
{
#ifdef CONSTRUCT_DEBUG
	cout << "SDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}

ostream& Student::print(ostream& os)const
{
	Professional_area::print(os);
	return os.width(10), os << left << group, os.width(5), os << internal << rating <<"%",os.width(3),os << " ";
}
ofstream& Student::print(ofstream& os)const
{
	Professional_area::print(os);
	os.width(10), os << left << group << "|", os.width(5), os << internal << rating << "%" << "|", os.width(3), os << " ";
	return os;
}
istream& Student::input(istream& is)
{
	Professional_area::input(is);
	is >> group >> rating;
	return is;
}
void Student::tofile()const
{
	Professional_area::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout /*"Группа: "*/ << group << /*", успеваемость: "*/" " << rating << ";" << endl;
	fout.close();
}