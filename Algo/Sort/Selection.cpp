#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void)
{
    srand(time(nullptr));

    //* init

    vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(rand() % 100 + 1);
        cout << vec.at(i) << " ";
    }

    //* Selection sort

    for (int i = 0; i < vec.size() - 1; i++)
    {
        int maxIndex = 0;

        for (int j = 1; j < vec.size() - i; j++)
        {
            if (vec.at(j) > vec.at(maxIndex))
                maxIndex = j;
        }
        swap(vec.at(maxIndex), vec.at(vec.size() - 1 - i));
    }

    //* print result

    cout << "\n";

    for (const int &i : vec)
        cout << i << " ";

    return 0;
}