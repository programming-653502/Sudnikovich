// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void bubbleSort(int *, int);

int main()
{
	srand(time(NULL));
	cout << "Enter the size of first array: ";
	int size1;
	cin >> size1;
	int *sorted1 = new int[size1];
	for (int counter = 0; counter < size1; counter++)
	{
		sorted1[counter] = rand() % 100; 
	}
	bubbleSort(sorted1, size1);
	for (int counter = 0; counter < size1; counter++)
	{
		cout << setw(2) << sorted1[counter] << "  ";
	}
	cout << "\n\n";
	cout << "Enter the size of second array: ";
	int size2;
	cin >> size2;
	int *sorted2 = new int[size2]; 
	for (int counter = 0; counter < size2; counter++)
	{
		sorted2[counter] = rand() % 100;
	}
	bubbleSort(sorted2, size2);
	for (int counter = 0; counter < size2; counter++)
	{
		cout << setw(2) << sorted2[counter] << "  ";
	}
	cout << "\n\n";
	int size = size1 + size2;
	int *sorted3 = new int[size];
	int *sorted = new int[size];
	for (int i = 0; i < size1; i++)
	{
		sorted3[i] = sorted1[i];
	}
	int i, j;
	int position = size1;
	for (i = 0; i < size2; i++)
	{
		sorted3[position] = sorted2[i];
		position++;
	}
	cout << "\n\nUnsorted array:\n\n";
	for (int counter = 0; counter < size; counter++)
	{
		cout << setw(2) << sorted3[counter] << "  ";
	}
	bubbleSort(sorted3, size);
	int p;
	for (int i = 0; i < size; i++)
	{
		sorted[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (p = 0; p < size; p++)
		{
			if (sorted3[i] == sorted[p])
			{
				break;
			}
		}
		if (p == size)
		{
			sorted[i] = sorted3[i];
		}
	}
	cout << "\n\nSorted array:\n\n";
	for (int counter = 0; counter < size; counter++)
	{
		cout << setw(2) << sorted[counter] << "  ";
	}
	cout << "\n\n";
	for (i = 0; i < size; i++)
	{
		if (sorted[i] == 0)
		{
			for (j = i + 1; j < size; j++)
			{
				sorted[j - 1] = sorted[j];
			}
			size--;
			i--;
		}
	}
	cout << "Final array:\n\n";
	for (int counter = 0; counter < size; counter++)
	{
		cout << setw(2) << sorted[counter] << "  ";
	}
	cout << "\n\n";
	system("pause");
	return 0;
}

void bubbleSort(int* arrayPtr, int length_array) 
{
	int temp = 0; 
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
		{
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
			{
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false;
			}
		}
	}
}