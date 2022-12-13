#include <iostream>
#include "binary_tree.hpp"

int main()
{
    BinaryTree<int> tree{1, 2, 3, 5, 8, 9, 9, 2, 5};
    BinaryTree<int> tree2{0};
    BinaryTree<int> tree3(9, tree, tree2);

    std::cout << tree.getHeight() << " " << tree3.getHeight() << std::endl;

    std::cout << tree.getSize() << " " << tree3.getSize() << std::endl;

    std::cout << tree.getRootPtr() << " " << tree3.getRootPtr() << std::endl;

    tree3.levelorder();

    tree3.clear();

    std::cout << tree3.getSize() << std::endl;

    

    return 0;
}