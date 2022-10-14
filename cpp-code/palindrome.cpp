#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &aSring);
void sort_out(string &aSring);

int main()
{
    string aString;

    while (true)
    {
        cout << "Enter a string or X to Exit('<' == backspace) :";
        cin >> aString;
        cout << endl;
        if (aString.at(0) == 'x')
        {
            break;
        }
        sort_out(aString);
        if (isPalindrome(aString))
        {
            cout << "The " << aString << " is a Palindrome !" << endl;
        }
        else
        {
            cout << "The " << aString << " is not a Palindrome !" << endl;
        }
    }
}
void sort_out(string &aSring)
{
    int size = aSring.size(), count = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        if (aSring.at(i) == '<')
        {
            aSring.erase(i, 1);
            count++;
        }
        else
        {
            if (count != 0)
            {
                aSring.erase(i, 1);
                count--;
            }
        }
    }
}
bool isPalindrome(string &aSring)
{
    int size = aSring.size();

    for (int i = 0; i < size / 2; i++)
    {
        if (aSring.at(i) != aSring.at(size - 1 - i))
        {
            return false;
        }
    }
    return true;
}