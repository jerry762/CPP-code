#if !defined(MY_LINKED_LIST_H)
#define MY_LINKED_LIST_H

#include <initializer_list>
#include <iostream>
#include "node.hpp"

// TODO: This is the starting point of the declaration.

class LinkedList
{
private:
    Node *m_headPtr;
    Node *m_tailPtr;
    size_t m_size;
    Node *reverse_recursive_implement(Node *currNode);                          //* completed
    void reset();                                                               //* completed
    friend std::ostream &operator<<(std::ostream &out, const LinkedList &list); //* completed

public:
    explicit LinkedList();                              //* completed
    explicit LinkedList(size_t size);                   //* completed
    LinkedList(size_t size, double fillNum);            //* completed
    LinkedList(std::initializer_list<double> list);     //* completed
    ~LinkedList();                                      //* completed
    LinkedList(const LinkedList &) = delete;            //* completed (delete copy constructor)
    LinkedList &operator=(const LinkedList &) = delete; //* completed (delete copy assignment)

    double &front() const;
    double &back() const;
    void push_front(double num); //* completed
    void pop_front();            //* completed
    void push_back(double num);  //* completed
    void pop_back();             //* completed
    void remove(double num);     //* completed
    void insert(double num);     //* completed
    bool empty() const;          //* completed
    size_t size() const;         //* completed
    void clear();                //* completed
    void merge();
    void reverse_recursive(); //* completed
    void reverse_iterative(); //* completed

    void operator+=(const LinkedList &myList) const;
};

// TODO: This is the starting point of the definition.

LinkedList::LinkedList() : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0) {}

LinkedList::LinkedList(size_t size) : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0)
{
    for (size_t i = 0; i < size; i++)
        push_front(0);
}

LinkedList::LinkedList(size_t size, double fillNum) : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0)
{
    for (size_t i = 0; i < size; i++)
        push_front(fillNum);
}

LinkedList::LinkedList(std::initializer_list<double> list) : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0)
{
    for (const double i : list)
        push_back(i);
}

LinkedList::~LinkedList()
{
    Node *currNode;

    while (m_headPtr)
    {
        currNode = m_headPtr;
        m_headPtr = currNode->getNextPtr();
        delete currNode;
    }
}

// double &LinkedList::front() const
// {
//     return m_headPtr->getNumber();
// }

void LinkedList::push_front(double num)
{
    Node *newNode = new Node(num);

    if (empty())
    {
        m_headPtr = newNode;
        m_tailPtr = newNode;
    }
    else
    {
        newNode->setNextPtr(m_headPtr);
        m_headPtr->setPrevPtr(newNode);
        m_headPtr = newNode;
    }
    m_size++;
}

void LinkedList::push_back(double num)
{
    Node *newNode = new Node(num);

    if (empty())
    {
        m_headPtr = newNode;
        m_tailPtr = newNode;
    }
    else
    {
        m_tailPtr->setNextPtr(newNode);
        newNode->setPrevPtr(m_tailPtr);
        m_tailPtr = newNode;
    }
    m_size++;
}

void LinkedList::pop_front()
{
    if (empty())
        std::cout << "LinkedList is empty !" << std::endl;
    else
    {
        Node *currNode = m_headPtr;
        m_headPtr = currNode->getNextPtr();
        m_headPtr->setPrevPtr(nullptr);
        delete currNode;
        m_size--;
        if (empty())
            reset();
    }
}

void LinkedList::pop_back()
{
    if (empty())
        std::cout << "LinkedList is empty !" << std::endl;
    else
    {
        Node *currNode = m_tailPtr;
        m_tailPtr = currNode->getPrevPtr();
        m_tailPtr->setNextPtr(nullptr);
        delete currNode;
        m_size--;
        if (empty())
            reset();
    }
}

bool LinkedList::empty() const
{
    return (size() == 0) ? true : false;
}

size_t LinkedList::size() const
{
    return m_size;
}

void LinkedList::clear()
{
    Node *currNode;

    while (m_headPtr)
    {
        currNode = m_headPtr;
        m_headPtr = currNode->getNextPtr();
        delete currNode;
    }

    reset();
}

