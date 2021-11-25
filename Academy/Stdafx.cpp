#include"Stdafx.h"

void clear_file()
{
	ofstream fout;
	fout.open("File.txt", std::ofstream::out | std::ofstream::trunc);
	fout.close();
	fout.open("group.txt", std::ofstream::out | std::ofstream::trunc);
	fout.close();
}

int HMstr(const string& name)
{
	int size = 0;
	ifstream fin(name);
	if (fin.is_open())
	{
		string str; 
		while (getline(fin, str)) size++;
	}
	else cerr << "File no found!" << endl;
	fin.close();
	return size;
}
string& DelSpace(string& str)
{
	int k = 0;
	for (int i = 0, j = 0; str[i]; ++i) { if (str[i] != ' ') str[j++] = str[i]; k = j; }	//delete all " "
	for (int i = k; str[i]; str[i] = NULL, i++);
	return str;
}