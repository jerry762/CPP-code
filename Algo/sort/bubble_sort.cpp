#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    srand(time(nullptr));

    //* init

    vector<int> vec;
    bool flag = true;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(rand() % 100 + 1);
        cout << vec.at(i) << " ";
    }

    //* Bubble sort

    for (int i = 0; i < vec.size() - 1; i++)
    {
        flag = true;
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec.at(j) > vec.at(j + 1))
            {
                swap(vec.at(j), vec.at(j + 1));
                flag = false;
            }
        }

        if (flag)
            break;
    }

    //* print result

    cout << "\n";

    for (const int &i : vec)
        cout << i << " ";

    return 0;
}