#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;

bool finish = false;

void thr1(int &a)
{
	while (!finish)
	{
		a++;
		cout << a << endl;
		Sleep(400);
	}
}
void thr2()
{
	while (!finish)
	{
		cout << "World" << endl;
		Sleep(400);
	}
}

void main()
{
	int a = 0;
	std::thread hello_thread(thr1,ref(a));
	std::thread world_thread(thr2);

	cin.get();
	finish = true;

	world_thread.join();
	hello_thread.join();
}