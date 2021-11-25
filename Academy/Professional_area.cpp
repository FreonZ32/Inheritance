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
	return cout.width(35),os << /*"Специальность: "*/left << speciality, cout.width(10), os << /*", тип обучения: "*/left << type_of_stydy;
}
void Professional_area::tofile()const
{
	Human::tofile();
	ofstream fout("File.txt", std::ios_base::app);
	fout /* "Специальность: "*/ << speciality << /*", тип обучения: "*/" " << type_of_stydy << ";" << endl;
	fout.close();
}

istream& operator>>(istream& is, Professional_area& obj)
{
	const int S = 256;
	char buffer[S] = {};
	char buf[S] = {};
	is.getline(buffer, S);
	string str;
	for (int i = 0; buffer[i]; i++)
	{
		for (int k = 0; buffer[i]; k++, i++)
		{
			if (buffer[i] != ' ')buf[k] = buffer[i];
			else break;
		}
		str = buf;
		if (obj.get_last_name() == "last_name")obj.set_last_name(str);
		else if (obj.get_first_name() == "first_name")obj.set_first_name(str);
		else if (obj.get_age() == 0) { double k = atoi(buf); obj.set_age(k); }
		else if (obj.get_speciality() == "speciality")obj.set_speciality(str);
		else if (obj.get_type_of_stydy() == "type_of_stydy")obj.set_type_of_stydy(str);
		memset(buf, 0, sizeof(char) * i);
	}
	return is;
}