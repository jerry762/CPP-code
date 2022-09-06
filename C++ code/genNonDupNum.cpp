#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    vector<int> nums;
    int size;

    cout << "input size: ";
    cin >> size;

    for (int i = 0; i < size; i++)
        nums.push_back(i);

    for (int i = 0; i < 100000; i++)
        swap(nums.at(rand() % size), nums.at(rand() % size));

    for (int i : nums)
        cout << i << " ";

    return 0;
}
