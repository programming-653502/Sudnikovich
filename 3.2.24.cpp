// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "locale"
#include <iomanip>

using namespace std;

int main()
{
	int m, n;
	cout << "Enter the number of rows: ";
	cin >> m;
	cout << "Enter the number of columns: ";
	cin >> n;
	int **arr = new int*[n];
	for (int t = 0; t < n; t++)
		arr[t] = new int[m];
	int i = 0, j, k = 0, p = 1;

	while (i < n*m)
	{
		k++;
		for (j = k - 1; j < m - k + 1; j++)
		{
			arr[k - 1][j] = p;
			p++;
			i++;
		}  

		for (j = k; j < n - k + 1; j++)
		{
			arr[j][m - k] = p++;
			i++;
		}  

		for (j = m - k - 1; j >= k - 1; j--)
		{
			arr[n - k][j] = p++;
			i++;
		}   

		for (j = n - k - 1; j >= k; j--)
		{
			arr[j][k - 1] = p++;
			i++;
		} 

	}

	for (int q = 0; q<n; q++)
	{
		for (int w = 0; w<m; w++)
		{
			cout << setw(4) << arr[q][w];
		};
		cout << endl;
	}
	cin >> n;
	return 0;
}

