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
Human::Human()
{
	set_last_name("last_name");
	set_first_name("first_name");
	set_age(0);
}
Human::Human(const string& last_name, const string& first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
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
	cout.width(13);
	return os << left << last_name, os << left << first_name << "\t" << age << "\t";
	//return os /*<< endl << "װָ: "*/ << left << last_name, os << left << first_name, cout.width(5), os << left << age /*" כוע.\n" <<*/;
}
void Human::tofile()const
{
	ofstream fout("File.txt", std::ios_base::app);
	fout << last_name << " " << first_name << "\t" << age << ";" << endl;
	fout.close();
}
 
ostream& operator<<(ostream& os, const Human& obj)
{
	obj.print(os);
	return os;
}
istream& operator>>(istream& is, Human& obj)
{
	const int S = 256;
	char buffer[S] = {};
	char buf[S] = {};
	is.getline(buffer, S);
	string str;
	for (int i = 0; buffer[i]; i++)
	{
		for (int k = 0; buffer[i];k++, i++)
		{
			if (buffer[i] != ' ')buf[k] = buffer[i];
			else break;
		}
		str = buf;
		if(obj.get_last_name()=="last_name")obj.set_last_name(str);
		else if(obj.get_first_name()=="first_name")obj.set_first_name(str);
		else if (obj.get_age() == 0) { double k = atoi(buf); obj.set_age(k);}
		memset(buf, 0, sizeof(char) * i);
	}
	return is;
}