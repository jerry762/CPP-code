#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#define MAX_SIZE 10

void heap_sort(std::vector<int> &vec);
void heapify(std::vector<int> &vec, int size, int root);

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> vec;

    for (size_t i = 0; i < MAX_SIZE; i++)
        vec.push_back(dist(rd));

    std::cout << "Heap_Sort (origin): ";

    for (const int &i : vec)
        std::cout << i << " ";

    heap_sort(vec);

    std::cout << std::endl
              << "Heap_Sort (sorted): ";

    for (const int &i : vec)
        std::cout << i << " ";

    return 0;
}

void heap_sort(std::vector<int> &vec)
{
    //* build heap
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);

    for (int i = vec.size() - 1; i > 0; i--)
    {
        std::swap(vec.at(0), vec.at(i));

        heapify(vec, i, 0);
    }
}

void heapify(std::vector<int> &vec, int size, int root)
{
    int max = root;

    int l = 2 * root + 1;

    int r = 2 * root + 2;

    if (l < size && vec.at(l) > vec.at(max))
        max = l;

    if (r < size && vec[r] > vec[max])
        max = r;

    if (max != root)
    {
        std::swap(vec.at(root), vec.at(max));

        heapify(vec, size, max);
    }
}
