#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#define flag 2

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

    //* Insertion sort
#if flag == 1

    for (int i = 1; i < vec.size(); i++)
    {
        int key = vec.at(i);
        for (int j = 0; j < i; j++)
        {
            if (key < vec.at(j))
            {
                for (int k = 0; k < i - j; k++)
                {
                    vec.at(i - k) = vec.at(i - 1 - k);
                }
                vec.at(j) = key;
                break;
            }
        }
    }

#endif

#if flag == 2

    for (int i = 1; i < vec.size(); i++)
    {
        int key = vec.at(i);
        int j = i - 1;

        while (j >= 0 && vec.at(j) > key)
        {
            vec.at(j + 1) = vec.at(j);
            j--;
        }
        vec.at(j + 1) = key;
    }

#endif

    //* print result

    cout << "\n";

    for (const int &a : vec)
        cout << a << " ";

    return 0;
}