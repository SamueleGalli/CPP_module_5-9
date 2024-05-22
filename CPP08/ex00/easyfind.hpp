#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
T easyfind(const T& container, int value)
{
    T   *find_value = std::find(container.begin(), container.end(), value);
    if (find_value != container.end())
        return (find_value);
    else
    {
        std::cout << "cannot find integer in container" << std::endl;
        return (-1);
    }
}

#endif