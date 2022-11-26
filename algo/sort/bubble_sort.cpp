#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#define MAX_SIZE 10

void bubble_sort(std::vector<int> &vec);

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> vec;

    for (size_t i = 0; i < MAX_SIZE; i++)
        vec.push_back(dist(rd));

    std::cout << "Bubble_Sort (origin): ";

    for (const int &i : vec)
        std::cout << i << " ";

    bubble_sort(vec);

    std::cout << std::endl
              << "Bubble_Sort (sorted): ";

    for (const int &i : vec)
        std::cout << i << " ";

    return 0;
}

void bubble_sort(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        bool change = false;

        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec.at(j) > vec.at(j + 1))
            {
                std::swap(vec.at(j), vec.at(j + 1));
                change = true;
            }
        }

        if (!change)
            break;
    }
}
