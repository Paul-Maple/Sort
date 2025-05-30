#include <iostream>
using namespace std;

//const int razmer = 10;
//int List[razmer] = {2, 10, 4, 8, 6, 5, 3, 7, 1, 9};

const int razmer = 20;
int List[razmer] = {34, 98, 12, 78, 5, 61, 27, 89, 41, 19, 55, 72, 3, 89, 68, 15, 5, 48, 27, 7};

int List_buffer[razmer];
int Iter = 0;

int Sort (int List[])
{
	cout << "Итерация " << Iter << ": ";
	Iter++;
	int q = 0;
	int buffer = List[0];

	for (int i = 0; i < razmer; i++)
	{
		//cout << List[i] << " ";
		if (List[i] < List[i-1])
		{
			List_buffer[q] = List[i];
			q++;
		}
	}

	for (int i = 0; i < razmer; i++)
	{
		if (List[i] >= List[i-1])
		{
			List_buffer[q] = List[i];
			q++;
		}
	}
//------------------------------------------Печать буфера
	//cout << "\n";
	for (int i = 0; i < razmer; i++)
	{
		cout << List_buffer[i] << " ";
	}
	cout << "\n";
//------------------------------------------Перезапись
	for (int i = 0; i < razmer; i++)
	{
		List[i] = List_buffer[i];
	}
//------------------------------------------Проверка
	for (int i = 0; i < razmer; i++)
	{
		if (List[i] < List[i-1]) Sort(List);
	}

}

int main()
{
	setlocale(LC_ALL, "");

	Sort(List);
//---------------Display--------------------------------------
	cout << "\n";
	for (int i = 0; i < razmer; i++)
	{
		cout << List[i] << " ";
	}
	cout << "\n";
//---------------Display--------------------------------------
}


