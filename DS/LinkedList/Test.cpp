#include "LinkedList.hpp"
#include <iostream>

int main()
{
    LinkedList a(5), b(8, 10), c{1, 2, 3, 4, 5, 6, 7, 8, 9};

    a.push_front(6);
    a.push_front(7);
    a.push_back(1);
    a.push_back(1);
    a.pop_back();
    a.pop_front();
    a.pop_back();
    a.pop_front();

    // a.clear();
    // b.clear();
    // c.clear();

    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << b << std::endl;
    std::cout << b.size() << std::endl;
    std::cout << c << std::endl;
    std::cout << c.size() << std::endl;

    // c.remove(4);
    // std::cout << c << std::endl;
    // std::cout << c.size() << std::endl;
    // c.remove(6);
    // std::cout << c << std::endl;
    // std::cout << c.size() << std::endl;
    // c.remove(1);
    // std::cout << c << std::endl;
    // std::cout << c.size() << std::endl;
    // c.remove(9);
    // std::cout << c << std::endl;
    // std::cout << c.size() << std::endl;
    // c.remove(0);

    // a.insert(85);
    // std::cout << a << std::endl;
    // std::cout << a.size() << std::endl;
    // a.insert(85);
    // std::cout << a << std::endl;
    // std::cout << a.size() << std::endl;
    // a.insert(85);
    // std::cout << a << std::endl;
    // std::cout << a.size() << std::endl;

    c.reverse_recursive();
    std::cout << c << std::endl;
    std::cout << c.size() << std::endl;
}