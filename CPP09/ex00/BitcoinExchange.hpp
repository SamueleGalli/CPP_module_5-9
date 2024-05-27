#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
class   BitcoinExchange
{
    public:
        //constructor
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &btc);

        //assignment operator
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        //destructor
        ~BitcoinExchange();
};

#endif