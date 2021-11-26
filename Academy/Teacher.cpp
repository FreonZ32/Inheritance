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

Teacher::Teacher():Professional_area()
{
	set_academic_degree("academic_degree");
	set_experience(0);
}
Teacher::Teacher(const string& last_name, const string& first_name, unsigned int age, const string& speciality,
	const string& type_of_stydy, const string& academic_degree, const unsigned int experience)
	:Professional_area(last_name, first_name, age, speciality, type_of_stydy)//Делигируем конструктор класса проф_сфера
{
	set_academic_degree(academic_degree);
	set_experience(experience);
#ifdef CONSTRUCT_DEBUG
	cout << "TConstructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Teacher::~Teacher()
{
#ifdef CONSTRUCT_DEBUG
	cout << "TDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
ostream& Teacher::print(ostream& os)const
{
	Professional_area::print(os);
	return os.width(10), os << left << academic_degree, os.width(5), os << internal << experience << "y", os.width(3), os << " ";
}
ofstream& Teacher::print(ofstream& os)const
{
	Professional_area::print(os);
	os.width(10), os << left << academic_degree << "|", os.width(5), os << internal << experience << "|", os.width(3), os << " ";
	return os;
}
istream& Teacher::input(istream& is)
{
	Teacher::input(is);
	is >> academic_degree >> experience;
	return is;
}
ifstream& Teacher::input(ifstream& is)
{
	Professional_area::input(is);
	getline(is, academic_degree, '|');
	string experience_buffer;
	getline(is, experience_buffer, '|');
	this->experience = stoi(experience_buffer);
	return is;
}
void Teacher::tofile()const
{
	Professional_area::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout << /*"Ученая степень: "*/" " << academic_degree << /*", стаж: "*/" " << experience << ";" << endl;
	fout.close();
}