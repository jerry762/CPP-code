#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

bool check_pair_bracket(string str);

int main()
{
    string str;

    while (1)
    {
        cin >> str;

        if (check_pair_bracket(str))
            cout << "True\n"
                 << endl;
        else
            cout << "False\n"
                 << endl;
    }

    return 0;
}

bool check_pair_bracket(string str)
{
    stack<char> stack;
    map<char, char> map{pair<char, char>('(', ')'),
                        pair<char, char>('[', ']'),
                        pair<char, char>('{', '}')};

    for (size_t i = 0; i < str.length(); i++)
    {
        char bracket = str.at(i);

        if (bracket == '(' || bracket == '{' || bracket == '[')
            stack.push(bracket);

        if (bracket == ')' || bracket == '}' || bracket == ']')
        {
            if (stack.empty() || map.at(stack.top()) != bracket)
                return false;

            stack.pop();
        }
    }

    if (!stack.empty())
        return false;
    else
        return true;
}