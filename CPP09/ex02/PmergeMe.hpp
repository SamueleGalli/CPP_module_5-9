#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
//conteinre che uso
#include <vector>
#include <deque>
//calcolatore tempo

class Pmergeme
{
    public:
        //constructor
        Pmergeme();
        Pmergeme(const Pmergeme &pmg);
        
        //assignment operetor
        Pmergeme    &operator=(const Pmergeme &pmg);

        //methods
        void    shorter(char **v, int c);

        //destructor
        ~Pmergeme();
};

#endif