// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "locale"
#include "cmath"

using namespace std;

void dateinput();
void fractionout();
void reverse();
void shorten();
void aboutauthor();

float numerator, denominator;

int main()
{
	int exit = 0, choice = 0;

	while (exit != 1)
	{
		cout << "\n\n\t\t\t\t\tMENU:\n";
		cout << "1. Enter (numerator and denominator) of rational number.\n";
		cout << "2. Output number (in numerator and denominator form, decimal и \n'science' notation).\n";
		cout << "3. Conclusion opposite to it the number.\n";
		cout << "4. The output of the reduced rational number.\n";
		cout << "5. Information.\n";
		cout << "6. Exit.\n";
		
		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			dateinput();
		}
		else if (choice == 2)
		{
			fractionout();
		}
		else if (choice == 3)
		{
			reverse();
		}
		else if (choice == 4)
		{
			shorten();
		}
		else if (choice == 5)
		{
			aboutauthor();
		}
		if (choice == 6)
		{
			cout << "Exiting...";
			exit = 1;
		}
	}
	return 0;
}

void dateinput()
{
	Input:
	cout << "Enter numerator: ";
	cin >> numerator;
	cout << "Enter denominator: ";
	cin >> denominator;
	if (denominator == 0 || denominator < numerator) goto Input;
}

void fractionout()
{
	float decOut;
	int ext = 0;
	if (numerator == 0 && denominator == 0)
	{
		cout << "\nThe number is not set. First set the number.\n";
		dateinput();
	}
	cout << "The number in the form fractions:\n" << numerator << "\n-\n" << denominator;
	decOut = numerator / denominator;
	cout << "\nA number in decimal: " << decOut;
	
	while (decOut > 10)
	{
		decOut /= 10;
		ext++;
	}
	while (decOut < 1)
	{
		decOut *= 10;
		ext--;
	}
	cout << "\nThe number in expansionary records: " << decOut << " * 10 ^ " << ext;
}

void reverse()
{
	if (numerator == 0 && denominator == 0)
	{
		cout << "\nThe number is not set. First set the number.\n";
		dateinput();
	}
	float decOut;
	decOut = numerator / denominator;
	cout << "Число, обратное заданному (в десятичном виде): " << powf(decOut, -1);
	cout << "\nЧисло, обратное заданному (в виде дроби):\n " << denominator << "\n-\n" << numerator;
}

void shorten()
{
	if (numerator == 0 && denominator == 0)
	{
		cout << "\nThe number is not set. First set the number.\n";
		dateinput();
	}
	int numeratorInt = numerator - 0;
	int denominatorInt = denominator - 0;
	int exit = 1;
	while (exit != 0)
	{
		Shr:
		int counter = 0;
		for (int i = 2; i < 99; i++)
		{
			if (numeratorInt % i == 0 && denominatorInt % i == 0)
			{
				numeratorInt /= i;
				denominatorInt /= i;
				counter++;
			}
		}
		if (counter == 0)
		{
			exit = 0;
		}
		else
		{
			goto Shr;
		}
	}
	cout << "The fraction in reduced form:\n" << numeratorInt << "\n-\n" << denominatorInt;
}

void aboutauthor()
{
	cout << "\n\nAuthor: Sudnikovich Kirill\n";
	cout << "Ver. : 1.0.0.\n\n";
}