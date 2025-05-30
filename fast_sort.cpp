#include <iostream>
using namespace std;

//const int razmer = 10;
//int List[razmer] = {9,8,7,6,5,4,3,2,1,0,};

//const int razmer = 10;
//int List[razmer] = {4,5,6,7,8,9,10,3,2,1};

const int razmer = 20;
int List[razmer] = {80,58,7,44,41,32,3,65,81,28,93,52,69,73,20,56,42,99,46,62};


int ITER = 0;
int COMP = 0;
int SWAP = 0;

void Print(int List[])
{
	// cout << "\n";
	for (int i = 0; i < razmer; i++)
	{
	cout << List[i] << " ";
	}
	cout << "\n";
}

int poisk_opornogo_elementa(int List[], int left, int right)
{
	int op_element = List[(left + right) / 2];

	while(left <= right)
	{
	    COMP++;

		while(List[left] < op_element)
        {
        left++;
        COMP++;
        }

		while(List[right] > op_element)
        {
        right--;
        COMP++;
        }

		if(left <= right)
		{
			int temp = List[left];
			List[left] = List[right];
			List[right] = temp;
			left++;
			right--;
            SWAP++;
			COMP++;
		}
	}
	ITER++;
	//cout << ITER << "Итерация: ";
	//Print(List);
	return left;
}

void SortHoara(int List[], int start, int end)
{
	if(start >= end)
    {
    COMP++;
    return;
    }
	int rightStart = poisk_opornogo_elementa(List, start, end);
	//cout << "Итерация: " << ITER;
	//cout <<  " rs = " << rightStart << " \n";
	SortHoara (List, start, rightStart-1);

	SortHoara (List, rightStart, end);

}

void SortHoara(int List[])
{
	SortHoara(List,0,razmer-1);
}

int main()
{
	setlocale(LC_ALL, "rus");
	//---------------Display--------------------------------------
	cout << "\nИсходный массив:\n";
	Print(List);
	//cout << "\nИтерации:\n";
//---------------SortHoara------------------------------------
	SortHoara(List);
//---------------SortHoara------------------------------------
	cout << "\nОтсортированный массив:\n";
	Print(List);
//---------------Display--------------------------------------
	cout << "\nКоличество итераций: " << ITER + 1 << "\n";
    cout << "Количество сравнений: " << COMP << "\n";
    cout << "Количество перестановок: " << SWAP << "\n";
    system("read -p 'Press Enter to continue...' var");
    return 0;
}


