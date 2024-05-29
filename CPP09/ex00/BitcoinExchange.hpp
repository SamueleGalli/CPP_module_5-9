#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
//per bitcoin<chiave, valore>
#include <stdexcept>
//per ss() e altro
#include <sstream>
#include <string>
#include <limits>
class   BitcoinExchange
{
    private:
        std::map<std::string, float > bitcoin;
    public:
        //constructor
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &btc);


        //function
        void    get_map_bitcoin(std::ifstream &file);
        void    exchanging(std::ifstream &filename);
        void    shorter_exchange(std::string date, float value);
        void    find_date_price(std::string date, float value);
        //assignment operator
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        //destructor
        ~BitcoinExchange();
};

#endif