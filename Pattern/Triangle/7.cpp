#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int height;
    int count = 1;

    cout << "Input a height: ";
    cin >> height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << left << setw(2) << count << " ";
            count++;
        }
        cout << endl;
    }

    return 0;
}