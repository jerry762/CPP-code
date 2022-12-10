#if !defined(BALANCED_BINARY_TREE_H)
#define BALANCED_BINARY_TREE_H

#define FLAG true //* Recursive(true), Iterative(false)

#include <iostream>
#include <algorithm>
#include <initializer_list>

#include "bianry_node.hpp"

template <class T>
class BalancedBinaryTree
{
private:
    BinaryNode<T> *m_rootPtr;
    size_t m_size;

private:
    BinaryNode<T> *insertNodeRecur(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr);
    void insertNodeIter(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr);
    bool removeNodeRecur(BinaryNode<T> *subTreePtr, const T &value);
    bool removeNodeIter(BinaryNode<T> *subTreePtr, const T &value);
    size_t getTreeHeight(const BinaryNode<T> *subTreePtr) const;
    BinaryNode<T> *destroyTree(BinaryNode<T> *subTreePtr);
    BinaryNode<T> *copyTree(const BinaryNode<T> *subTreePtr);

public:
    inline explicit BalancedBinaryTree();
    inline explicit BalancedBinaryTree(const std::initializer_list<T> &list);
    inline explicit BalancedBinaryTree(const T &data, const BalancedBinaryTree<T> &leftTree, const BalancedBinaryTree<T> &rightTree);
    ~BalancedBinaryTree();
    inline BalancedBinaryTree(const BalancedBinaryTree<T> &tree);
    inline BalancedBinaryTree<T> &operator=(const BalancedBinaryTree<T> &tree);
    inline void insertValue(const T &value);
    inline bool removeValue(const T &value);
    inline size_t getHeight() const;
    inline void clear();
    inline const BinaryNode<T> *const getRootPtr() const;
};

template <class T>
BalancedBinaryTree<T>::BalancedBinaryTree() : m_rootPtr(nullptr), m_size(0)
{
}

template <class T>
BalancedBinaryTree<T>::BalancedBinaryTree(const std::initializer_list<T> &list) : m_rootPtr(nullptr), m_size(0)
{
    for (const T &i : list)
        insertValue(i);
}

template <class T>
BalancedBinaryTree<T>::BalancedBinaryTree(const T &data, const BalancedBinaryTree<T> &leftTree, const BalancedBinaryTree<T> &rightTree) : m_rootPtr(new BinaryNode<T>(data, copyTree(leftTree.m_rootPtr), copyTree(rightTree.m_rootPtr)))
{
}

template <class T>
BalancedBinaryTree<T>::~BalancedBinaryTree()
{
    destroyTree(m_rootPtr);
}

template <class T>
BalancedBinaryTree<T>::BalancedBinaryTree(const BalancedBinaryTree<T> &tree)
{
    if (tree.m_rootPtr)
        m_rootPtr = copyTree(tree.m_rootPtr);
    else
        BalancedBinaryTree();
}

template <class T>
BalancedBinaryTree<T> &BalancedBinaryTree<T>::operator=(const BalancedBinaryTree<T> &tree)
{
    if (tree.m_rootPtr)
        m_rootPtr = copyTree(tree.m_rootPtr);
    else
        BalancedBinaryTree();
}

template <class T>
void BalancedBinaryTree<T>::insertValue(const T &value)
{
    BinaryNode<T> *newNodePtr = new BinaryNode<T>(value);

#if FLAG == true
    m_rootPtr = insertNodeRecur(m_rootPtr, newNodePtr);
#else
    insertNodeIter(m_rootPtr, newNodePtr);
#endif

    ++m_size;
}

template <class T>
bool BalancedBinaryTree<T>::removeValue(const T &value)
{
    bool isRemove = false;

#if FLAG == true
    isRemove = removeNodeRecur(m_rootPtr, value);
#else
    isRemove = removeNodeIter(m_rootPtr, value);
#endif

    if (isRemove)
        --m_size;

    if (m_size == 0)
        m_rootPtr = nullptr;

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
    return true;
}

template <class T>
void BalancedBinaryTree<T>::insertNodeIter(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr)
{
}

template <class T>
size_t BalancedBinaryTree<T>::getHeight() const
{
    if (m_rootPtr)
        return std::max(getTreeHeight(m_rootPtr->getLeftPtr()), getTreeHeight(m_rootPtr->getRightPtr()));
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
    m_rootPtr = destroyTree(m_rootPtr);
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

    return subTreePtr;
}

template <class T>
BinaryNode<T> *BalancedBinaryTree<T>::copyTree(const BinaryNode<T> *subTreePtr)
{
    if (!subTreePtr)
        return nullptr;

    BinaryNode<T> *newNodePtr = new BinaryNode<T>(subTreePtr->getData());

    newNodePtr->setLeftPtr(copyTree(subTreePtr->getLeftPtr()));
    newNodePtr->setRightPtr(copyTree(subTreePtr->getRightPtr()));

    return newNodePtr;
}

template <class T>
const BinaryNode<T> *const BalancedBinaryTree<T>::getRootPtr() const
{
    return m_rootPtr;
}

#endif // BALANCED_BINARY_TREE_H
