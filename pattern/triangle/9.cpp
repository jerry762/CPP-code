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
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}