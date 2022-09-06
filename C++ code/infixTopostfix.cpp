#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    stack<pair<char, int>> stack;
    map<char, int> ops = {{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    char op;
    string express;

    cin >> n;

    getchar();

    while (n--)
    {
        getline(cin, express);

        for (int i = 0; i < express.size(); i++)
        {
            op = express.at(i);
            if (op == ' ')
                continue;
            if (op >= '0' && op <= '9')
            {
                cout << op << " ";
            }
            else
            {
                if (ops.count(op))
                {
                    if (stack.empty() || stack.top().second < ops[op] || op == '(')
                    {
                        stack.push(make_pair(op, ops[op]));
                    }
                    else
                    {
                        cout << stack.top().first << " ";
                        stack.pop();
                        stack.push(make_pair(op, ops[op]));
                    }
                }
                else
                {
                    while (stack.top().first != '(')
                    {
                        cout << stack.top().first << " ";
                        stack.pop();
                    }
                    stack.pop();
                }
            }
        }
        while (!stack.empty())
        {
            cout << stack.top().first << " ";
            stack.pop();
        }
        cout << endl;
    }
    return 0;
}