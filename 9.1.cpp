#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main(void)
{
	setlocale(LC_CTYPE, "");

	int i, j, n, summ, sr[50];

	cout << "Введите размерность массива: \n";
	cin >> n;
	cout << "Введите матрицу: \n";
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {

		arr[i] = new int[n];
		for (int j = 0; j < n; j++)  cin >> arr[i][j];

	}

	for (i = 0; i < n; i++) {

		summ = 0;
		for (j = 0; j < n; j++)
		{
			summ += arr[i][j];
		}
		sr[i] = summ / n;
	}

	cout << "Массив a:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
			if (j == n - 1)
			{
				cout << "\n";
			}
		}
	}

	for (i = 0; i < n; i++)
		cout << "Среднее значение " << i + 1 << " строки: " << sr[i] << "\n";
	for (i = 0; i < n; i++) {
		cout << "\n";
		for (j = i + 1; j < n; j++)
		{
			if (sr[i] == sr[j])
				cout << "Совпадают " << i + 1 << " и " << j + 1 << " строки\n";
		}
	}
	delete[] arr;
	cout << "Сдача практики";
}
