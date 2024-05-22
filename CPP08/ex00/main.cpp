#include <vector>
#include "easyfind.hpp"
int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    int r = easyfind(vec, 4);
    if (r != -1)
        std::cout << "finded int value in container" << std::endl;
    return 0;
}
