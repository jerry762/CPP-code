#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <cstdio>

using namespace std;

void print(vector<vector<int>> &smt);
void myDelay(vector<vector<int>> &smt);

int main()
{
    int size, count = 1, move = 0;

    cout << "Input matrix size(n*n): ";
    cin >> size;
    cout << endl;

    vector<vector<int>> smt(size, vector<int>(size, 0));

    for (int i = size - 1; i > 0; i -= 2)
    {
        for (int j = 0; j < i; j++)
        {
            smt[0 + move][0 + move + j] = count;
            myDelay(smt);
            count++;
        }
        for (int j = 0; j < i; j++)
        {
            smt[0 + move + j][size - 1 - move] = count;
            myDelay(smt);
            count++;
        }
        for (int j = 0; j < i; j++)
        {
            smt[size - 1 - move][size - 1 - move - j] = count;
            myDelay(smt);
            count++;
        }
        for (int j = 0; j < i; j++)
        {
            smt[size - 1 - move - j][0 + move] = count;
            myDelay(smt);
            count++;
        }
        move++;
    }

    if (size % 2)
    {
        smt[size / 2][size / 2] = size * size;
        myDelay(smt);
    }
    print(smt);
    return 0;
}

void print(vector<vector<int>> &smt)
{
    for (const auto row : smt)
    {
        for (const auto col : row)
        {
            printf("%3d ", col);
        }
        cout << endl;
    }
}
void myDelay(vector<vector<int>> &smt)
{
    print(smt);
    Sleep(300);
    system("cls");
}