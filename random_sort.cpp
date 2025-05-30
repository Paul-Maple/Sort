#include <ctime>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int razmer = 6;
int List[razmer] = {2,6,4,3,1,5};

//const int razmer = 10;
//int List[razmer] = {4,5,6,7,8,9,10,3,2,1};

//const int razmer = 20;
//int List[razmer] = {34, 98, 12, 78, 5, 61, 27, 89, 41, 19, 55, 72, 3, 89, 68, 15, 5, 48, 27, 7};

int ITER = 0;

void Print(int List[])
{
	// cout << "\n";
	for (int i = 0; i < razmer; i++)
	{
		cout << List[i] << " ";
	}
	cout << "\n";
}

void swap(int List[])
{
	int i = rand() % (razmer);
	int j = rand() % (razmer);

	int a = List[i];
	List[i] = List[j];
	List[j] = a;

	ITER++;
	cout << ITER << ": ";
	Print(List);
	//cout << i << " " << j << "\n";
}

void Random_sort(int List[])
{
	int buffer = 0;
	for(int i = 1; i < razmer; i++)
	{
		if (List[i] < List[i-1])
		{
			swap(List);
			Random_sort(List);
		}
	}

}

int main()
{
	setlocale(LC_ALL, "");
	//---------------Display--------------------------------------
	cout << "\nИсходный массив:\n";
	Print(List);
	cout << "\nИтерации:\n";
//---------------SortHoara------------------------------------
srand(time(0));
Random_sort(List);
//---------------SortHoara------------------------------------
	cout << "\nОтсортированный массив:\n";
	Print(List);
//---------------Display--------------------------------------
	cout << "\nКоличество итераций: " << ITER << "\n";
}
