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

int    num_point(char *v)
{
    int num = 0;
    int point = 0;
    for (int i = 0; v[i] != '\0'; i++)
    {
        while (v[i] == ' ')
            i++;
        while(std::isdigit(v[i]) != 0)
        {
            num++;
            i++;
            while (v[i] == ' ')
                i++;
        }
        while (v[i] == '/' || v[i] == '*' || v[i] == '+' || v[i] == '-')
        {
            point++;
            i++;
            while (v[i] == ' ')
                i++;
        }
        if (point > 0 && num > 0 && (point > num - 1 || num - 1 > point))
            return (1);
        num = 0;
        point = 0;
    }
    return (0);
}

double    RPN::reverse_polish_notation(char *v)
{
    is_valid = 0;
    if (num_point(v) == 1)
    {
        std::cout << "to many or to low signs" << std::endl;
        is_valid = 1;
        return (0);
    }
    std::stack<int>  rpn;
    //suddivido la stringa in per sazi
    char    *point = std::strtok(v, " ");
    while (point != NULL)
    {
        if (std::strlen(point) == 1)
        {
            if (rpn.size() >= 2 && (point[0] == '*' || point[0] == '/' || point[0] == '+' || point[0] == '-'))
            {
                int first = rpn.top();
                rpn.pop();
                int second = rpn.top();
                rpn.pop();
                std::cout << "first = " << first << "\nsecond = " << second << std::endl;
                if (first == 0 && point[0] == '/' && second > 0)
                {
                    std::cout << "can't divide by zero" << std::endl;
                    is_valid = 1;
                    return (0);
                }
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