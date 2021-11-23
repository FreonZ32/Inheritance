#include"Human.h"

const string& Human::get_last_name()const
{
	return last_name;
}
const string& Human::get_first_name()const
{
	return first_name;
}
unsigned int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(unsigned int age)
{
	this->age = age;
}

Human::Human(const string& last_name, const string& first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstrucror:\t" << this << endl;
}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}
void Human::print()const
{
	cout << endl << last_name << " " << first_name << " " << age << " ���.\n";
}
void Human::tofile()const
{
	ofstream fout("File.txt", std::ios_base::app);
	fout << endl << last_name << " " << first_name << " " << age << " ���.\n";
	fout.close();
}