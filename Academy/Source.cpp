#include"Stdafx.h"
#include"Human.h"
#include"Professional_area.h"
#include"Teacher.h"
#include"Student.h"
#include"Graduate.h"
#include<string.h>
#pragma warning(disable : 4996)

//#define INHERITANCE
//#define GROUP_MASSIVE



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


#ifdef GROUP_MASSIVE
	//clear_file();
	Human* group[] =
	{
		new Student("Pinkman", "Jessy", 22, "Methamphimamine manufacture", "stydent", "WW_01", 93),
		new Student("Vercetti", "Tomas", 30, "Cryminal", "stydent", "Vice", 90),
		new	Teacher("Hartwell", "Walter", 50, "Methamphimamine manufacture", "teacher", "Magistr", 24),
		new Teacher("Eistein", "Albert", 143, "Astronomy", "teacher", "God", 120),
		new Graduate("Schrader", "Hank", 43, "criminalistics", "student", "DEA", 60, "How to find Heisenberg", "WalterHartwell")
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
		//group[i]->tofile();
		/*ofstream fout("group.txt");
		for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
		{
			fout << *group[i] << endl;
		}
		fout.close();*/
	}
	//system("start notepad File.txt");
	//system("start notepad group.txt");
	cout << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
#endif // GROUP_MASSIVE

		Human A;
		cout << "¬ведите данные: "; cin >> A;
		cout << A << endl;
		Professional_area B;
		cout << "¬ведите данные: "; cin >> B;
		cout << B;

}


