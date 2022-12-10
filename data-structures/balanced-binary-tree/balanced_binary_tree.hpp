#if !defined(BALANCED_BINARY_TREE)
#define BALANCED_BINARY_TREE

#define FLAG true //* Recursive(true), Iterative(false)

#include <iostream>
#include <algorithm>
#include <initializer_list>

#include "bianry_node.hpp"

template <class T>
class BalancedBinaryTree
{
private:
    BinaryNode<T> *m_root;
    size_t m_size;

private:
    BinaryNode<T> *insertNodeRecur(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr);
    void insertNodeIter(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr);
    bool removeNodeRecur(BinaryNode<T> *subTreePtr, const T &value);
    bool removeNodeIter(BinaryNode<T> *subTreePtr, const T &value);
    size_t getTreeHeight(const BinaryNode<T> *subTreePtr) const;
    BinaryNode<T> *destroyTree(BinaryNode<T> *subTreePtr);

public:
    inline explicit BalancedBinaryTree();
    inline explicit BalancedBinaryTree(const std::initializer_list<T> &list);
    ~BalancedBinaryTree();
    inline BalancedBinaryTree(const BalancedBinaryTree<T> &tree) = delete;
    inline BalancedBinaryTree<T> &operator=(const BalancedBinaryTree<T> &tree) = delete;
    inline void insertValue(const T &value);
    inline bool removeValue(const T &value);
    inline size_t getHeight() const;
    inline void clear();
};

template <class T>
BalancedBinaryTree<T>::BalancedBinaryTree() : m_root(nullptr), m_size(0)
{
}

template <class T>
BalancedBinaryTree<T>::BalancedBinaryTree(const std::initializer_list<T> &list) : m_root(nullptr), m_size(0)
{
    for (const T &i : list)
        insertValue(i);
}

template <class T>
BalancedBinaryTree<T>::~BalancedBinaryTree()
{
    destroyTree(m_root);
}

template <class T>
void BalancedBinaryTree<T>::insertValue(const T &value)
{
    BinaryNode<T> *newNodePtr = new BinaryNode<T>(value);

#if FLAG == true
    m_root = insertNodeRecur(m_root, newNodePtr);
#else
    insertNodeIter(m_root, newNodePtr);
#endif

    ++m_size;
}

template <class T>
bool BalancedBinaryTree<T>::removeValue(const T &value)
{
    bool isRemove = false;

#if FLAG == true
    isRemove = removeNodeRecur(m_root, value);
#else
    isRemove = removeNodeIter(m_root, value);
#endif

    if (isRemove)
        --m_size;

    if (m_size == 0)
        m_root = nullptr;

    return isRemove;
}

template <class T>
BinaryNode<T> *BalancedBinaryTree<T>::insertNodeRecur(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr)
{
    if (!subTreePtr)
        return newNodePtr;
    else
    {
        BinaryNode<T> *leftPtr = subTreePtr->getLeftPtr();
        BinaryNode<T> *rightPtr = subTreePtr->getRightPtr();
        BinaryNode<T> *tempPtr = nullptr;

        if (getTreeHeight(leftPtr) <= getTreeHeight(rightPtr))
        {
            tempPtr = insertNodeRecur(subTreePtr->getLeftPtr(), newNodePtr);
            subTreePtr->setLeftPtr(tempPtr);
        }
        else
        {
            tempPtr = insertNodeRecur(subTreePtr->getRightPtr(), newNodePtr);
            subTreePtr->setRightPtr(tempPtr);
        }

        return subTreePtr;
    }
}

template <class T>
bool BalancedBinaryTree<T>::removeNodeRecur(BinaryNode<T> *subTreePtr, const T &value)
{
    if (subTreePtr)
    {
        if (subTreePtr->getData() == value)
        {
        }
        removeNodeRecur(subTreePtr->getLeftPtr(), value);
        removeNodeRecur(subTreePtr->getRightPtr(), value);
    }
}

template <class T>
void BalancedBinaryTree<T>::insertNodeIter(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr)
{
}

template <class T>
size_t BalancedBinaryTree<T>::getHeight() const
{
    if (m_root)
        return std::max(getTreeHeight(m_root->getLeftPtr()), getTreeHeight(m_root->getRightPtr()));
    else
        return 0;
}

template <class T>
size_t BalancedBinaryTree<T>::getTreeHeight(const BinaryNode<T> *subTreePtr) const
{
    if (!subTreePtr)
        return 0;

    return 1 + std::max(getTreeHeight(subTreePtr->getLeftPtr()), getTreeHeight(subTreePtr->getRightPtr()));
}

template <class T>
void BalancedBinaryTree<T>::clear()
{
    m_root = destroyTree(m_root);
}

template <class T>
BinaryNode<T> *BalancedBinaryTree<T>::destroyTree(BinaryNode<T> *subTreePtr)
{
    if (subTreePtr)
    {
        destroyTree(subTreePtr->getLeftPtr());
        destroyTree(subTreePtr->getRightPtr());

        delete subTreePtr;
        subTreePtr = nullptr;
        return subTreePtr;
    }
}

#endif // BALANCED_BINARY_TREE
