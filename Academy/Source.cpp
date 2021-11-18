#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{return last_name;}
	const string& get_first_name()const
	{return first_name;}
	unsigned int get_age()const
	{return age;}
	void set_last_name(const string& last_name)
	{this->last_name = last_name;}
	void set_first_name(const string& first_name)
	{this->first_name = first_name;}
	void set_age(unsigned int age)
	{this->age = age;}

	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstrucror:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	virtual void print()const
	{
		cout << endl << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

class Professional_area :public Human
{
	string speciality;
	string type_of_stydy;	//teacher/student/
public:
	const string& get_speciality()const
	{return speciality;}
	void set_speciality(const string& speciality)
	{this->speciality = speciality;}
	const string& get_type_of_stydy()const
	{return type_of_stydy;}
	void set_type_of_stydy(const string& type_of_stydy)
	{this->type_of_stydy = type_of_stydy;}

	Professional_area(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& type_of_stydy) :Human(last_name, first_name, age)//Делигируем конструктор базового класса
	{
		set_speciality(speciality);
		set_type_of_stydy(type_of_stydy);
		cout << "PaConstructor:\t" << this << endl;
	}
	~Professional_area()
	{
		cout << "PaDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", тип обучения: " << type_of_stydy << endl;
	}
};

class Teacher :public Professional_area
{
	string academic_degree;
	unsigned int experience;

public:
	const string& get_academic_degree()const
	{return academic_degree;}
	void set_academic_degree(const string& academic_degree)
	{this->academic_degree = academic_degree;}
	unsigned int get_experience()const
	{return experience;}
	void set_experience(unsigned int experience)
	{this->experience = experience;}

	Teacher(const string& last_name, const string& first_name, unsigned int age, const string& speciality,
		const string& type_of_stydy,const string& academic_degree, const unsigned int experience)
		:Professional_area(last_name, first_name, age, speciality, type_of_stydy)//Делигируем конструктор класса проф_сфера
	{
		set_academic_degree(academic_degree);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void print()const
	{
		Professional_area::print();
		cout << "Ученая степень: " << academic_degree << ", стаж: " << experience << endl;
	}
};

class Student :public Professional_area
{
	string group;
	double rating;
public:
	const string& get_group()const
	{return group;}
	double get_rating()const
	{return rating;}
	void set_group(const string& group)
	{this->group = group;}
	void set_rating(double rating)
	{this->rating = rating;}

	Student(const string& last_name, const string& first_name, unsigned int age,
			const string& speciality, const string& type_of_stydy,
			const string& group, double rating)
		:Professional_area(last_name, first_name, age, speciality, type_of_stydy)//Делигируем конструктор класса проф_сфера
	{
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void print()const
	{
		Professional_area::print();
		cout << "Группа: " << group << ", успеваемость : " << rating << endl;
	}
};

class Graduate :public Student
{
	string thesis;
	string curator;
public:
	const string& get_thesis()const
	{return thesis;}
	void set_thesis(const string& thesis)
	{this->thesis = thesis;}
	const string& get_curator()const
	{return curator;}
	void set_curator(const string& curator)
	{this->curator = curator;}

	Graduate(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& type_of_stydy,
		const string& group, double rating, const string& thesis, const string& curator) 
		:Student(last_name, first_name, age, speciality, type_of_stydy, group, rating)//Делигируем конструктор класса Студент
	{
		set_thesis(thesis);
		set_curator(curator);
		cout << "SConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << "Тема диплома: " << thesis << ", куратор: " << curator << endl;
	}
};

//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "rus");

#ifdef INHERITANCE
	Human h("Montana", "Antonio", 35);
	h.print();

	Teacher d("Hartwell", "Walter", 50, "Methamphimamine manufacture", "teacher", "Magistr", 24);
	d.print();

	Student s("Pinkman", "Jessy", 22, "Methamphimamine manufacture", "stydent", "WW_01", 93);
	s.print();

	Graduate f("Schrader", "Hank", 43, "criminalistics", "student", "DEA", 60, "How to find Heisenberg", "WalterHartwell");
	f.print();
#endif // INHERITANCE

	Human* group[] =
	{
		new Student("Pinkman", "Jessy", 22, "Methamphimamine manufacture", "stydent", "WW_01", 93),
		new Student("Vercetti", "Tomas", 30, "Cryminal", "stydent", "Vice", 90),
		new	Teacher("Hartwell", "Walter", 50, "Methamphimamine manufacture", "teacher", "Magistr", 24),
		new Teacher("Eistein", "Albert", 143, "Astronomy", "teacher", "God", 120),
		new Graduate("Schrader", "Hank", 43, "criminalistics", "student", "DEA", 60, "How to find Heisenberg", "WalterHartwell")
	};
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		cout << endl;
		group[i]->print();
	}
	cout << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
}