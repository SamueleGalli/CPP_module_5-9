#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
//using eredita costruttori della classe stack
//public std::stack<T> questo eredita membri pubblici e protetti
template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        //construttore
        MutantStack();
        MutantStack(const MutantStack &copy);
        
        //operatore di assegnazione
        MutantStack    &operator=(const MutantStack &copy);

        //metodi iteratori
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        //metodi per ottenere gli iteratori
        iterator begin();
        iterator end();

        //distruttore
        ~MutantStack();
};

template <typename T>
MutantStack<T>::MutantStack()
{
}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    if (this != &copy)
        *this = copy;
}

//assignment operator
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
    if (this != &copy)
    {
        *this = copy;
    }
    return *this;
}

//c sta per container
//member functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

//distructors
template <typename T>
MutantStack<T>::~MutantStack()
{
}

#endif