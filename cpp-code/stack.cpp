// #include <bits/stdc++.h>

// using namespace std;

// class Stack
// {
//     class Node
//     {
//     private:
//         int number;
//         Node *next;

//     public:
//         static int size;

//     public:
//         Node(int number, Node *next);
//         int getNumber();
//         Node *getNext();
//         void setNumber(int number);
//         void setNext(Node *next);
//         int getSize();
//         bool empty();
//     };

// private:
//     Node *headPtr;
//     static int count;

// public:
//     Stack();
//     void push(int number);
//     void pop();
//     int getCount();
//     bool empty();
//     int top();
//     void clear();
//     void print();
//     int getSize();
// };

// int Stack::Node::size = 0;
// Stack::Node::Node(int number, Node *next) : number(number), next(next)
// {
//     size++;
// }
// int Stack::Node::getNumber()
// {
//     return number;
// }
// Stack::Node *Stack::Node::getNext()
// {
//     return next;
// }
// void Stack::Node::setNumber(int number)
// {
//     this->number = number;
// }
// void Stack::Node::setNext(Stack::Node *next)
// {
//     this->next = next;
// }
// int Stack::Node::getSize()
// {
//     return size;
// }
// bool Stack::Node::empty()
// {
//     return size == 0;
// }

// int Stack::count = 0;
// Stack::Stack() : headPtr(nullptr)
// {
//     count++;
// }
// void Stack::push(int number)
// {
//     Node *newNode = new Node(number, nullptr);

//     if (headPtr == nullptr)
//     {
//         headPtr = newNode;
//         return;
//     }
//     newNode->setNext(headPtr);
//     headPtr = newNode;
// }
// void Stack::pop()
// {
//     Node *currentPtr = nullptr;
//     currentPtr = headPtr;
//     headPtr = headPtr->getNext();
//     delete currentPtr;
//     Node::size--;
// }
// int Stack::getCount()
// {
//     return count;
// }
// bool Stack::empty()
// {
//     return headPtr == nullptr;
// }
// int Stack::top()
// {
//     return headPtr->getNumber();
// }
// void Stack::clear()
// {
//     Node *currentPtr = nullptr;
//     while (headPtr != nullptr)
//     {
//         currentPtr = headPtr;
//         headPtr = headPtr->getNext();
//         delete currentPtr;
//     }
//     Node::size = 0;
// }
// void Stack::print()
// {
//     Node *currentPtr = nullptr;
//     currentPtr = headPtr;
//     while (currentPtr != nullptr)
//     {
//         cout << currentPtr->getNumber() << " ";
//         currentPtr = currentPtr->getNext();
//     }
//     cout << endl;
// }
// int Stack::getSize()
// {
//     return headPtr->getSize();
// }

// int main()
// {
//     Stack stack;
//     char jud;
//     int number;

//     while (true)
//     {
//         cout << "input P(push), p(pop), c(clear), s(size) ,t(top), q(quit): ";
//         cin >> jud;
//         switch (jud)
//         {
//         case 'P':
//             cout << "input number :";
//             cin >> number;
//             stack.push(number);
//             stack.print();
//             break;
//         case 'p':
//             if (stack.empty())
//             {
//                 cout << "Empty !" << endl;
//                 break;
//             }
//             stack.pop();
//             cout << "poped !" << endl;
//             stack.print();
//             break;

//         case 'c':
//             if (stack.empty())
//             {
//                 cout << "Empty !" << endl;
//                 break;
//             }
//             stack.clear();
//             cout << "cleared !" << endl;
//             break;

//         case 's':
//             cout << "The size is :" << stack.getSize() << endl;
//             break;

//         case 't':
//             if (stack.empty())
//             {
//                 cout << "Empty !" << endl;
//                 break;
//             }
//             cout << "The top is :" << stack.top() << endl;
//             break;

//         case 'q':
//             cout << "Quit !" << endl;
//             return 0;

//         default:
//             cout << "invalid input !" << endl;
//             break;
//         }
//     }
// }