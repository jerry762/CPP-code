#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int binary_search_iterative(vector<int> &numbers, int &target);
int binary_search_recursive(vector<int> &numbers, int &target, int l, int r);

ostream &operator<<(ostream &out, const vector<int> &numbers);

int main()
{
    srand(time(0));

    int result, target;
    set<int> set;
    vector<int> numbers;

    cout << numbers;

    while (set.size() < 10)
        set.insert(rand() % 100);

    numbers.assign(set.begin(), set.end());

    cout << numbers << endl;
    cout << "Enter the target: ";
    cin >> target;

    result = binary_search_iterative(numbers, target);
    cout << "Iterative Result: " << result << endl;

    result = binary_search_recursive(numbers, target, 0, numbers.size());
    cout << "Recursive Result: " << result;
}

ostream &operator<<(ostream &out, const vector<int> &numbers)
{
    for (int i : numbers)
    {
        out << i << " ";
    }
    return out;
}
int binary_search_iterative(vector<int> &numbers, int &target)
{
    int l = 0, r = numbers.size();

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (numbers[m] == target)
        {
            return m;
        }
        else if (target > numbers[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}
int binary_search_recursive(vector<int> &numbers, int &target, int l, int r)
{
    if (l <= r)
    {
        int m = (l + r) / 2;

        if (numbers[m] == target)
        {
            return m;
        }
        else if (target > numbers[m])
        {
            return binary_search_recursive(numbers, target, m + 1, r);
        }
        else
        {
            return binary_search_recursive(numbers, target, l, m - 1);
        }
    }
    else
    {
        return -1;
    }
}
