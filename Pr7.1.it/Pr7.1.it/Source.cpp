// Lab_7_1.cpp
// Мартиненко Вікторія
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 21
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** с, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** с, const int rowCount, const int colCount);
void Sort(int** с, const int rowCount, const int colCount);
void Change(int** с, const int row1, const int row2, const int colCount);
void Calc(int** с, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -21;
	int High = 18;
	int rowCount = 8;
	int colCount = 7;
	int** с = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		с[i] = new int[colCount];
	Create(с, rowCount, colCount, Low, High);
	Print(с, rowCount, colCount);
	Sort(с, rowCount, colCount);
	Print(с, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(с, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(с, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] с[i];
	delete[] с;
	return 0;
}
void Create(int** с, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			с[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** с, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << с[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** с, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((с[i1][0] < с[i1 + 1][0])
				||
				(с[i1][0] == с[i1 + 1][0] &&
					с[i1][1] < с[i1 + 1][1])
				||
				(с[i1][0] == с[i1 + 1][0] &&
					с[i1][1] == с[i1 + 1][1] &&
					с[i1][3] > с[i1 + 1][3]))
				Change(с, i1, i1 + 1, colCount);
}
void Change(int** с, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = с[row1][j];
		с[row1][j] = с[row2][j];
		с[row2][j] = tmp;
	}
}
void Calc(int** с, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (с[i][j] % 2 == 0 || !(с[i][j] > 0))
			{
				S += с[i][j];
				k++;
				с[i][j] = 0;
			}
}