#include <ctime>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//const int razmer = 6;
//int List[razmer] = {2,6,4,3,1,5};

//const int razmer = 10;
//int List[razmer] = {6,2,7,3,8,4,1,5,9,10};

const int razmer = 20;
int List[razmer] = {34, 27, 12, 78, 5, 61, 27, 89, 41, 19, 55, 72, 3, 89, 68, 15, 5, 48, 98, 7};

int ITER = 0;

void Print(int List[], int razmer)
{
	for (int i = 0; i < razmer; i++)
	{
		cout << List[i] << " ";
	}
	cout << "\n";
}

void Stalin_sort(int List[])
{
    ITER++;
	int buffer = 0;
	int val = List[0];
	for(int i = 0; i < razmer; i++)
	{
		if (List[i] >= val)
		{
			buffer++;
            val = List[i];
		}
	}
	
	int *arr = new int[buffer];
	int k = 0;
	val = List[0];
	
	for(int i = 0; i < razmer; i++)
	{
		if (List[i] >= val)
		{
			arr[k] = List[i];
			val = List[i];
			k++;   
		}
	}
	Print(arr,buffer);
}

int main()
{
	setlocale(LC_ALL, "");
	//---------------Display--------------------------------------
	cout << "\nИсходный массив:\n";
	Print(List,razmer);
//---------------Sort------------------------------------
	cout << "\nОтсортированный массив:\n";
	Stalin_sort(List);
//---------------Sort------------------------------------
	cout << "\nКоличество итераций: " << ITER << "\n";
//---------------Display--------------------------------------
}
