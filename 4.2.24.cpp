// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <string.h>

using namespace std;

string with;
string s1;

int check(string Sbuff);

int main()
{
	setlocale(0, "rus");
	char s[10];
	cout << "Enter a word: ";
	cin.getline(s, 10);
	s1 = s;
	for (int i = 0; i != 1;)
	{
		char buff[15];
		string comma = ", ";
		ifstream fin("dictionary.txt");
		while (1)
		{
			int sovpad;
			fin >> buff;
			string Sbuff = buff;
			for (int k = 0; Sbuff[k] != '\0'; k++)
			{
				if (s1[i] == Sbuff[k])
				{
					sovpad = check(Sbuff);
				}
			}
			if (!buff[0])
			{
				i = 1;
				break;
			}
			if ((sovpad == strlen(s)) && (sovpad == strlen(buff)))
			{
				with.append(Sbuff);
				with.append(comma);
			}
		}
	}
	cout << "Слова, полностью совпадающие с заданным словом по составу : \n" << with;
	system("\npause");
	return 0;
}

int check(string Sbuff)
{
	int sovpad = 0;
	for (int i = 0; s1[i] != '\0'; i++)
	{
		for (int k = 0; Sbuff[k] != '\0'; k++)
		{
			if (s1[i] == Sbuff[k])
			{
				sovpad++;
				Sbuff[k] = '1';
				break;
			}
		}
	}
	return sovpad;
}