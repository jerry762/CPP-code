#include <array>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10000000

using namespace std;

int main()
{
    array<int, 6> dice = {1, 2, 3, 4, 5, 6};
    array<int, 6> count = {0};

    srand(time(0));

    for (int i = 1; i <= SIZE; i++)
    {
        switch (dice[rand() % 8])
        {
        case 1:
            count[0]++;
            break;
        case 2:
            count[1]++;
            break;
        case 3:
            count[2]++;
            break;
        case 4:
            count[3]++;
            break;
        case 5:
            count[4]++;
            break;
        case 6:
            count[5]++;
            break;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << "number " << i + 1 << ": " << count[i] << ", Probability = " << (double)count[i] / SIZE << endl;
    }
}
