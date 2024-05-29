#include "RPN.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        RPN rpn;
        int result = rpn.reverse_polish_notation(v[1]);
        if (result == 0)
            return (1);
        std::cout << "the result is =" << result << std::endl;
    }
    else
        std::cout << "invalid argument" << std::endl;
}