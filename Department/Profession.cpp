#include"Profession.h"

const string& Profession::get_profession()const
{
	return profession;
}
const string& Profession::get_type_of_payment()const
{
	return type_of_payment;
}
const unsigned int Profession::get_experience()const
{
	return experience;
}
void Profession::set_profession(const string& profession)
{
	this->profession = profession;
}
void Profession::set_type_of_payment(const string& type_of_payment)
{
	this->type_of_payment = type_of_payment;
}
void Profession::set_experience(const unsigned int experience)
{
	this->experience = experience;
}

Profession::Profession()
{
	set_profession("profession");
	set_type_of_payment("type_of_payment");
	set_experience(0);
}
Profession::Profession(const string& last_name, const string& first_name, const string& profession, const string& type_of_payment, const unsigned int experience)
	:Human(last_name,first_name)
{
	set_profession(profession);
	set_type_of_payment(type_of_payment);
	set_experience(experience);
#ifdef CONSTRUCT_DEBUG
	cout << "PConstrucror:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Profession::~Profession()
{
#ifdef CONSTRUCT_DEBUG
	cout << "PDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}

ostream& Profession::print(ostream& os)const
{
	Human::print(os);
	return os <<"|", os.width(15), os << left << profession, os << "|", os.width(10), os << left << type_of_payment, os << "|", os.width(5), os << left << experience;
}
ofstream& Profession::print(ofstream& os)const
{
	Human::print(os);
	os << "," << profession << "," << type_of_payment << "," << experience;
	return os;
}

istream& Profession::input(istream& is)
{
	Human::input(is);
	return is >> profession >> type_of_payment >> experience;
}
ifstream& Profession::input(ifstream& is)
{
	Human::input(is);
	getline(is, profession, ',');
	getline(is, type_of_payment, ',');
	string experience_buffer;
	getline(is, experience_buffer, ',');
	this->experience = stoi(experience_buffer);
	return is;
}