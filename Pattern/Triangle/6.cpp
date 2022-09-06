#include <iostream>

using namespace std;

int main()
{
    int height;

    cout << "Input a height: ";
    cin >> height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = height - 1 - i; j >= 0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}