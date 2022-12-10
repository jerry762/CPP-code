#if !defined(DOUBLY_LINKED_NODE_H)
#define DOUBLY_LINKED_NODE_H

// TODO: This is the starting point of the declaration.

class DoublyLinkedNode
{
private:
    double m_number;
    DoublyLinkedNode *m_nextPtr;
    DoublyLinkedNode *m_prevPtr;

public:
    inline explicit DoublyLinkedNode();
    inline explicit DoublyLinkedNode(double num);
    inline ~DoublyLinkedNode() = default;
    inline DoublyLinkedNode(const DoublyLinkedNode &doublyLinkedNode) = delete;
    inline DoublyLinkedNode &operator=(const DoublyLinkedNode &doublyLinkedNode) = delete;
    inline double getNumber() const;
    inline DoublyLinkedNode *getNextPtr() const;
    inline DoublyLinkedNode *getPrevPtr() const;
    inline void setNumber(double num);
    inline void setNextPtr(DoublyLinkedNode *nextPtr);
    inline void setPrevPtr(DoublyLinkedNode *prevPtr);
};

// TODO: This is the starting point of the definition.

DoublyLinkedNode::DoublyLinkedNode() : m_number(0), m_nextPtr(nullptr), m_prevPtr(nullptr) {}
DoublyLinkedNode::DoublyLinkedNode(double num) : m_number(num), m_nextPtr(nullptr), m_prevPtr(nullptr) {}

double DoublyLinkedNode::getNumber() const
{
    return m_number;
}

DoublyLinkedNode *DoublyLinkedNode::getNextPtr() const
{
    return m_nextPtr;
}

DoublyLinkedNode *DoublyLinkedNode::getPrevPtr() const
{
    return m_prevPtr;
}

void DoublyLinkedNode::setNumber(double num)
{
    m_number = num;
}

void DoublyLinkedNode::setNextPtr(DoublyLinkedNode *nextPtr)
{
    m_nextPtr = nextPtr;
}

void DoublyLinkedNode::setPrevPtr(DoublyLinkedNode *prevPtr)
{
    m_prevPtr = prevPtr;
}

#endif // DOUBLY_LINKED_NODE_H
