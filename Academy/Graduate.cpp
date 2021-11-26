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
	:Student(last_name, first_name, age, speciality, type_of_stydy, group, rating)//Делигируем конструктор класса Студент
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
	return  os.width(20), os << left << curator, os << left << thesis;
}
ofstream& Graduate::print(ofstream& os)const
{
	Student::print(os);
	os.width(20), os << left << curator << "|", os << left << thesis << "|";
	return os;
}
istream& Graduate::input(istream& is)
{
	Graduate::input(is);
	is >> curator >> thesis;
	return is;
}
ifstream& Graduate::input(ifstream& is)
{
	Student::input(is);
	getline(is, curator, '|');
	getline(is, thesis, '|');
	return is;
}
void Graduate::tofile()const
{
	Student::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout << /*"Тема диплома: "*/" " << thesis << /*", куратор: "*/" " << curator << ";" << endl;
	fout.close();
}