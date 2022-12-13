#if !defined(BINARY_TREE_H)
#define BINARY_TREE_H

#define FLAG true //* Recursive(true), Iterative(false)

#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <queue>

#include "bianry_node.hpp"

template <class T>
class BinaryTree
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
    void levelorderTree() const;
    inline void increaseSize();
    inline void decreaseSize();
    inline void setSize(const size_t &size);

public:
    inline explicit BinaryTree();
    inline explicit BinaryTree(const std::initializer_list<T> &list);
    inline explicit BinaryTree(const T &data, const BinaryTree<T> &leftTree, const BinaryTree<T> &rightTree);
    ~BinaryTree();
    inline BinaryTree(const BinaryTree<T> &tree);
    inline BinaryTree<T> &operator=(const BinaryTree<T> &tree);
    inline void insertValue(const T &value);
    inline bool removeValue(const T &value);
    inline size_t getHeight() const;
    inline void clear();
    inline size_t getSize() const;
    inline const BinaryNode<T> *const getRootPtr() const;
    inline void levelorder() const;
    inline bool empty() const;
};

template <class T>
BinaryTree<T>::BinaryTree() : m_rootPtr(nullptr), m_size(0)
{
}

template <class T>
BinaryTree<T>::BinaryTree(const std::initializer_list<T> &list) : m_rootPtr(nullptr), m_size(0)
{
    for (const T &i : list)
        insertValue(i);
}

template <class T>
BinaryTree<T>::BinaryTree(const T &data, const BinaryTree<T> &leftTree, const BinaryTree<T> &rightTree) : m_rootPtr(new BinaryNode<T>(data, copyTree(leftTree.m_rootPtr), copyTree(rightTree.m_rootPtr))), m_size(1 + leftTree.getSize() + rightTree.getSize())
{
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    destroyTree(m_rootPtr);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree)
{
    if (tree.m_rootPtr)
        m_rootPtr = copyTree(tree.m_rootPtr);
    else
        BinaryTree();
}

template <class T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &tree)
{
    if (this == &tree)
        return *this;

    if (tree.m_rootPtr)
    {
        m_rootPtr = copyTree(tree.m_rootPtr);
        setSize(tree.getSize());
    }
    else
        BinaryTree();

    return *this;
}

template <class T>
void BinaryTree<T>::insertValue(const T &value)
{
    BinaryNode<T> *newNodePtr = new BinaryNode<T>(value);

#if FLAG == true
    m_rootPtr = insertNodeRecur(m_rootPtr, newNodePtr);
#else
    insertNodeIter(m_rootPtr, newNodePtr);
#endif

    increaseSize();
}

template <class T>
bool BinaryTree<T>::removeValue(const T &value)
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
BinaryNode<T> *BinaryTree<T>::insertNodeRecur(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr)
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
bool BinaryTree<T>::removeNodeRecur(BinaryNode<T> *subTreePtr, const T &value)
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
void BinaryTree<T>::insertNodeIter(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNodePtr)
{
}

template <class T>
size_t BinaryTree<T>::getHeight() const
{
    if (m_rootPtr)
        return std::max(getTreeHeight(m_rootPtr->getLeftPtr()), getTreeHeight(m_rootPtr->getRightPtr()));
    else
        return 0;
}

template <class T>
size_t BinaryTree<T>::getTreeHeight(const BinaryNode<T> *subTreePtr) const
{
    if (!subTreePtr)
        return 0;

    return 1 + std::max(getTreeHeight(subTreePtr->getLeftPtr()), getTreeHeight(subTreePtr->getRightPtr()));
}

template <class T>
void BinaryTree<T>::clear()
{
    m_rootPtr = destroyTree(m_rootPtr);
    setSize(0);
}

template <class T>
BinaryNode<T> *BinaryTree<T>::destroyTree(BinaryNode<T> *subTreePtr)
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
BinaryNode<T> *BinaryTree<T>::copyTree(const BinaryNode<T> *subTreePtr)
{
    if (!subTreePtr)
        return nullptr;

    BinaryNode<T> *newNodePtr = new BinaryNode<T>(subTreePtr->getData());

    newNodePtr->setLeftPtr(copyTree(subTreePtr->getLeftPtr()));
    newNodePtr->setRightPtr(copyTree(subTreePtr->getRightPtr()));

    return newNodePtr;
}

template <class T>
const BinaryNode<T> *const BinaryTree<T>::getRootPtr() const
{
    return m_rootPtr;
}

template <class T>
void BinaryTree<T>::increaseSize()
{
    ++m_size;
}

template <class T>
void BinaryTree<T>::decreaseSize()
{
    --m_size;
}

template <class T>
size_t BinaryTree<T>::getSize() const
{
    return m_size;
}

template <class T>
void BinaryTree<T>::setSize(const size_t &size)
{
    m_size = size;
}

template <class T>
bool BinaryTree<T>::empty() const
{
    return (getSize() == 0) ? true : false;
}

template <class T>
void BinaryTree<T>::levelorder() const
{
    if (empty())
    {
        std::cout << "empty !" << std::endl;
    }
    else
    {
        levelorderTree();
        std::cout << std::endl;
    }
}

template <class T>
void BinaryTree<T>::levelorderTree() const
{
    std::queue<BinaryNode<T> *> queue;

    queue.push(m_rootPtr);

    while (!queue.empty())
    {
        BinaryNode<T> *tempNodePtr = queue.front();
        BinaryNode<T> *leftPtr = tempNodePtr->getLeftPtr();
        BinaryNode<T> *rightPtr = tempNodePtr->getRightPtr();

        queue.pop();

        if (leftPtr)
            queue.push(leftPtr);

        if (rightPtr)
            queue.push(rightPtr);

        std::cout << tempNodePtr->getData() << " ";
    }
}

#endif // BINARY_TREE_H
