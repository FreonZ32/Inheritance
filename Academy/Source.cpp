#include"Stdafx.h"
#include"Human.h"
#include"Professional_area.h"
#include"Teacher.h"
#include"Student.h"
#include"Graduate.h"
#include<string.h>
#include<vector>
#include"Files.h"
#pragma warning(disable : 4996)

//#define INHERITANCE
//#define GROUP_MASSIVE
//#define CIN_CHECK
//#define READ_FROM_FILE

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
	clear_file();
	Human* group[] =
	{
		new Student("Pinkman", "Jessy", 22, "Methamphimamine manufacture", "stydent", "WW_01", 93),
		new Student("Vercetti", "Tomas", 30, "Cryminal", "stydent", "Vice", 90),
		new	Teacher("Hartwell", "Walter", 50, "Methamphimamine manufacture", "teacher", "Magistr", 24),
		new Teacher("Eistein", "Albert", 143, "Astronomy", "teacher", "God", 120),
		new Graduate("Schrader", "Hank", 43, "criminalistics", "student", "DEA", 60, "How to find Heisenberg", "Walter Hartwell")
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)cout << *group[i] << endl;
	ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)fout << *group[i] << endl;
	fout.close();
	//READ FROM FILE
	ifstream fin("group.txt");
	//system("start notepad group.txt");
	if (fin.is_open())
	{
		int size = HMstr("group.txt");
		string str;
		const int* size1 = (int*)(&size);
		vector<Human*>groupfile = {};
		string last_name, first_name, speciality, type_of_stydy, group,curator,thesis, academic_degree;
		unsigned int age = 0, experience = 0; double rating = 0;
		for (int i = 0; i < size; i++)
		{
			getline(fin, str,'\n');		//Get string
			//cout << " Получили строку: " << str << endl;	
			str = DelSpace(str);
			//cout << " Строка без пробелов: " << str << endl;
			if (!memcmp(str.c_str(), "classStudent", 12) || !memcmp(str.c_str(), "classGraduate", 13))
			{
				istringstream ist(str); string token;
				int num = 0;
				while (getline(ist, token, '|'))
				{
					switch (num)
					{
					case 1: last_name = token; break;
					case 2: first_name = token; break;
					case 3: age = atoi(token.c_str()); break;
					case 4: speciality = token; break;
					case 5: type_of_stydy = token; break;
					case 6: group = token; break;
					case 7: rating = (double)atoi(token.c_str()); break;
					case 8: curator = token; break;
					case 9: thesis = token; break;
					default:break;
					}
					num++;
					//cout << num++ << token << endl;
				}
				if (!memcmp(str.c_str(), "classStudent", 12))
				{
					groupfile.push_back(new Student(last_name, first_name, age, speciality, type_of_stydy, group, rating));
				}
				else groupfile.push_back(new Graduate(last_name, first_name, age, speciality, type_of_stydy, group, rating, thesis, curator));
			}
			if (!memcmp(str.c_str(), "classTeacher", 12) || !memcmp(str.c_str(), "classHuman", 10))
			{
				istringstream ist(str); string token;
				int num = 0;
				while (getline(ist, token, '|'))
				{
					switch (num)
					{
					case 1: last_name = token; break;
					case 2: first_name = token; break;
					case 3: age = atoi(token.c_str()); break;
					case 4: speciality = token; break;
					case 5: type_of_stydy = token; break;
					case 6: academic_degree = token; break;
					case 7: experience = atoi(token.c_str()); break;
					default:break;
					}
					num++;
					//cout << num << "-" << token << endl;
				}
				if (!memcmp(str.c_str(), "classTeacher", 12))
				{
					groupfile.push_back(new Teacher(last_name,first_name,age,speciality,type_of_stydy,academic_degree,experience));
				}
				else groupfile.push_back(new Human(last_name, first_name, age));
			}
			//system("pause");
		}
		for(int i = 0; i < size; i++)cout << *groupfile[i] << endl;
		groupfile.clear();
		//for (int i = 0; i < size; i++)[] *groupfile[i];
	}
	else cerr << "File no found!" << endl;
	fin.close();
	//system("start notepad File.txt");
	//system("start notepad group.txt");
	cout << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)delete[] group[i];
#endif // GROUP_MASSIVE

#ifdef CIN_CHECK
	/*Human A;
	cout << "Введите данные: "; cin >> A;
	cout << A << endl;*/
	Student D;
	cout << "Введите данные: "; cin >> D;
	cout << D << endl;
	/*Professional_area B;
	cout << "Введите данные: "; cin >> B;
	cout << B;*/
#endif // CIN_CHECK

#ifdef READ_FROM_FILE
	clear_file();
	const Human* group[] =
	{
		new Student("Pinkman", "Jessy", 22, "Methamphimamine manufacture", "stydent", "WW_01", 93),
		new Student("Vercetti", "Tomas", 30, "Cryminal", "stydent", "Vice", 90),
		new	Teacher("Hartwell", "Walter", 50, "Methamphimamine manufacture", "teacher", "Magistr", 24),
		new Teacher("Eistein", "Albert", 143, "Astronomy", "teacher", "God", 120),
		new Graduate("Schrader", "Hank", 43, "criminalistics", "student", "DEA", 60, "How to find Heisenberg", "Walter Hartwell")
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)cout << *group[i] << endl;
	string filename = "group.txt";
	Save_to_file(group, sizeof(group) / sizeof(group[0]), filename);
	
	/*ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)fout << *group[i] << endl;
	fout.close();*/

	//system("start notepad group.txt");
	system((string("start notepad ") + filename).c_str());
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)delete[] group[i];
#endif // READ_FROM_FILE

	Load_from_file("group.txt");
	//Print(group, 5);
}


