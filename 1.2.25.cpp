// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "stdio.h"
#include "iostream"
#include <locale>

void check(int a);

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int m;
	input:
	cout << "Enter m: ";
	cin >> m;
	if (m <= 0) goto input;
	else;
	for (int ch = 1; ch <= m; ch++)
	{
		cout << "Number " << ch << endl << "in decimal: " << ch << endl;
		check(ch);
	}
	cin >> m;
	return 0;
}

void check(int ch)
{
	int i, reverse[20], straight[20], l, s_index = 0;

	for (i = 0; i < 10; i++)
	{
		reverse[i] = 0;
	}
	for (i = 0; i < 10; i++)
	{
		straight[i] = 0;
	}
	i = 0;
	while (ch != 0)
	{
		if (ch % 2 == 0)
		{
			reverse[i] = 0;
			ch = ch / 2;
		}
		else
		{
			reverse[i] = 1;
			ch = ch / 2;
		}
		i++;
	}
	i = i - 1;
	l = i;
	for (; i >= 0; i--)
	{
		straight[s_index] = reverse[i];
		s_index++;
	}
	cout << "In binary form: ";
	for (int i = 0; i <= l; i++)
	{
		cout << straight[i];
	}
	cout << endl;
	int sim = 1;
	for (i = 0; i < l + 1 / 2; i++)
	{
		if (straight[i] == straight[l - i]);
		else
		{
			cout << "The binary representation of this number is not symmetrical.";
			sim = 0;
			cout << endl << endl;
			break;
		}
	}
	if (sim == 1)
	{
		cout << "he binary representation of this number symmetrically.";
		cout << endl << endl;
	}
}
