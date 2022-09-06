#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int i, j;
    vector<int> lens;

    while (cin >> i >> j)
    {

        cout << i << " " << j << " ";
        if (i > j)
        {
            swap(i, j);
        }

        for (int k = i; k <= j; k++)
        {
            int n = k, len = 1;

            while (n != 1)
            {
                if (n % 2)
                {
                    n = 3 * n + 1;
                }
                else
                {
                    n = n / 2;
                }
                len++;
            }
            lens.push_back(len);
        }
        cout << *max_element(lens.begin(), lens.end()) << endl;
        lens.clear();
    }
}