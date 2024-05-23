#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
//algorithm e un container(funzioni per classi) anche chiamato STL (Standard Template Library)
#include <iostream>

template <typename T>
bool easyfind(T container, int value)
{
    //std::find cerca value nel conteiner.
    //se non trova value ritorna conteiner.end.
    //containter.begin punto di partenza della ricerca.
    //container.end elemento dopo l'ultimo quindi penso (NULL) per indicare la fine della ricerca.
    //value elemento da trovare.
    typename T::iterator find_value = std::find(container.begin(), container.end(), value);
    if (find_value != container.end())
        return (true);
    else
    {
        std::cout << "cannot find integer in container" << std::endl;
        return (false);
    }
}

#endif