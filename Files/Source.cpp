#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "rus");

#ifdef WRITE_TO_FILE
	cout << "Hello World" << endl;
	ofstream fout("File.txt", std::ios_base::app);	//Создаем и открывае поток
	fout << "Hello World";
	fout.close();
	system("start notepad File.txt");
#endif // WRITE_TO_FILE

	const int SIZE = 256;
	char buffer[SIZE] = {};
	ifstream fin("File.txt");
	if (fin.is_open())
	{
		while (!fin.eof())//while the end of file
		{
			fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer  << endl;
		}
	}
	else cerr << "File not found" << endl;
	fin.close();
}