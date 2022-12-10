#if !defined(DOUBLY_LINKED_LIST_H)
#define DOUBLY_LINKED_LIST_H

#include <initializer_list>
#include <iostream>
#include "doubly_linked_node.hpp"

// TODO: This is the starting point of the declaration.

class DoublyLinkedList
{
private:
    DoublyLinkedNode *m_headPtr;
    DoublyLinkedNode *m_tailPtr;
    size_t m_size;
    DoublyLinkedNode *reverse_recursive_implement(DoublyLinkedNode *currNode);        //* completed
    void reset();                                                                     //* completed
    friend std::ostream &operator<<(std::ostream &out, const DoublyLinkedList &list); //* completed

public:
    explicit DoublyLinkedList();                                    //* completed
    explicit DoublyLinkedList(size_t size);                         //* completed
    DoublyLinkedList(size_t size, double fillNum);                  //* completed
    DoublyLinkedList(const std::initializer_list<double> &list);    //* completed
    ~DoublyLinkedList();                                            //* completed
    DoublyLinkedList(const DoublyLinkedList &) = delete;            //* completed (delete copy constructor)
    DoublyLinkedList &operator=(const DoublyLinkedList &) = delete; //* completed (delete copy assignment)

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

    void operator+=(const DoublyLinkedList &myList) const;
};

// TODO: This is the starting point of the definition.

DoublyLinkedList::DoublyLinkedList() : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0) {}

DoublyLinkedList::DoublyLinkedList(size_t size) : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0)
{
    for (size_t i = 0; i < size; i++)
        push_front(0);
}

DoublyLinkedList::DoublyLinkedList(size_t size, double fillNum) : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0)
{
    for (size_t i = 0; i < size; i++)
        push_front(fillNum);
}

DoublyLinkedList::DoublyLinkedList(const std::initializer_list<double> &list) : m_headPtr(nullptr), m_tailPtr(nullptr), m_size(0)
{
    for (const double &i : list)
        push_back(i);
}

DoublyLinkedList::~DoublyLinkedList()
{
    DoublyLinkedNode *currNode;

    while (m_headPtr)
    {
        currNode = m_headPtr;
        m_headPtr = currNode->getNextPtr();
        delete currNode;
    }
}

// double &DoublyLinkedList::front() const
// {
//     return m_headPtr->getNumber();
// }

void DoublyLinkedList::push_front(double num)
{
    DoublyLinkedNode *newNode = new DoublyLinkedNode(num);

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

void DoublyLinkedList::push_back(double num)
{
    DoublyLinkedNode *newNode = new DoublyLinkedNode(num);

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

void DoublyLinkedList::pop_front()
{
    if (empty())
        std::cout << "DoublyLinkedList is empty !" << std::endl;
    else
    {
        DoublyLinkedNode *currNode = m_headPtr;
        m_headPtr = currNode->getNextPtr();
        m_headPtr->setPrevPtr(nullptr);
        delete currNode;
        m_size--;
        if (empty())
            reset();
    }
}

void DoublyLinkedList::pop_back()
{
    if (empty())
        std::cout << "DoublyLinkedList is empty !" << std::endl;
    else
    {
        DoublyLinkedNode *currNode = m_tailPtr;
        m_tailPtr = currNode->getPrevPtr();
        m_tailPtr->setNextPtr(nullptr);
        delete currNode;
        m_size--;
        if (empty())
            reset();
    }
}

bool DoublyLinkedList::empty() const
{
    return (size() == 0) ? true : false;
}

size_t DoublyLinkedList::size() const
{
    return m_size;
}

void DoublyLinkedList::clear()
{
    DoublyLinkedNode *currNode;

    while (m_headPtr)
    {
        currNode = m_headPtr;
        m_headPtr = currNode->getNextPtr();
        delete currNode;
    }

    reset();
}

void DoublyLinkedList::insert(double num)
{
    if (empty())
        push_back(num);
    else
    {
        DoublyLinkedNode *currNode = m_headPtr;
        DoublyLinkedNode *prevNode = nullptr;
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
            DoublyLinkedNode *newNode = new DoublyLinkedNode(num);

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

void DoublyLinkedList::remove(double num)
{
    if (empty())
        std::cout << "DoublyLinkedList is empty !";
    else
    {
        DoublyLinkedNode *currNode = m_headPtr;
        DoublyLinkedNode *prevNode = nullptr;

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

void DoublyLinkedList::reverse_iterative()
{
    if (empty())
        std::cout << "DoublyLinkedList is empty !" << std::endl;
    else
    {
        DoublyLinkedNode *prevNode = nullptr;
        DoublyLinkedNode *currNode = m_headPtr;
        DoublyLinkedNode *postNode = m_headPtr->getNextPtr();

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

void DoublyLinkedList::reverse_recursive()
{
    if (empty())
        std::cout << "DoublyLinkedList is empty !" << std::endl;
    else
    {
        DoublyLinkedNode *tempNode;
        tempNode = reverse_recursive_implement(m_headPtr);
        tempNode->setPrevPtr(tempNode->getNextPtr());
        tempNode->setNextPtr(nullptr);
        std::swap(m_headPtr, m_tailPtr);
    }
}

DoublyLinkedNode *DoublyLinkedList::reverse_recursive_implement(DoublyLinkedNode *currNode)
{
    if (!currNode->getNextPtr())
        return currNode;

    DoublyLinkedNode *postNode = reverse_recursive_implement(currNode->getNextPtr());

    postNode->setPrevPtr(postNode->getNextPtr());
    postNode->setNextPtr(currNode);
    return currNode;
}

void DoublyLinkedList::reset()
{
    m_headPtr = nullptr;
    m_tailPtr = nullptr;
    m_size = 0;
}

std::ostream &operator<<(std::ostream &out, const DoublyLinkedList &list)
{
    if (list.empty())
        out << "DoublyLinkedList is empty !";
    else
    {
        DoublyLinkedNode *currNode = list.m_headPtr;
        while (currNode->getNextPtr())
        {
            out << currNode->getNumber() << " ";
            currNode = currNode->getNextPtr();
        }
        out << currNode->getNumber();
    }

    // if (list.empty())
    //     out << "DoublyLinkedList is empty !";
    // else
    // {
    //     DoublyLinkedNode *currNode = list.m_tailPtr;
    //     while (currNode->getPrevPtr())
    //     {
    //         out << currNode->getNumber() << " ";
    //         currNode = currNode->getPrevPtr();
    //     }
    //     out << currNode->getNumber();
    // }

    return out;
}

#endif // DOUBLY_LINKED_LIST_H