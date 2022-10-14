#include <iostream>

using namespace std;
int main()
{
    int a, b, c = 1;
    while (1)
    {
        cout << "input number (hight)" << endl;
        cin >> a;
        b = a - 1;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
                cout << "  ";
            b--;
            for (int k = 1; k <= c; k++)
                cout << "* ";
            c += 2;
            cout << endl;
        }
        c = 1;
    }
}