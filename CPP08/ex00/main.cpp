#include <vector>
#include "easyfind.hpp"
int main()
{
    //array dinamico
    std::vector<int> vec;
    //alloco elementi al vettore
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    if (easyfind(vec, 5) == true)
        std::cout << "finded int value in container" << std::endl;
    return 0;
}
