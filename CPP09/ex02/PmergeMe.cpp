#include "PmergeMe.hpp"

//constructor
Pmergeme::Pmergeme()
{
}

Pmergeme::Pmergeme(const Pmergeme &pmg)
{
    if (this != &pmg)
        *this = pmg;
}

//assignment operetor
Pmergeme    &Pmergeme::operator=(const Pmergeme &pmg)
{
    if (this != &pmg)
        *this = pmg;
    return (*this);
}

//methods

int check_error(char **v, int c)
{
    if (c > 2)
    {
        for (int i = 1; i < c; i++)
        {
            if (std::atoi(v[i]) < 0)
            {
                std::cout << "Error not positive number" << std::endl;
                return (1);
            }
            else if (v[i + 1] != 0 && std::strcmp(v[i], v[i + 1]) == 0)
            {
                std::cout << "Error: duplication found" << std::endl;
                return (1);
            }
            for (int j = 0; v[i][j] != '\0'; j++)
            {
                if (std::isdigit(v[i][j]) == 0)
                {
                    std::cout << "Error: invalid number" << std::endl;
                    return (1);
                }
            }
        }
        return (0);
    }
    return (1);
}

void    Pmergeme::shorter(char **v, int c)
{
    if (check_error(v, c) == 1)
        return ;
    std::cout << "Before: ";
    for (int i = 1; i < c; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl << "After: ";
    std::sort(v[1], v[1] + c);
    for (int i = 1; i < c; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

//destructor
Pmergeme::~Pmergeme()
{
}