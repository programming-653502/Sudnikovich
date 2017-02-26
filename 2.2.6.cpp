// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "locale"

float func(float x, int n);
float fact(int n);

using namespace std;

int main()
{

	float left, right;
	int n;
	float x, e;
	cout << "Enter X: ";
	cin >> x;
	cout << "Enter the margin of error E: ";
	cin >> e;
	left = sin(x);
	for (int i = 0; i < 1000; i++)
	{
		right = func(x, i);
		if (abs(left - right) < e)
		{
			n = i;
			break;
		}
	}
	cout << "sin(x) = " << left << " . Decomposition = " << right;
	cout << "\nDiffers from the expression sin(x) when n = " << n;
	cin >> x;
	return 0;
}

float func(float x, int n)
{
	float result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
	}
	return result;
}

float fact(int n)
{
	float res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i;
	}
	return res;
}