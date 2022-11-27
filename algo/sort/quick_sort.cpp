#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

#define MAX_SIZE 10

void quick_sort(std::vector<int> &vec, int left, int right);
int partition(std::vector<int> &vec, int left, int right, int pivot);

std::random_device rd;
std::uniform_int_distribution<int> dist(1, 100);

int main()
{
    std::vector<int> vec;

    for (size_t i = 0; i < MAX_SIZE; i++)
        vec.push_back(dist(rd));

    std::cout << "Quick_Sort (origin): ";

    for (const int &i : vec)
        std::cout << i << " ";

    quick_sort(vec, 0, vec.size() - 1);

    std::cout << std::endl
              << "Quick_Sort (sorted): ";

    for (const int &i : vec)
        std::cout << i << " ";

    return 0;
}

void quick_sort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    dist.param(decltype(dist)::param_type(left, right));

    int pivot = partition(vec, left, right, dist(rd));

    quick_sort(vec, left, pivot - 1);
    quick_sort(vec, pivot + 1, right);
}

int partition(std::vector<int> &vec, int left, int right, int pivot)
{
    int value = vec.at(pivot);
    int storeIndex = left;

    std::swap(vec.at(pivot), vec.at(right));

    for (size_t i = left; i < right; i++)
    {
        if (vec.at(i) < value)
        {
            std::swap(vec.at(i), vec.at(storeIndex));
            storeIndex++;
        }
    }

    std::swap(vec.at(storeIndex), vec.at(right));

    return storeIndex;
}