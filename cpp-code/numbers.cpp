#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<vector<string>> numbers = {
        {"*****",
         "*   *",
         "*   *",
         "*   *",
         "*****"},
        {"    *",
         "    *",
         "    *",
         "    *",
         "    *"},
        {"*****",
         "    *",
         "*****",
         "*    ",
         "*****"},
        {"*****",
         "    *",
         "*****",
         "    *",
         "*****"},
        {"*   *",
         "*   *",
         "*****",
         "    *",
         "    *"},
        {"*****",
         "*    ",
         "*****",
         "    *",
         "*****"},
        {"*****",
         "*    ",
         "*****",
         "*   *",
         "*****"},
        {"*****",
         "    *",
         "    *",
         "    *",
         "    *"},
        {"*****",
         "*   *",
         "*****",
         "*   *",
         "*****"},
        {"*****",
         "*   *",
         "*****",
         "    *",
         "    *"}};

    string input;
    
    cin >> input;

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < input.size(); j++)
        {
            cout << numbers.at(input.at(j) - '0').at(i) << " ";
        }
        cout << endl;
    }

    return 0;
}