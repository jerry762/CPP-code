#if !defined(MY_BST_NODE_H)
#define MY_BST_NODE_H

#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <queue>
#include <stack>
#include "Node.hpp"

class BST
{
private:
    Node *m_root;
    size_t m_size;
    void reset();
    void preorder_recursive_implement(Node *currNode) const;      //* completed
    void inorder_recursive_implement(Node *currNode) const;       //* completed
    void postorder_recursive_implement(Node *currNode) const;     //* completed
    Node *insert_recursive_implement(Node *currNode, double num); //* completed
    bool remove_recursive_implement(Node *currNode, double num);
    Node *successor(Node *currNode) const;   //* completed
    Node *predecessor(Node *currNode) const; //* completed

public:
    explicit BST();                          //* completed
    explicit BST(size_t size);               //* completed
    BST(size_t size, int fillNum);           //* completed
    BST(std::initializer_list<double> list); //* completed
    ~BST();
    BST(BST &bst) = delete;            //* completed
    BST &operator=(BST &bst) = delete; //* completed
    void insert_iterative(double num); //* completed
    void insert_recursive(double num); //* completed
    bool remove_iterative(double num); //* completed
    bool remove_recursive(double num);
    void preorder_iterative() const;                                    //* completed
    void preorder_recursive() const;                                    //* completed
    void inorder_iterative() const;                                     //* completed
    void inorder_recursive() const;                                     //* completed
    void postorder_iterative() const;                                   //* completed
    void postorder_recursive() const;                                   //* completed
    void levelorder() const;                                            //* completed
    bool search(double num) const;                                      //* completed
    bool empty() const;                                                 //* completed
    size_t getSize() const;                                             //* completed
    friend std::ostream &operator<<(std::ostream &out, const BST &bST); //* completed
    void test();
};

BST::BST() : m_root(nullptr), m_size(0) {}

BST::BST(size_t size) : m_root(new Node(size, 0)), m_size(size) {}

BST::BST(size_t size, int fillNum) : m_root(new Node(size, fillNum)), m_size(size) {}

BST::BST(std::initializer_list<double> list) : m_root(nullptr), m_size(0)
{
    for (const double i : list)
        insert_recursive(i);
}

BST::~BST()
{
}

void BST::insert_iterative(double num)
{
    if (empty())
        m_root = new Node(num);
    else
    {
        Node *newNode = new Node(num);
        Node *currNode = m_root;

        while (newNode)
        {
            if (num < currNode->getNumber())
            {
                if (!currNode->getLeftPtr())
                {
                    currNode->setLeftPtr(newNode);
                    newNode = nullptr;
                }
                else
                    currNode = currNode->getLeftPtr();
            }
            else if (num > currNode->getNumber())
            {
                if (!currNode->getRightPtr())
                {
                    currNode->setRightPtr(newNode);
                    newNode = nullptr;
                }
                else
                    currNode = currNode->getRightPtr();
            }
            else
            {
                currNode->addCount();
                delete newNode;
                newNode = nullptr;
            }
        }
    }
    m_size++;
}

void BST::insert_recursive(double num)
{
    if (empty())
        m_root = new Node(num);
    else
        insert_recursive_implement(m_root, num);

    m_size++;
}

Node *BST::insert_recursive_implement(Node *currNode, double num)
{
    if (!currNode)
        return new Node(num);

    Node *tempNode = nullptr;

    if (num < currNode->getNumber())
    {
        tempNode = insert_recursive_implement(currNode->getLeftPtr(), num);
        currNode->setLeftPtr(tempNode);
    }
    else if (num > currNode->getNumber())
    {
        tempNode = insert_recursive_implement(currNode->getRightPtr(), num);
        currNode->setRightPtr(tempNode);
    }
    else
        currNode->addCount();
    return currNode;
}

