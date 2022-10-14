#include <iostream>

using namespace std;

class LinkedList
{
    class Node
    {
    public:
        int number;
        Node *nextPtr;
    };

public:
    Node *headNode = nullptr;
    bool direction = true;

public:
    void inputNode(int number);
    void deleteNode(int number);
    void printList();
    Node *reverse(Node *current);
    void clear();
    bool isEmpty();
};

void LinkedList::inputNode(int number)
{
    Node *newNode = new Node, *currentPtr = headNode, *previousPtr = nullptr;
    newNode->number = number;
    newNode->nextPtr = nullptr;
    if (headNode == nullptr)
    {
        headNode = newNode;
        return;
    }
    if ((LinkedList::direction) ? (newNode->number < headNode->number) : (newNode->number > headNode->number))
    {
        newNode->nextPtr = headNode;
        headNode = newNode;
        return;
    }
    while (currentPtr != nullptr)
    {
        if ((LinkedList::direction) ? (newNode->number < currentPtr->number) : (newNode->number > currentPtr->number))
        {
            previousPtr->nextPtr = newNode;
            newNode->nextPtr = currentPtr;
            return;
        }
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    previousPtr->nextPtr = newNode;
}
void LinkedList::deleteNode(int number)
{
    Node *currentPtr = headNode, *previousPtr = nullptr;

    if (headNode == nullptr)
    {
        cout << "no Node !" << endl;
        return;
    }
    if (headNode->number == number)
    {
        while (headNode->number == number)
        {
            headNode = headNode->nextPtr;
            delete currentPtr;
            currentPtr = headNode;
            if (headNode == nullptr)
            {
                return;
            }
        }
        return;
    }
    while (currentPtr != nullptr)
    {
        if (currentPtr->number == number)
        {
            previousPtr->nextPtr = currentPtr->nextPtr;
            delete currentPtr;
            currentPtr = previousPtr;
        }
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
}
void LinkedList::printList()
{
    Node *currentPtr = headNode;

    while (currentPtr != nullptr)
    {
        cout << currentPtr->number << " ";
        currentPtr = currentPtr->nextPtr;
    }
    cout << endl;
}
LinkedList::Node *LinkedList::reverse(LinkedList::Node *current)
{
    if (headNode == nullptr)
    {
        cout << "no Node !" << endl;
        return nullptr;
    }
    if (current->nextPtr == nullptr)
    {
        headNode = current;
        return headNode;
    }
    reverse(current->nextPtr)->nextPtr = current;
    current->nextPtr = nullptr;
    return current;
}
void LinkedList::clear()
{
    Node *currentPtr = headNode;

    while (headNode != nullptr)
    {
        headNode = headNode->nextPtr;
        delete currentPtr;
        currentPtr = headNode;
    }
}
bool LinkedList::isEmpty()
{
    return headNode == nullptr;
}

int main()
{
    LinkedList a;
    int number;
    char jud;

    while (1)
    {
        cout << "Input function i(Insert), d(Delete), r(Reverse), c(Clear), q(Quit):";
        cin >> jud;
        cout << endl;
        switch (jud)
        {
        case 'i':
            cout << "Input number:";
            cin >> number;
            a.inputNode(number);
            a.printList();
            break;

        case 'd':
            cout << "Delete number:";
            cin >> number;
            a.deleteNode(number);
            a.printList();
            break;

        case 'r':
            a.reverse(a.headNode);
            a.direction = !a.direction;
            a.printList();
            break;

        case 'c':
            if (a.isEmpty() == true)
            {
                cout << "no Node !" << endl;
                break;
            }
            a.clear();
            cout << "cleared !" << endl;
            break;

        case 'q':
            cout << "Quit !" << endl;
            return 0;

        default:
            cout << "Invalid input !" << endl;
            break;
        }
    }
}