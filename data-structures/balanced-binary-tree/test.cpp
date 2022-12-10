#include <iostream>
#include "balanced_binary_tree.hpp"

int main()
{
    BalancedBinaryTree<int> tree{1, 2, 3, 5, 8, 9, 9, 2, 5};
    BalancedBinaryTree<int> tree2;
    BalancedBinaryTree<int> tree3(9, tree, tree2);

    std::cout << tree.getHeight() << " " << tree3.getHeight() << std::endl;

    std::cout << tree.getRootPtr() << " " << tree3.getRootPtr();

    return 0;
}