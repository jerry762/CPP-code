#include <iostream>
#include <chrono>
#include <array>
#include <random>
#include <cmath>

#define SIZE 16 //* 0 ~ 15
#define MODE 0

using namespace std;

/*
2^0  = 1
2^1  = 2
2^2  = 4
2^3  = 8
2^4  = 16
2^5  = 32
2^6  = 64
2^7  = 128
2^8  = 256
2^9  = 512
2^10 = 1024
2^11 = 2048
2^12 = 4096
2^13 = 8192
2^14 = 16384
2^15 = 32768
*/

int main()
{
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> dist(0, SIZE - 1);

    array<unsigned int, SIZE> arr{0};

    for (size_t i = 0; i < arr.size(); i++)
        arr.at(i) = i;

    while (1)
    {
        unsigned int times = arr.at(dist(gen)), p_ans = 0;

#if MODE

        unsigned int ans = (1 << times);

        cout << "2^" << times << "? ";
        cin >> p_ans;

        if (ans == p_ans)
            cout << "True !, ans is " << ans << endl;
        else
            cout << "False !, ans is " << ans << endl;

        cout << endl;

#else

        unsigned int ans = times;

        cout << "2^X = " << (1 << times) << ", X = ? ";
        cin >> p_ans;

        if (ans == (unsigned int)log2(1 << p_ans))
            cout << "True !, ans is " << ans << endl;
        else
            cout << "False !, ans is " << ans << endl;

        cout << endl;
#endif
    }

    return 0;
}