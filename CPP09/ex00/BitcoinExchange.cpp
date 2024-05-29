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

//function
void    BitcoinExchange::get_map_bitcoin(std::ifstream &file)
{
    std::string    l;
    double        price;
    if (file.is_open() == 1)
    {
        //salva la prima riga in l e continua a ciclare finche esiste
        while (std::getline(file, l))
        {
            //ss la stringa diventa il file 
            std::stringstream ss(l);
            std::string     date;
            //legge la stringa ss fino al punto e virgola e memorizza cio in date
            //cerca di memorizzare un valore numerico da ss e lo butta in price
            while (std::getline(ss, date, ',') && ss >> price)
            {
                //utilizza sintassi data/price (chiave/prezzo) usi data per ottenere il prezzo
                bitcoin[date] = price;
            }
        }
        file.close();
    }
    else
        std::cout << "invalid bitcoin file" << std::endl;
}

void    BitcoinExchange::find_date_price(std::string date, float value)
{
    //cerco data in bitcoin senno ne prendo una precedente alla corrente
    std::map<std::string, float>::iterator iterator = bitcoin.find(date);
    //restituisce end se trova un valore piu piccolo di date
    if (iterator != bitcoin.end())
        std::cout << date << " => " << value << " = " << value * iterator->second << std::endl;
    else
    {
        //ricerca data precedente valida senno da errore
        std::map<std::string, float>::iterator lower_it = bitcoin.lower_bound(date);
        lower_it--;
        //lower_it punta al value di data piu vicino calcolato con lower bound
        std::cout << date << " => " << value << " = " << value * lower_it->second << std::endl;
    }
}

void    BitcoinExchange::shorter_exchange(std::string date, float value)
{
    //valore dopo data minore di 0 (Errore)
    //valore dopo data maggiore di 1000 (Errore)
    if (value < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return ;
    }
    else if (value > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return ;
    }
    else if (date < "2009-01-02")
    {
        std::cout << "Error: too small date" << std::endl;
        return ;
    }
    find_date_price(date, value);
}

void    BitcoinExchange::exchanging(std::ifstream &filename)
{
    //leggere il file
    std::string line;
    std::string date;
    float value;
    //leggo riga per riga
    int i = 1;
    int enter = 0;
    while (std::getline(filename, line))
    {
        enter = 1;
        //prende il posto del file e dichiare una variabile date e value
        std::stringstream ss(line);
        //std::cout << "Contenuto dello stringstream ss: (" << ss.str() << ")" <<  std::endl;
        //cerca data e value nel file
        if (ss >> date && ss.ignore(std::numeric_limits<std::streamsize>::max(), '|') && ss >> value)
            shorter_exchange(date, value);
        else if (i == 0)
            std::cout << "Error: bad input => " << line << std::endl;
        i = 0;
    }
    if (enter == 0)
        std::cout << "Error: empty file" << std::endl;
    //chiusura file
    filename.close();
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