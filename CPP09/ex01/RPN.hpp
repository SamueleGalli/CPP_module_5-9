#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>
#include <cmath>
#include <cstring>
class RPN
{
    public:
        bool    is_valid;
        //constructor
        RPN();
        RPN(const RPN &copy);
        //copy assignment operator
        RPN     &operator=(const RPN &copy);
        
        //methods
        double    reverse_polish_notation(char *v);
        //destructor
        ~RPN();
};

#endif