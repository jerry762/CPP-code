#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <random>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
    random_device rd;
    uniform_int_distribution<int> distInt(1, 100);
    uniform_real_distribution<double> distReal(0.0, 1.0);

    vector<int> vec(10);

    iota(vec.begin(), vec.end(), 1);

    while (1)
    {
        cout << setw(3) << distInt(rd) << " " << setw(6) << fixed << setprecision(4) << distReal(rd) << endl;

        for (int i : vec)
            cout << i << " ";

        shuffle(vec.begin(), vec.end(), rd);
        cout << endl;

        Sleep(500);
    }

    return 0;
}