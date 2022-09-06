#if !defined(MY_NODE_H)
#define MY_NODE_H

// TODO: This is the starting point of the declaration.

class Node
{
private:
    double m_number;
    Node *m_nextPtr;
    Node *m_prevPtr;

public:
    explicit Node();
    explicit Node(double num);
    double getNumber() const;
    Node *getNextPtr() const;
    Node *getPrevPtr() const;
    void setNumber(double num);
    void setNextPtr(Node *nextPtr);
    void setPrevPtr(Node *prevPtr);
};

// TODO: This is the starting point of the definition.

Node::Node() : m_number(0), m_nextPtr(nullptr), m_prevPtr(nullptr) {}
Node::Node(double num) : m_number(num), m_nextPtr(nullptr), m_prevPtr(nullptr) {}

double Node::getNumber() const
{
    return m_number;
}

Node *Node::getNextPtr() const
{
    return m_nextPtr;
}

Node *Node::getPrevPtr() const
{
    return m_prevPtr;
}

void Node::setNumber(double num)
{
    m_number = num;
}

void Node::setNextPtr(Node *nextPtr)
{
    m_nextPtr = nextPtr;
}

void Node::setPrevPtr(Node *prevPtr)
{
    m_prevPtr = prevPtr;
}

#endif // MY_NODE_H
