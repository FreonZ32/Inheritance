#include"Stdafx.h"
#include"Human.h"
#include"Profession.h"
#include"Hourly_payment.h"

void main()
{
	setlocale(LC_ALL, "rus");
	Profession A("Чел", "Челович", "Программистер","Почасовая", 150);
	cout << A << endl;
	Hourly_payment B("Xhee", "Haaaaa", "Tester", "ssss", 140, 45, 34);
	cout << B << endl;
}