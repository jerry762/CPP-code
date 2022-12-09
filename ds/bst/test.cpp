#include <iostream>
#include "binary_search_tree.hpp"

using namespace std;

/*
list: {43, 8, 6, 3, 12, 68, 8, 6, 43, 50, 70, 50}

                      43(2)
                    /       \
                  8(2)      68(1)
                  /  \       /    \
                6(2) 12(1) 50(2) 70(1)
                /
               3(1)



    preorder: 43 43 8 8 6 6 3 12 68 50 50 70

    inorder: 3 6 6 8 8 12 43 43 50 50 68 70

    postorder: 3 6 6 12 8 8 50 50 70 68 43 43

    levelorder: 43 43 8 8 68 6 6 12 50 50 70 3

*/

int main()
{
  BinarySearchTree bst{43, 8, 6, 3, 12, 68, 8, 6, 43, 50, 70, 50};
  // BinarySearchTree bst{5, 1, 6};

  cout << bst.getSize() << endl;
  cout << bst;

  // bst.remove_iterative(43);
  // bst.remove_iterative(43);
  // bst.remove_iterative(68);
  // bst.remove_iterative(70);

  bst.remove_iterative(5);
  bst.remove_iterative(1);
  bst.remove_iterative(6);

  cout << bst;

  // bst.test();

  return 0;
}