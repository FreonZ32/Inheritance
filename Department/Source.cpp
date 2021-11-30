#include"Stdafx.h"
#include"Human.h"
#include"Profession.h"
#include"Hourly_payment.h"
#include"Monthly_payment.h"

void main()
{
	setlocale(LC_ALL, "rus");
	/*Profession A("Чел", "Челович", "Программистер", 150);
	cout << A << endl;
	Hourly_payment B("Xhee", "Haaaaa", "Tester", 140, 45, 34);
	cout << B << endl;
	Monthly_payment C ("Hheheh", "sadasda", "Greender", 90, 4500);
	cout << C << endl;*/

	Human* group[] =
	{
		new Hourly_payment ("Fyndsf", "sdfsd", "Tester2", 95, 14, 20),
		new Hourly_payment ("Xhee", "Haaaaa", "Tester", 140, 45, 34),
		new	Monthly_payment ("Hsad", "sada", "Greender2", 90, 7500),
		new Monthly_payment ("Hheheh", "sadasda", "Greender", 90, 4500),
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)cout << *group[i] << endl;
}