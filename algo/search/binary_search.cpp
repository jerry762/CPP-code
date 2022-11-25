#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <functional>

bool binary_search_recursive(std::vector<int> &vec, int left, int right, int target);
bool binary_search_iterative(std::vector<int> &vec, int left, int right, int target);

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::uniform_int_distribution<int> dist(1, 100);
    std::default_random_engine gen(seed);

    std::vector<int> vec;
    int target = 0;

    while (1)
    {
        for (size_t i = 0; i < 10; i++)
        {
            int target = dist(gen);

            if (std::find(vec.begin(), vec.end(), target) == vec.end())
                vec.push_back(target);
            else
                i--;
        }

        sort(vec.begin(), vec.end(), std::less<int>());

        for (size_t i = 0; i < vec.size(); i++)
        {
            if (i == vec.size() - 1)
                std::cout << vec.at(i) << "(" << i << ")";
            else
                std::cout << vec.at(i) << "(" << i << "), ";
        }

        std::cout << std::endl
                  << "Input target: ";

        std::cin >> target;

        std::cout << "binary search recursive: "
                  << std::boolalpha << binary_search_recursive(vec, 0, vec.size(), target) << std::endl;

        std::cout << "binary search iterative: "
                  << std::boolalpha << binary_search_iterative(vec, 0, vec.size(), target) << std::endl
                  << std::endl;

        vec.clear();
    }

    return 0;
}

bool binary_search_recursive(std::vector<int> &vec, int left, int right, int target)
{
    if (left == right)
    {
        std::cout << "not found " << target << " | ";
        return false;
    }

    int mid = (left + right) / 2;

    if (target > vec.at(mid))
        return binary_search_recursive(vec, mid + 1, right, target);
    else if (target < vec.at(mid))
        return binary_search_recursive(vec, left, mid, target);
    else
    {
        std::cout << "found " << target << " | at index " << mid << " | ";
        return true;
    }
}

bool binary_search_iterative(std::vector<int> &vec, int left, int right, int target)
{
    while (left != right)
    {
        int mid = (left + right) / 2;

        if (target > vec.at(mid))
            left = mid + 1;
        else if (target < vec.at(mid))
            right = mid;
        else
        {
            std::cout << "found " << target << " | at index " << mid << " | ";
            return true;
        }
    }
    std::cout << "not found " << target << " | ";
    return false;
}
