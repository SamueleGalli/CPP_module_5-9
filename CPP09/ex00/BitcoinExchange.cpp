#include "BitcoinExchange.hpp"

//constructor
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc)
{
    if (this != &btc)
    {
        *this = btc;
    }
}

//assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc)
{
    if (this != &btc)
    {
        *this = btc;
    }
    return (*this);
}

//destructor
BitcoinExchange::~BitcoinExchange()
{
}