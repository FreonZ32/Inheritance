#include"Files.h"

void Save_to_file(const Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)fout << *group[i] << endl;
	fout.close();
}
//void Print(const Human* group[], const int size)
//{
//	for (int i = 0; i < size; i++)cout << *group[i] << endl;
//}
Human** Load_from_file(const string& filename)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		int n = 0;
		string buffer;
		while (!fin.eof())
		{
			getline(fin, buffer); n++;
		}
		fin.clear();
		Human** group = new Human * [n] {};
		fin.seekg(ios::beg,0);
		
		for (int i = 0; i < n; i++)
		{
			string human_type;
			getline(fin, human_type,'|');
			//human_type = DelSpace(human_type);
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
		}
		fin.close();
		return group;
	}
	else cerr << "Error: File not found!" << endl;
	return nullptr;
}
Human* HumanFactory(const string& human_type)
{
	if (human_type.find("class Sudent")!= string::npos)return new Student();
	if (human_type.find("class Graduate") != string::npos)return new Graduate();
	if (human_type.find("class Teacher") != string::npos)return new Teacher();
	if (human_type.find("class Human") != string::npos)return new Human();
	return nullptr;
}