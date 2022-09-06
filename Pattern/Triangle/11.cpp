#include <iostream>

using namespace std;

int main()
{
    int height;
    int diff = 'A' - 'a';
    int count = 0;

    cout << "Input a height: ";
    cin >> height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (count % 2 == 0)
            {
                cout << (char)('a' + count) << " ";
            }
            else
            {
                cout << (char)('a' + count + diff) << " ";
            }
            count++;
        }
        cout << endl;
    }

    return 0;
}