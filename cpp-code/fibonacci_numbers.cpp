#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, vector<unsigned long int> &vec)
{
    for (int i : vec)
        out << i << " ";
    return out;
}

void fibonacci_numbers_iterative(vector<unsigned long int> &fibonacci)
{
    for (int i = 0; i < 10; i++)
        fibonacci.push_back(fibonacci.at(fibonacci.size() - 1) + fibonacci.at(fibonacci.size() - 2));
}

void fibonacci_numbers(vector<unsigned long int> &fibonacci)
{
}

int main()
{
    vector<unsigned long int> fibonacci(2, 1);

    fibonacci_numbers_iterative(fibonacci);
    cout << fibonacci;

    fibonacci.assign(2, 1);

    return 0;
}