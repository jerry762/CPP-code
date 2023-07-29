#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &str);
void sort_out(string &str);

int main()
{
    string aString;

    while (1)
    {
        cout << "Enter a string or X to Exit('<' == backspace) :";
        cin >> aString;
        cout << endl;

        if (aString.at(0) == 'x')
            break;

        sort_out(aString);

        if (isPalindrome(aString))
            cout << "The \"" << aString << "\" is a Palindrome !" << endl;
        else
            cout << "The \"" << aString << "\" is not a Palindrome !" << endl;

    }
}

void sort_out(string &str)
{
    int size = str.size(), count = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        if (str.at(i) == '<')
        {
            str.erase(i, 1);
            count++;
        }
        else
        {
            if (count != 0)
            {
                str.erase(i, 1);
                count--;
            }
        }
    }
}

bool isPalindrome(string &str)
{
    int size = str.size();

    for (int i = 0; i < size / 2; i++)
    {
        if (str.at(i) != str.at(size - 1 - i))
        {
            return false;
        }
    }
    
    return true;
}