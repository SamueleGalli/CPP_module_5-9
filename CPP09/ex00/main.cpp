#include "BitcoinExchange.hpp"

int main(int c, char **v)
{
    if (c > 2)
    {
        std::cout << "Error: too many arguments" << std::endl;
        return (1);
    }
    else if (c == 1)
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
    std::ifstream file(v[1]);
    if (file.is_open() == 1)
    {
        std::cout << "Bitcoining" << std::endl;
        file.close();
    }
    else
    {
        std::cout << "invalid bitcoin file" << std::endl;
        return (1);
    }
}