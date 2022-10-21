#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str;
    string op = "+-*/";

    while (cin >> str)
    {
        stringstream ss(str);
        string token;

        while (getline(ss, token, ' '))
        {
            cout << token << endl;
        }
    }

    return 0;
}