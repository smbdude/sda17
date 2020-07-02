#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(void)
{
	setlocale(LC_CTYPE, "");
	int i, j, n, m, summ, sred[50];
	printf("Введите размерность массива\n");
	cin >> n;
	cin >> m;
	int** arr = new int* [n];
	for (i = 0; i < n; i++)
		arr[i] = new int[m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Введите [%d][%d] элемент массива\n", i + 1, j + 1);
			cin >> arr[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		summ = 0;
		for (j = 0; j < m; j++)
		{
			summ += arr[i][j];
		}
		sred[i] = summ / m;
	}

	printf("Массив a:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
			if (j == m - 1)
			{
				printf("\n");
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("Среднее значение %d строки:%d\n", i + 1, sred[i]);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < m; j++)
		{
			if (sred[i] == sred[j])
				printf("Совпадают %d и %d строки\n", i + 1, j + 1);
		}

	delete[] arr;
}
