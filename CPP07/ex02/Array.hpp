#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T                *data;
        unsigned int dimension;
    public:
        //create an empty array
        Array();
        //create an array with 'n' elements
        Array(unsigned int n);
        //copy constructor that mustn't affect other array than that specified
        Array(Array const &copy);
        //copy assignment operator that mustn't affect other array than that specified
        Array &operator=(Array const &copy);
        //return the number of elements
        unsigned int size() const;
        //accedere agli elementi con [] non const(modificabile)
        T &operator[](unsigned int index);
        //accedere agli elementi con [] const(non modificabile)
        T const &operator[](unsigned int index) const;
        //destructor
        ~Array();
};

#include "Array.tpp"

#endif
