// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <string.h>

using namespace std;

string with;

int main()
{
	char s[10];
	cout << "Enter a word: ";
	cin.getline(s, 10);
	cout << s << endl;
	string s1 = s;
	for (int i = 0; s1[i] != '\0'; i++)
	{
		char buff[15];
		string comma = ", ";
		ifstream fin("dictionary.txt");
		while (1)
		{
			fin >> buff;
			string Sbuff = buff;
			for (int j = 0; Sbuff[j] != '\0'; j++)
			{
				if (s1[i] == Sbuff[j])
				{
					with.append(Sbuff);
					with.append(comma);
				}
			}
			if (!buff[0])
			{
				break;
			}
		}
		cout << "Words with letter " << s1[i] << " : " << with << "\n\n";
		with.clear();
	}
	system("pause");
	return 0;
}