#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

#define MAX_SIZE 10

void insertion_sort(std::vector<int> &vec);

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> vec;

    for (size_t i = 0; i < MAX_SIZE; i++)
        vec.push_back(dist(rd));

    std::cout << "Insertion_Sort (origin): ";

    for (const int &i : vec)
        std::cout << i << " ";

    insertion_sort(vec);

    std::cout << std::endl
              << "Insertion_Sort (sorted): ";

    for (const int &i : vec)
        std::cout << i << " ";

    return 0;
}

void insertion_sort(std::vector<int> &vec)
{
    for (size_t i = 1; i < vec.size(); i++)
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
}
