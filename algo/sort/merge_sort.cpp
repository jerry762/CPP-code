#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <numeric>

#define MAX_SIZE 10

void merge_sort(std::vector<int> &vec, int left, int right);
void merge(std::vector<int> &vec, int left, int mid, int right);

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> vec;

    for (size_t i = 0; i < MAX_SIZE; i++)
        vec.push_back(dist(rd));

    std::cout << "Merge_Sort (origin): ";

    for (const int &i : vec)
        std::cout << i << " ";

    merge_sort(vec, 0, vec.size() - 1);

    std::cout << std::endl
              << "Merge_Sort (sorted): ";

    for (const int &i : vec)
        std::cout << i << " ";

    return 0;
}

void merge_sort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    merge_sort(vec, left, mid);      //* divide
    merge_sort(vec, mid + 1, right); //* divide
    merge(vec, left, mid, right);    //* combine
}

void merge(std::vector<int> &vec, int left, int mid, int right)
{
    std::vector<int> leftSubArr(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightSubArr(vec.begin() + mid + 1, vec.begin() + right + 1);

    leftSubArr.push_back(std::numeric_limits<int>::max());
    rightSubArr.push_back(std::numeric_limits<int>::max());

    int leftIndex = 0;
    int rightIndex = 0;

    for (size_t i = left; i <= right; i++)
    {
        if (leftSubArr.at(leftIndex) > rightSubArr.at(rightIndex))
        {
            vec.at(i) = rightSubArr.at(rightIndex);
            rightIndex++;
        }
        else
        {
            vec.at(i) = leftSubArr.at(leftIndex);
            leftIndex++;
        }
    }
}
