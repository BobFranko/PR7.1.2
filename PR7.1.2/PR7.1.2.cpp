#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Заповнення матриці випадковими числами
void Create(int Z[7][5])
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
            Z[i][j] = 11 + rand() % 57;
}

// Виведення матриці
void Print(int Z[7][5])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << setw(4) << Z[i][j];

        cout << endl;
    }
}

// Обмін двох рядків місцями
void Change(int Z[7][5], int row1, int row2)
{
    for (int j = 0; j < 5; j++)
    {
        int tmp = Z[row1][j];
        Z[row1][j] = Z[row2][j];
        Z[row2][j] = tmp;
    }
}

// Сортування рядків за спаданням
void Sort(int Z[7][5])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i; j++)
        {
            bool needChange = false;

            if (Z[j][0] < Z[j + 1][0])
                needChange = true;

            else if (Z[j][0] == Z[j + 1][0] &&
                Z[j][1] < Z[j + 1][1])
                needChange = true;

            else if (Z[j][0] == Z[j + 1][0] &&
                Z[j][1] == Z[j + 1][1] &&
                Z[j][2] < Z[j + 1][2])
                needChange = true;

            if (needChange)
                Change(Z, j, j + 1);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Z[7][5];

    Create(Z);

    cout << "Initial matrix:" << endl;
    Print(Z);

    Sort(Z);

    cout << endl;
    cout << "Sorted matrix:" << endl;
    Print(Z);

    return 0;
}
