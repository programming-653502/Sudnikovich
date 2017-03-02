// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "locale"
#include "string.h"

using namespace std;

string doubleSpace(string s, int needSpace);
int lenStr(string s);
int spaceCount(string s);

int main()
{
	int strok;
	cout << "The number of input rows = ";
	cin >> strok;
	string strin[15];
	string kek;
	int len = 40;
	int i;
	char **Massiv = new char*[strok + 1];
	for (i = 0; i<strok + 1; i++) Massiv[i] = new char[len];
	for (i = 0; i<strok + 1; i++) cin.getline(Massiv[i], len);
	for (i = 1; i<strok + 1; i++)
	{
		string str = Massiv[i];
		strin[i] = str;
	}
	int mlen = 0;
	for (i = 1; i<strok + 1; i++)
	{
		kek = strin[i];
		int len = lenStr(kek);
		if (len > mlen)
		{
			mlen = len;
		}
	}
	int needSpace;
	int cancel;
	for (i = 1; i<strok + 1; i++)
	{
		int spaceCounter = spaceCount(strin[i]);
		int leng = lenStr(strin[i]);
		if (spaceCounter == 0)
		{
			goto a;
		}
		if ((mlen - leng) % spaceCounter == 1)
		{
			cout << "This text is impossible to justify, inserting spaces evenly throughout the string.";
			i = 1;
			cancel = 1;
			break;
		}
	a:;
	}
	for (i = 1; (i<strok + 1) && cancel != 1; i++)
	{
		if (cancel != 1)
		{
			int len = lenStr(strin[i]);
			needSpace = mlen - len;
			kek = strin[i];
			strin[i] = doubleSpace(kek, needSpace);
			cout << strin[i] << endl;
		}
	}
	for (i = 0; i<strok + 1; i++) delete[]Massiv[i]; 
	delete[]Massiv;
	cin.get();
}

string doubleSpace(string s, int needSpace)
{
	string r;
	char c;
	for (int i = 0; (c = s[i]) != '\0'; i++)
	{
		if (c == ' ')
		{
			for (int i = 0; i < needSpace; i++)
			{
				r += ' ';
			}
		}
		r += c;
	}
	return r;
}

int lenStr(string s)
{
	int len = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}

int spaceCount(string s)
{
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			count++;
		}
	}
	return count;
}