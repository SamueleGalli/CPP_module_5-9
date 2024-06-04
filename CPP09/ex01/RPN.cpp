#include "RPN.hpp"


//constructor
RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
    if (this != &copy)
        *this = copy;
    
}

//copy assignment operator
RPN     &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        *this = copy;
    return (*this);
}


//methods

double    RPN::reverse_polish_notation(char *v)
{
    is_valid = 0;
    std::stack<double>  rpn;
    //suddivido la stringa in per sazi
    char    *point = std::strtok(v, " ");
    while (point != NULL)
    {
        if (std::strlen(point) == 1)
        {
            if (rpn.size() >= 2 && (point[0] == '*' || point[0] == '/' || point[0] == '+' || point[0] == '-'))
            {
                double first = rpn.top();
                rpn.pop();
                double second = rpn.top();
                rpn.pop();
                if (point[0] == '+')
                    rpn.push(first + second);
                else if (point[0] == '-')
                    rpn.push(second - first);
                else if (point[0] == '*')
                    rpn.push(first * second);
                else if (point[0] == '/')
                    rpn.push(second / first);
            }
            else
                rpn.push(point[0] - '0');

        }
        else
        {
            std::cout << "Error: invalid input" << std::endl;
            is_valid = 1;
            return (0);
        }
        point = std::strtok(0, " ");
    }
    return (rpn.top());
}

//destructor
RPN::~RPN()
{

}