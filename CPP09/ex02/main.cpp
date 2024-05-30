#include "PmergeMe.hpp"

int    main(int c, char **v)
{
    if (c > 2)
    {
        Pmergeme pmg;
        pmg.shorter(v, c);
        return (0);
    }
    if (c == 2)
    {
        std::cout << "already sorted" << std::endl;
        return (0);
    }
    std::cout << "no arguments" << std::endl;
    return (1);
}