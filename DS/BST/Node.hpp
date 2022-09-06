#if !defined(MY_NODE_H)
#define MY_NODE_H

// TODO: This is the starting point of the declaration.

class Node
{
private:
    double m_number;
    size_t m_count;
    Node *m_leftPtr;
    Node *m_rightPtr;

public:
    explicit Node();
    explicit Node(double num);
    Node(size_t count, double fillNum);
    Node(Node &node) = delete;
    Node operator=(Node &node) = delete;
    double getNumber() const;
    Node *getLeftPtr() const;
    Node *getRightPtr() const;
    size_t getCount() const;
    void setNumber(double num);
    void setLeftPtr(Node *leftPtr);
    void setRightPtr(Node *rightPtr);
    void setCount(size_t count);
    void addCount();
    void minCount();
};

// TODO: This is the starting point of the definition.

Node::Node() : m_number(0), m_count(0), m_leftPtr(nullptr), m_rightPtr(nullptr) {}
Node::Node(double num) : m_number(num), m_count(1), m_leftPtr(nullptr), m_rightPtr(nullptr) {}
Node::Node(size_t count, double fillNum) : m_number(fillNum), m_count(count), m_leftPtr(nullptr), m_rightPtr(nullptr) {}

double Node::getNumber() const
{
    return m_number;
}

Node *Node::getLeftPtr() const
{
    return m_leftPtr;
}

Node *Node::getRightPtr() const
{
    return m_rightPtr;
}

size_t Node::getCount() const
{
    return m_count;
}

void Node::setNumber(double num)
{
    m_number = num;
}

void Node::setLeftPtr(Node *leftPtr)
{
    m_leftPtr = leftPtr;
}

void Node::setRightPtr(Node *rightPtr)
{
    m_rightPtr = rightPtr;
}

void Node::setCount(size_t count)
{
    m_count = count;
}

void Node::addCount()
{
    m_count++;
}

void Node::minCount()
{
    m_count--;
}

#endif // MY_NODE_H
