// #include <iostream>
// #include <stack>

// using namespace std;

// int main()
// {

//     stack<int> stack;
//     char jud;
//     int number;

//     while (1)
//     {

//         cout << "input P(push), p(pop), s(size), t(top), b(break): ";
//         cin >> jud;
//         switch (jud)
//         {
//         case 'P':
//             cout << "input number: ";
//             cin >> number;
//             stack.push(number);
//             break;

//         case 'p':
//             if (stack.empty())
//             {
//                 cout << "Empty !";
//                 break;
//             }
//             stack.pop();
//             cout << "pop !" << endl;
//             break;

//         case 't':
//             if (stack.empty())
//             {
//                 cout << "Empty !" << endl;
//                 break;
//             }
//             cout << "The top is :" << stack.top() << endl;
//             break;

//         case 's':
//             cout << "Size is : " << stack.size() << endl;
//             break;

//         case 'b':
//             cout << "End !" << endl;
//             return 0;

//         default:
//             cout << "invalid input !" << endl;

//         }
//     }
// }