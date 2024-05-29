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
    std::ifstream file2(v[1]);
    if (file2.is_open() == 0)
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
    btc.get_map_bitcoin(file);
    btc.exchanging(file2);
}