bool BST::remove_iterative(double num)
{
    if (empty())
    {
        std::cout << "BST is empty !" << std::endl;
        return false;
    }
    else
    {
        Node *currNode = m_root;
        Node *prevNode = nullptr;

        while (currNode && currNode->getNumber() != num)
        {
            prevNode = currNode;
            if (num > currNode->getNumber())
                currNode = currNode->getRightPtr();
            else
                currNode = currNode->getLeftPtr();
        }

        if (currNode)
        {
            if (currNode->getCount() == 1)
            {
                Node *connectedNode = nullptr;
                Node *successorNode = successor(currNode);
                Node *predecessorNode = predecessor(currNode);

                if (currNode->getLeftPtr() && currNode->getRightPtr()) //* two nodes
                {
                    connectedNode = successorNode; //* successorNode set default

                    Node tempNode(connectedNode->getCount(), connectedNode->getNumber());

                    connectedNode->setCount(1);
                    remove_iterative(connectedNode->getNumber());

                    currNode->setNumber(tempNode.getNumber());
                    currNode->setCount(tempNode.getCount());
                }
                else if (currNode->getLeftPtr() || currNode->getRightPtr()) //* one node
                {
                    if (predecessorNode)
                        connectedNode = predecessorNode;
                    else
                        connectedNode = successorNode;

                    Node tempNode(connectedNode->getCount(), connectedNode->getNumber());

                    connectedNode->setCount(1);
                    remove_iterative(connectedNode->getNumber());

                    currNode->setNumber(tempNode.getNumber());
                    currNode->setCount(tempNode.getCount());
                }
                else //* no node
                {
                    if (currNode == m_root)
                    {
                        delete m_root;
                        m_root = nullptr;
                    }
                    else
                    {
                        if (prevNode->getLeftPtr() == currNode)
                            prevNode->setLeftPtr(nullptr);
                        else
                            prevNode->setRightPtr(nullptr);

                        delete currNode;
                    }
                }
            }
            else
                currNode->minCount();

            m_size--;
        }
        else
        {
            std::cout << "Not found number "
                      << num
                      << " to delete!" << std::endl;
            return false;
        }
    }
    return true;
}

bool BST::remove_recursive(double num)
{
    return true;
}

bool BST::remove_recursive_implement(Node *currNode, double num)
{
    return true;
}

void BST::preorder_recursive_implement(Node *currNode) const
{
    if (currNode)
    {
        for (size_t i = 0; i < currNode->getCount(); i++)
            std::cout << currNode->getNumber() << " ";
        preorder_recursive_implement(currNode->getLeftPtr());
        preorder_recursive_implement(currNode->getRightPtr());
    }
}

void BST::inorder_recursive_implement(Node *currNode) const
{
    if (currNode)
    {
        inorder_recursive_implement(currNode->getLeftPtr());
        for (size_t i = 0; i < currNode->getCount(); i++)
            std::cout << currNode->getNumber() << " ";
        inorder_recursive_implement(currNode->getRightPtr());
    }
}

void BST::postorder_recursive_implement(Node *currNode) const
{
    if (currNode)
    {
        postorder_recursive_implement(currNode->getLeftPtr());
        postorder_recursive_implement(currNode->getRightPtr());
        for (size_t i = 0; i < currNode->getCount(); i++)
            std::cout << currNode->getNumber() << " ";
    }
}

void BST::preorder_iterative() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::stack<Node *> stack;

        std::cout << "preorder_iterative: ";

        stack.push(m_root);

        while (!stack.empty())
        {
            Node *tempNode = stack.top();

            stack.pop();

            for (size_t i = 0; i < tempNode->getCount(); i++)
                std::cout << tempNode->getNumber() << " ";

            if (tempNode->getRightPtr())
                stack.push(tempNode->getRightPtr());

            if (tempNode->getLeftPtr())
                stack.push(tempNode->getLeftPtr());
        }
        std::cout << std::endl;
    }
}

void BST::preorder_recursive() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::cout << "preorder_recursive: ";
        preorder_recursive_implement(m_root);
        std::cout << std::endl;
    }
}

