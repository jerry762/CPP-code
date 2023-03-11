#include <iostream>
#include <array>

using namespace std;

int gcd(int a, int b)
{
    return (a % b == 0) ? b : gcd(b, a % b);
}

int fib(int n)
{
    int a = 0, b = 1, c = 0;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        for (size_t i = 2; i <= n; i++)
        {
            a = b + c;
            c = b;
            b = a;
        }
        return a;
    }
}

int fib_o(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib_o(n - 1) + fib_o(n - 2);
}

int fib_r(int n, array<int, 100000> &arr)
{
    if (arr.at(n) != 0)
        return arr.at(n);
    if (n == 0)
        return 0;
    return arr.at(n) = fib_r(n - 1, arr) + fib_r(n - 2, arr);
}

int fib_i(int n, array<int, 100000> &arr)
{
    arr.fill(0);
    arr.at(1) = 1;

    for (size_t i = 2; i <= n; i++)
        arr.at(i) = arr.at(i - 1) + arr.at(i - 2);

    return arr.at(n);
}

int main()
{
    array<int, 100000> arr{0, 1};

    cout << gcd(36, 6) << endl;
    cout << fib_o(45) << endl;
    cout << fib(45) << endl;
    cout << fib_r(45, arr) << endl;
    cout << fib_i(45, arr) << endl;

    return 0;
}