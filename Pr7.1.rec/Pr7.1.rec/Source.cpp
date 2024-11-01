#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** c, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** c, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** c, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** c, const int row1, const int row2, const int colCount);
void Calc(int** c, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -21;
    const int High = 18;

    const int rowCount = 8;
    const int colCount = 7;

    int** c = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        c[i] = new int[colCount];

    Create(c, rowCount, colCount, Low, High);
    cout << "Start matrix:" << endl;
    cout << endl;
    Print(c, rowCount, colCount);
    Sort(c, rowCount, colCount);
    cout << endl;
    cout << "Sorted matrix:" << endl;
    cout << endl;
    Print(c, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(c, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << endl;
    cout << "Modified matrix:" << endl;
    Print(c, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] c[i];
    delete[] c;
    return 0;
}

void Create(int** c, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i >= rowCount) return;
    c[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(c, rowCount, colCount, Low, High, i, j + 1);
    else
        Create(c, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** c, const int rowCount, const int colCount, int i, int j)
{
    if (i >= rowCount) return;
    cout << setw(4) << c[i][j];
    if (j < colCount - 1)
        Print(c, rowCount, colCount, i, j + 1);
    else
    {
        cout << endl;
        Print(c, rowCount, colCount, i + 1, 0);
    }
}

void Sort(int** c, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 >= rowCount - 1) return;

    if (i1 < rowCount - i0 - 1)
    {
        if ((c[i1][0] > c[i1 + 1][0]) ||
            (c[i1][0] == c[i1 + 1][0] && c[i1][1] < c[i1 + 1][1]) ||
            (c[i1][0] == c[i1 + 1][0] && c[i1][1] == c[i1 + 1][1] && c[i1][2] < c[i1 + 1][2]))
        {
            Change(c, i1, i1 + 1, colCount);
        }
        Sort(c, rowCount, colCount, i0, i1 + 1);
    }
    else
    {
        Sort(c, rowCount, colCount, i0 + 1, 0);
    }
}

void Change(int** c, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = c[row1][j];
        c[row1][j] = c[row2][j];
        c[row2][j] = tmp;
    }
}

void Calc(int** c, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i >= rowCount) return;

    if (c[i][j] % 2 == 0 || !(c[i][j] > 0))
    {
        S += c[i][j];
        k++;
        c[i][j] = 0;
    }

    if (j < colCount - 1)
        Calc(c, rowCount, colCount, S, k, i, j + 1);
    else
        Calc(c, rowCount, colCount, S, k, i + 1, 0);
}
