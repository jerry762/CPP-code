#include <iostream>
#include <queue>

using namespace std;

class Node
{
private:
    int data = 0;
    Node *leftPtr = nullptr;
    Node *rightPtr = nullptr;

public:
    explicit Node(int num);
    ~Node();
    void setData(int num);
    void setLeftPtr(Node *ptr);
    void setRightPtr(Node *ptr);
    int getData() const;
    Node *getLeftPtr() const;
    Node *getRightPtr() const;
};

class BalancedBinaryTree
{
private:
    Node *root = nullptr;
    void preorderTraversal(Node *node) const;
    void inorderTraversal(Node *node) const;
    void postorderTraversal(Node *node) const;

public:
    explicit BalancedBinaryTree(int num);
    ~BalancedBinaryTree();
    void insert(int num);
    void preorder() const;
    void inorder() const;
    void postorder() const;
    void levelorder() const;
    void drawTree() const;
};

Node::Node(int num) : data(num)
{
}

Node::~Node()
{
    delete this;
}

void Node::setData(int num)
{
    this->data = num;
}

void Node::setLeftPtr(Node *ptr)
{
    this->leftPtr = ptr;
}

void Node::setRightPtr(Node *ptr)
{
    this->rightPtr = ptr;
}

int Node::getData() const
{
    return this->data;
}

Node *Node::getLeftPtr() const
{
    return this->leftPtr;
}

Node *Node::getRightPtr() const
{
    return this->rightPtr;
}

BalancedBinaryTree::BalancedBinaryTree(int num)
{
    this->root = new Node(num);
}

BalancedBinaryTree::~BalancedBinaryTree()
{
}

void BalancedBinaryTree::insert(int num)
{
    Node *newNode = new Node(num);
    queue<Node *> record;

    record.push(root);

    while (!record.empty())
    {
        Node *node = record.front();

        record.pop();

        if (!node->getLeftPtr())
        {
            node->setLeftPtr(newNode);
            return;
        }
        if (!node->getRightPtr())
        {
            node->setRightPtr(newNode);
            return;
        }
        record.push(node->getLeftPtr());
        record.push(node->getRightPtr());
    }
}

void BalancedBinaryTree::preorderTraversal(Node *node) const
{
    if (node)
    {
        cout << node->getData() << " ";
        preorderTraversal(node->getLeftPtr());
        preorderTraversal(node->getRightPtr());
    }
}

void BalancedBinaryTree::inorderTraversal(Node *node) const
{
    if (node)
    {
        inorderTraversal(node->getLeftPtr());
        cout << node->getData() << " ";
        inorderTraversal(node->getRightPtr());
    }
}

void BalancedBinaryTree::postorderTraversal(Node *node) const
{
    if (node)
    {
        postorderTraversal(node->getLeftPtr());
        postorderTraversal(node->getRightPtr());
        cout << node->getData() << " ";
    }
}

void BalancedBinaryTree::preorder() const
{
    cout << "preorder: ";
    preorderTraversal(this->root);
    cout << endl;
}

void BalancedBinaryTree::inorder() const
{
    cout << "inorder: ";
    inorderTraversal(this->root);
    cout << endl;
}

void BalancedBinaryTree::postorder() const
{
    cout << "postorder: ";
    postorderTraversal(this->root);
    cout << endl;
}

void BalancedBinaryTree::levelorder() const
{
    cout << "levelorder: ";

    queue<Node *> sto;

    sto.push(this->root);

    while (!sto.empty())
    {
        Node *temp = sto.front();
        cout << temp->getData() << " ";
        if (temp->getLeftPtr())
        {
            sto.push(temp->getLeftPtr());
        }
        if (temp->getRightPtr())
        {
            sto.push(temp->getRightPtr());
        }
        sto.pop();
    }

    cout << endl;
}
void BalancedBinaryTree::drawTree() const
{
}

int main()
{
    BalancedBinaryTree tree(4);

    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    tree.preorder();
    tree.inorder();
    tree.postorder();
    tree.levelorder();
}
