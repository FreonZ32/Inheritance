#include"Stdafx.h"

void clear_file()
{
	ofstream fout;
	fout.open("File.txt", std::ofstream::out | std::ofstream::trunc);
	fout.close();
	fout.open("group.txt", std::ofstream::out | std::ofstream::trunc);
	fout.close();
}