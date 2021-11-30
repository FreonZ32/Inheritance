#include"Human.h"

const string& Human::get_last_name()const
{
	return last_name;
}
const string& Human::get_first_name()const
{
	return first_name;
}
void Human::set_last_name(const string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const string& first_name)
{
	this->first_name = first_name;
}
Human::Human()
{
	set_last_name("last_name");
	set_first_name("first_name");
}
Human::Human(const string& last_name, const string& first_name)
{
	set_last_name(last_name);
	set_first_name(first_name);
#ifdef CONSTRUCT_DEBUG
	cout << "HConstrucror:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Human::~Human()
{
#ifdef CONSTRUCT_DEBUG
	cout << "HDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
ostream& Human::print(ostream& os)const
{
	return os.width(10), os << left << last_name, os << "|", os.width(10), os << left << first_name;
}
ofstream& Human::print(ofstream& os)const
{
	os << typeid(*this).name() << ",";
	os << "," << last_name << "," << first_name;
	return os;
}

istream& Human::input(istream& is)
{
	return is >> last_name >> first_name;
}
ifstream& Human::input(ifstream& is)
{
	getline(is, last_name, ',');
	getline(is, first_name, ',');
	return is;
}

ostream& operator<<(ostream& os, const Human& obj)
{
	obj.print(os);
	return os;
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	obj.print(os);
	return os;
}
ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.input(is);
}
istream& operator>>(istream& is, Human& obj)
{
	return obj.input(is);
}