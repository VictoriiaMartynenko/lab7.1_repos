// Lab_7_1.cpp
// ���������� ³�����
// ����������� ������ � 7.1.
// ����� ������� �������� �� ������������� ����� / ��������� �������.
// ������ 21
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** �, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** �, const int rowCount, const int colCount);
void Sort(int** �, const int rowCount, const int colCount);
void Change(int** �, const int row1, const int row2, const int colCount);
void Calc(int** �, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -21;
	int High = 18;
	int rowCount = 8;
	int colCount = 7;
	int** � = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		�[i] = new int[colCount];
	Create(�, rowCount, colCount, Low, High);
	Print(�, rowCount, colCount);
	Sort(�, rowCount, colCount);
	Print(�, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(�, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(�, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] �[i];
	delete[] �;
	return 0;
}
void Create(int** �, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			�[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** �, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << �[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** �, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((�[i1][0] < �[i1 + 1][0])
				||
				(�[i1][0] == �[i1 + 1][0] &&
					�[i1][1] < �[i1 + 1][1])
				||
				(�[i1][0] == �[i1 + 1][0] &&
					�[i1][1] == �[i1 + 1][1] &&
					�[i1][3] > �[i1 + 1][3]))
				Change(�, i1, i1 + 1, colCount);
}
void Change(int** �, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = �[row1][j];
		�[row1][j] = �[row2][j];
		�[row2][j] = tmp;
	}
}
void Calc(int** �, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (�[i][j] % 2 == 0 || !(�[i][j] > 0))
			{
				S += �[i][j];
				k++;
				�[i][j] = 0;
			}
}