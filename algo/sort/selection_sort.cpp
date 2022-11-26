#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

#define MAX_SIZE 10

void selection_sort(std::vector<int> &vec);

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> vec;

    for (size_t i = 0; i < MAX_SIZE; i++)
        vec.push_back(dist(rd));

    std::cout << "Selection_Sort (origin): ";

    for (const int &i : vec)
        std::cout << i << " ";

    selection_sort(vec);

    std::cout << std::endl
              << "Selection_Sort (sorted): ";

    for (const int &i : vec)
        std::cout << i << " ";

    return 0;
}

void selection_sort(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        size_t index = i;

        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec.at(index) > vec.at(j))
                index = j;
        }
        std::swap(vec.at(i), vec.at(index));
    }
}
