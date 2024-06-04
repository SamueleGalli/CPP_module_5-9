#include "BitcoinExchange.hpp"

int main(int c, char **v)
{
    BitcoinExchange btc;
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
    v = v + 1 - 1;
    std::ifstream file("data.csv");
    if (file.is_open() == 0)
    {
        std::cout << "Error: could not open \"data.csv\" file" << std::endl;
        return (1);
    }
    std::ifstream file2(v[1]);
    if (file2.is_open() == 0)
    {
        std::cout << "Error: could not open file " << "\"" << v[1]<< "\"" << std::endl;
        return (1);
    }
    btc.get_map_bitcoin(file);
    if (btc.is_valid == 1)
        return (1);
    btc.exchanging(file2);
}