void BST::inorder_iterative() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::stack<Node *> stack;

        std::cout << "inorder_iterative: ";

        Node *currNode = m_root;

        while (!stack.empty() || currNode)
        {
            if (currNode)
            {
                stack.push(currNode);
                currNode = currNode->getLeftPtr();
            }
            else
            {
                currNode = stack.top();
                stack.pop();

                for (size_t i = 0; i < currNode->getCount(); i++)
                    std::cout << currNode->getNumber() << " ";

                currNode = currNode->getRightPtr();
            }
        }
        std::cout << std::endl;
    }
}

void BST::inorder_recursive() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::cout << "inorder_recursive: ";
        inorder_recursive_implement(m_root);
        std::cout << std::endl;
    }
}

void BST::postorder_iterative() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::stack<Node *> stack_node;
        std::stack<Node *> stack_value;

        std::cout << "postorder_iterative: ";

        stack_node.push(m_root);

        while (!stack_node.empty())
        {
            Node *tempNode = stack_node.top();

            stack_node.pop();
            stack_value.push(tempNode);

            if (tempNode->getLeftPtr())
                stack_node.push(tempNode->getLeftPtr());

            if (tempNode->getRightPtr())
                stack_node.push(tempNode->getRightPtr());
        }

        while (!stack_value.empty())
        {
            Node *tempNode = stack_value.top();

            for (size_t i = 0; i < tempNode->getCount(); i++)
                std::cout << tempNode->getNumber() << " ";

            stack_value.pop();
        }
        std::cout << std::endl;
    }
}

void BST::postorder_recursive() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::cout << "postorder_recursive: ";
        postorder_recursive_implement(m_root);
        std::cout << std::endl;
    }
}

void BST::levelorder() const
{
    if (empty())
        std::cout << "BST is empty !" << std::endl;
    else
    {
        std::queue<Node *> queue;

        std::cout << "levelorder: ";

        queue.push(m_root);

        while (!queue.empty())
        {
            Node *tempNode = queue.front();

            for (size_t i = 0; i < tempNode->getCount(); i++)
                std::cout << tempNode->getNumber() << " ";

            queue.pop();

            if (tempNode->getLeftPtr())
                queue.push(tempNode->getLeftPtr());

            if (tempNode->getRightPtr())
                queue.push(tempNode->getRightPtr());
        }
        std::cout << std::endl;
    }
}

bool BST::search(double num) const
{
    if (empty())
    {
        std::cout << "BST is empty !" << std::endl;
        return false;
    }
    else
    {
        Node *currNode = m_root;

        while (currNode && currNode->getNumber() != num)
        {
            if (num > currNode->getNumber())
                currNode = currNode->getRightPtr();
            else
                currNode = currNode->getLeftPtr();
        }
        return currNode ? true : false;
    }
}

bool BST::empty() const
{
    return (m_root) ? false : true;
}

size_t BST::getSize() const
{
    return m_size;
}

Node *BST::successor(Node *currNode) const
{
    currNode = currNode->getRightPtr();

    while (currNode && currNode->getLeftPtr())
        currNode = currNode->getLeftPtr();

    return currNode;
}

Node *BST::predecessor(Node *currNode) const
{
    currNode = currNode->getLeftPtr();

    while (currNode && currNode->getRightPtr())
        currNode = currNode->getRightPtr();

    return currNode;
}

void BST::test()
{
    std::cout << successor(m_root->getLeftPtr())->getNumber() << std::endl;
    std::cout << predecessor(m_root->getLeftPtr())->getNumber() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const BST &bst)
{
    bst.preorder_recursive();
    bst.preorder_iterative();
    bst.inorder_recursive();
    bst.inorder_iterative();
    bst.postorder_recursive();
    bst.postorder_iterative();
    bst.levelorder();

    return out;
}

#endif // MY_BST_NODE_H
