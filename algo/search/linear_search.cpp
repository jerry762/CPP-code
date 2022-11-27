#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <functional>

#define MAX_SIZE 10

bool linear_search(std::vector<int> &vec, int target);

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::uniform_int_distribution<int> dist(1, 100);
    std::default_random_engine gen(seed);

    std::vector<int> vec;
    int target = 0;

    while (1)
    {
        for (size_t i = 0; i < MAX_SIZE; i++)
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

        std::cout << "linear search: "
                  << std::boolalpha << linear_search(vec, target) << std::endl;

        vec.clear();
    }

    return 0;
}

bool linear_search(std::vector<int> &vec, int target)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) == target)
        {
            std::cout << "found " << target << " | at index " << i << " | ";
            return true;
        }
    }

    std::cout << "not found " << target << " | ";

    return false;
}
