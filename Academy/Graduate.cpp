#include"Graduate.h"

const string& Graduate::get_thesis()const
{
	return thesis;
}
void Graduate::set_thesis(const string& thesis)
{
	this->thesis = thesis;
}
const string& Graduate::get_curator()const
{
	return curator;
}
void Graduate::set_curator(const string& curator)
{
	this->curator = curator;
}

Graduate::Graduate() :Student()
{
	set_thesis("thesis");
	set_curator("curator");
}
Graduate::Graduate(const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& type_of_stydy,
	const string& group, double rating, const string& thesis, const string& curator)
	:Student(last_name, first_name, age, speciality, type_of_stydy, group, rating)//���������� ����������� ������ �������
{
	set_thesis(thesis);
	set_curator(curator);
#ifdef CONSTRUCT_DEBUG
	cout << "SConstructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Graduate::~Graduate()
{
#ifdef CONSTRUCT_DEBUG
	cout << "SDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
ostream& Graduate::print(ostream& os)const
{
	Student::print(os);
	return cout.width(30), os << left << thesis, cout.width(10), os << left << curator;
}
void Graduate::tofile()const
{
	Student::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout << /*"���� �������: "*/" " << thesis << /*", �������: "*/" " << curator << ";" << endl;
	fout.close();
}