void LinkedList::insert(double num)
{
    if (empty())
        push_back(num);
    else
    {
        Node *currNode = m_headPtr;
        Node *prevNode = nullptr;
        int position;
        int count = 0;

        while (currNode)
        {
            std::cout << "_"
                      << count
                      << "_ "
                      << "\'" << currNode->getNumber() << "\'"
                      << " ";
            count++;
            currNode = currNode->getNextPtr();
        }
        std::cout << "_" << count << "_" << std::endl;

        std::cout << "Select the position to insert node." << std::endl;
        std::cout << "Select position: ";
        std::cin >> position;
        currNode = m_headPtr;

        if (position == 0)
            push_front(num);
        else if (position == size())
            push_back(num);
        else
        {
            Node *newNode = new Node(num);

            for (int i = 0; i < position; i++)
            {
                prevNode = currNode;
                currNode = currNode->getNextPtr();
            }
            prevNode->setNextPtr(newNode);
            newNode->setNextPtr(currNode);
            currNode->setPrevPtr(newNode);
            newNode->setPrevPtr(prevNode);

            m_size++;
        }
    }
}

void LinkedList::remove(double num)
{
    if (empty())
        std::cout << "LinkedList is empty !";
    else
    {
        Node *currNode = m_headPtr;
        Node *prevNode = nullptr;

        while (currNode && currNode->getNumber() != num)
        {
            prevNode = currNode;
            currNode = currNode->getNextPtr();
        }
        if (currNode)
        {
            if (currNode == m_headPtr)
                pop_front();
            else if (currNode == m_tailPtr)
                pop_back();
            else
            {
                prevNode->setNextPtr(currNode->getNextPtr());
                currNode->getNextPtr()->setPrevPtr(prevNode);
                delete currNode;
                m_size--;
            }
        }
        else
            std::cout << "Didn't not find the specific node to delete." << std::endl;
    }
}

void LinkedList::reverse_iterative()
{
    if (empty())
        std::cout << "LinkedList is empty !" << std::endl;
    else
    {
        Node *prevNode = nullptr;
        Node *currNode = m_headPtr;
        Node *postNode = m_headPtr->getNextPtr();

        while (postNode)
        {
            currNode->setPrevPtr(currNode->getNextPtr());
            currNode->setNextPtr(prevNode);
            prevNode = currNode;
            currNode = postNode;
            postNode = postNode->getNextPtr();
        }
        currNode->setPrevPtr(currNode->getNextPtr());
        currNode->setNextPtr(prevNode);
        std::swap(m_headPtr, m_tailPtr);
    }
}

void LinkedList::reverse_recursive()
{
    if (empty())
        std::cout << "LinkedList is empty !" << std::endl;
    else
    {
        Node *tempNode;
        tempNode = reverse_recursive_implement(m_headPtr);
        tempNode->setPrevPtr(tempNode->getNextPtr());
        tempNode->setNextPtr(nullptr);
        std::swap(m_headPtr, m_tailPtr);
    }
}

Node *LinkedList::reverse_recursive_implement(Node *currNode)
{
    if (!currNode->getNextPtr())
        return currNode;

    Node *postNode = reverse_recursive_implement(currNode->getNextPtr());

    postNode->setPrevPtr(postNode->getNextPtr());
    postNode->setNextPtr(currNode);
    return currNode;
}

void LinkedList::reset()
{
    m_headPtr = nullptr;
    m_tailPtr = nullptr;
    m_size = 0;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &list)
{
    if (list.empty())
        out << "LinkedList is empty !";
    else
    {
        Node *currNode = list.m_headPtr;
        while (currNode->getNextPtr())
        {
            out << currNode->getNumber() << " ";
            currNode = currNode->getNextPtr();
        }
        out << currNode->getNumber();
    }

    // if (list.empty())
    //     out << "LinkedList is empty !";
    // else
    // {
    //     Node *currNode = list.m_tailPtr;
    //     while (currNode->getPrevPtr())
    //     {
    //         out << currNode->getNumber() << " ";
    //         currNode = currNode->getPrevPtr();
    //     }
    //     out << currNode->getNumber();
    // }

    return out;
}

#endif // MY_LINKED_LIST_H