#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

class DisjointSet
{
private:
    vector<int> set;

public:
    DisjointSet(int size);
    ~DisjointSet();
    int findSet(int index);
    void unionSet(int a, int b);
    int getSetSize(int index);
    friend ostream &operator<<(ostream &out, const DisjointSet &disjointSet);
};

DisjointSet::DisjointSet(int size)
{
    set.assign(size, -1);
}

DisjointSet::~DisjointSet()
{
}

int DisjointSet::getSetSize(int index)
{
    return set.at(findSet(index));
}

int DisjointSet::findSet(int index)
{
    if (set.at(index) < 0)
    {
        return index;
    }
    return set.at(index) = findSet(set.at(index));
}

void DisjointSet::unionSet(int a, int b)
{
    int root1 = findSet(a);
    int root2 = findSet(b);

    if (set.at(root1) > set.at(root2))
    {
        set.at(root2) += set.at(root1);
        set.at(root1) = root2;
    }
    else
    {
        set.at(root1) += set.at(root2);
        set.at(root2) = root1;
    }
}

ostream &operator<<(ostream &out, const DisjointSet &disjointSet)
{
    for (int i = 0; i < disjointSet.set.size(); i++)
    {
        cout << setw(3) << i << " ";
    }
    out << endl;
    for (const int i : disjointSet.set)
    {
        out << setw(3) << i << " ";
    }
    return out;
}

int main()
{
    int size;
    char cmd;

    cout << "Input size: ";

    cin >> size;

    DisjointSet set(size);

    cout << set << endl
         << endl;

    while (1)
    {
        int num1, num2;

        cout << "input cmd(f and u): ";
        cin >> cmd;
        switch (cmd)
        {
        case 'f':
            cout << "Find: ";
            cin >> num1;
            cout << num1 << " root's is " << set.findSet(num1) << ", set'element is " << set.getSetSize(num1) * -1 << endl
                 << set << endl
                 << endl;
            break;
        case 'u':
            cout << "Union: ";
            cin >> num1 >> num2;
            cout << "Before union:" << endl
                 << set << endl
                 << endl;
            set.unionSet(num1, num2);
            cout << "After union:" << endl
                 << set << endl
                 << endl;
            break;
        }
    }
    return 0;
}