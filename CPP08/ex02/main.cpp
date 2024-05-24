#include "MutantStack.hpp"
#include <list>
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "primo elemento = " << mstack.top() << std::endl;
    std::cout << "size = " << mstack.size() << std::endl;
    std::cout << "pop(rimozione elemento)" << std::endl;
    mstack.pop();
    std::cout << "size = " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "inzio stampo elementi stack" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "ora proviamo con un std::list" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::cout << "inzio stampo elementi lista" << std::endl;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}