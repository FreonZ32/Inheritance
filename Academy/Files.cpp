#include"Files.h"

void Save_to_file(const Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)fout << *group[i] << endl;
	fout.close();
}
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
		for (int i = 0; i<n ; i++)
		{
			getline(fin, buffer);
			cout << buffer << endl;
		}
		fin.close();
	}
	else cerr << "Error: File not found!" << endl;
	return nullptr;
}