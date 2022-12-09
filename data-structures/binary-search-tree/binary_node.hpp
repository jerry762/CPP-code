#if !defined(MY_BINARY_NODE)
#define MY_BINARY_NODE

// TODO: This is the starting point of the declaration.

class BinaryNode
{
private:
    double m_number;
    size_t m_count;
    BinaryNode *m_leftPtr;
    BinaryNode *m_rightPtr;

public:
    explicit BinaryNode();
    explicit BinaryNode(double num);
    BinaryNode(size_t count, double fillNum);
    BinaryNode(BinaryNode &node) = delete;
    BinaryNode operator=(BinaryNode &node) = delete;
    double getNumber() const;
    BinaryNode *getLeftPtr() const;
    BinaryNode *getRightPtr() const;
    size_t getCount() const;
    void setNumber(double num);
    void setLeftPtr(BinaryNode *leftPtr);
    void setRightPtr(BinaryNode *rightPtr);
    void setCount(size_t count);
    void addCount();
    void minCount();
};

// TODO: This is the starting point of the definition.

BinaryNode::BinaryNode() : m_number(0), m_count(0), m_leftPtr(nullptr), m_rightPtr(nullptr) {}
BinaryNode::BinaryNode(double num) : m_number(num), m_count(1), m_leftPtr(nullptr), m_rightPtr(nullptr) {}
BinaryNode::BinaryNode(size_t count, double fillNum) : m_number(fillNum), m_count(count), m_leftPtr(nullptr), m_rightPtr(nullptr) {}

double BinaryNode::getNumber() const
{
    return m_number;
}

BinaryNode *BinaryNode::getLeftPtr() const
{
    return m_leftPtr;
}

BinaryNode *BinaryNode::getRightPtr() const
{
    return m_rightPtr;
}

size_t BinaryNode::getCount() const
{
    return m_count;
}

void BinaryNode::setNumber(double num)
{
    m_number = num;
}

void BinaryNode::setLeftPtr(BinaryNode *leftPtr)
{
    m_leftPtr = leftPtr;
}

void BinaryNode::setRightPtr(BinaryNode *rightPtr)
{
    m_rightPtr = rightPtr;
}

void BinaryNode::setCount(size_t count)
{
    m_count = count;
}

void BinaryNode::addCount()
{
    m_count++;
}

void BinaryNode::minCount()
{
    m_count--;
}

#endif // MY_BINARY_NODE
