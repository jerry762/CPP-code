#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void mergeSort(vector<int> &nums);
void divide(vector<int> &nums, int left, int right);
void conquer(vector<int> &nums, int left, int mid, int right);
bool compare(int a, int b);

int main()
{
    srand(time(0));
    int size;
    char cmd;
    cout << "Input nums size: ";
    cin >> size;
    vector<int> nums(size);

    cout << setw(17) << "Original nums: ";
    for (int &i : nums)
    {
        i = rand() % 100;
        cout << " " << setw(2) << i;
    }

    // cout << endl
    //      << "Input comand: ";
    // cin >> cmd;

    mergeSort(nums);
    cout << endl
         << setw(17) << "Sorted nums: ";

    for (const int &i : nums)
        cout << " " << setw(2) << i;
    return 0;
}
void mergeSort(vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    divide(nums, 0, nums.size() - 1);
}
void divide(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        divide(nums, left, mid);
        divide(nums, mid + 1, right);
        conquer(nums, left, mid, right);
    }
}
void conquer(vector<int> &nums, int left, int mid, int right)
{
    vector<int> l(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> r(nums.begin() + mid + 1, nums.begin() + right + 1);
    while (!l.empty() && !r.empty())
    {
        if (l.back() > r.back())
        {
            nums[right--] = l.back();
            l.pop_back();
        }
        else
        {
            nums[right--] = r.back();
            r.pop_back();
        }
    }
    while (!l.empty())
    {
        nums[right--] = l.back();
        l.pop_back();
    }
    while (!r.empty())
    {
        nums[right--] = r.back();
        r.pop_back();
    }
}
