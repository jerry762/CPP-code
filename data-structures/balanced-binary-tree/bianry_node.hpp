#if !defined(BINARY_NODE_H)
#define BINARY_NODE_H

template <class T>
class BinaryNode
{
private:
    T m_data;
    BinaryNode<T> *m_leftPtr;
    BinaryNode<T> *m_rightPtr;

public:
    inline explicit BinaryNode() = delete;
    inline explicit BinaryNode(T data);
    inline BinaryNode(const BinaryNode<T> &binaryNode) = delete;
    inline BinaryNode &operator=(const BinaryNode<T> &binaryNode) = delete;
    ~BinaryNode() = default;
    inline T getData() const;
    inline void setData(T data);
    inline BinaryNode<T> *getLeftPtr() const;
    inline void setLeftPtr(BinaryNode<T> *leftPtr);
    inline BinaryNode<T> *getRightPtr() const;
    inline void setRightPtr(BinaryNode<T> *rightPtr);
};

template <class T>
BinaryNode<T>::BinaryNode(T data) : m_data(data), m_leftPtr(nullptr), m_rightPtr(nullptr)
{
}

template <class T>
T BinaryNode<T>::getData() const
{
    return m_data;
}

template <class T>
void BinaryNode<T>::setData(T data)
{
    m_data = data;
}

template <class T>
BinaryNode<T> *BinaryNode<T>::getLeftPtr() const
{
    return m_leftPtr;
}

template <class T>
void BinaryNode<T>::setLeftPtr(BinaryNode<T> *leftPtr)
{
    m_leftPtr = leftPtr;
}

template <class T>
BinaryNode<T> *BinaryNode<T>::getRightPtr() const
{
    return m_rightPtr;
}

template <class T>
void BinaryNode<T>::setRightPtr(BinaryNode<T> *rightPtr)
{
    m_rightPtr = rightPtr;
}

#endif // BINARY_NODE_H
