#include <iostream>

using namespace std;

int main()
{
    int height;

    cout << "Input a height: ";
    cin >> height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            cout << (char)('A' + height - 1 - i - j) << " ";
        }
        cout << endl;
    }

    return 0;
}