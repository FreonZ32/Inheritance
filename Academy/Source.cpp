#include"Stdafx.h"
#include"Human.h"
#include"Professional_area.h"
#include"Teacher.h"
#include"Student.h"
#include"Graduate.h"
#include<string.h>
#pragma warning(disable : 4996)

//#define INHERITANCE
//#define CREATE_AND_WRITE_IN_F
//#define SIMPLE_READING
#define DOWNLOAD_FROM_F_TO

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

#ifdef CREATE_AND_WRITE_IN_F
	clear_file();
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
		cout << endl;
		group[i]->print();
		group[i]->tofile();
		ofstream fout("File.txt", std::ios_base::app);
		fout << endl;
		fout.close();
	}
	system("start notepad File.txt");
	cout << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
#endif // CREATE_AND_WRITE_IN_F

#ifdef SIMPLE_READING
	string str;
	ifstream fin("File.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, str);
			cout << str << endl;
		}
	}
	else cerr << "File not found" << endl;
	fin.close();
#endif // SIMPLE_READING


#ifdef DOWNLOAD_FROM_F_TO

	const int SIZE = 256;
	char str[SIZE] = {};

	ifstream file;
	file.open("File.txt");
	if (file.is_open())
	{
		for (file.getline(str, SIZE); !file.eof(); file.getline(str, SIZE))
		{
			if (!strncmp(str, "ิศ", 2))
			{
				char last_name[SIZE] = {};
				char first_name[SIZE] = {};
				int age = 0;
				int n = 1;
				for (int i = 4, k = 0; str[i]; i++)
				{
					while (str[i] != ' ')
					{
						switch (n)
						{
						case 1:last_name[k] = str[i]; break;
						case 2:first_name[k] = str[i]; break;
						case 3:if (age != 0)age *= 10; age += (int(str[i]) - 48); break;
						default:;
						}
						k++; i++;
					}
					n++; k = 0;
				}
				Human G(last_name, first_name, age);
				G.print();
			}
		}
	}
	else cerr << "File not found" << endl;
	file.close();
#endif // DOWNLOAD_FROM_F_TO

}