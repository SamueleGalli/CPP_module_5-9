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

int    finded_invalid_char(std::string line)
{
    int comma = 0;
    if (line[4] != '-' && line[7] != '-')
        return (1);
    for (size_t i = 0; i < line.size(); i++)
    {
        if (comma == 0 && line[i] == ',')
        {
            comma = i;
            break ;
        }
        if ((i != 4 && i != 7) && (line[i] < '0' || line[i] > '9'))
            return (1);
    }
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());
    //controllo se e un anno bisestile in caso rendo l'1 a 29 giorni
    if (month < 1 || month > 12 || day < 1 )
        return (1);
    int month_daily[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        month_daily[1] = 29;
    if (day > month_daily[month - 1])
        return (1);
    size_t i = ++comma;
    int character = 0;
    for (; i < line.size(); i++)
    {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '.' && (line[i] < '0' || line[i] > '9'))
            return (1);
        if (line[i] >= '0' && line[i] <= '9')
            character++;
    }
    if (character == 0)
        return (1);
    return (0);
}

void    BitcoinExchange::get_map_bitcoin(std::ifstream &file)
{
    is_valid = 0;
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
            if (l != "date,exchange_rate" && (l.empty() || finded_invalid_char(l) == 1))
            {
                std::cout << "Error: bad data.csv file invalid (" << l << ")" << std::endl;
                is_valid = 1;
                return ;
            }
            while (std::getline(ss, date, ',') && ss >> price)
            {
                if (price < 0)
                {
                    std::cout << "Error: bad data.csv file" << std::endl;
                    is_valid = 1;
                }
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
    else if (date < bitcoin.begin()->first)
    {
        std::cout << "Error: too small date" << std::endl;
        return ;
    }
    find_date_price(date, value);
}

int check_file_validation(std::string line)
{
    size_t i = 0;
    int comma = 0;
    if (line[4] != '-' || line[7] != '-' || line[10] != ' ')
        return (1);
    for (i = 0; i < 10 && line[i] != ' '; i++)
    {
        if (comma == 0 && line[i] == '|')
        {
            comma = i;
            break ;
        }
        if ((i != 4 && i != 7) && (line[i] < '0' || line[i] > '9'))
            return (1);
    }
    if (i < 10)
    return (1);
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());
    //controllo se e un anno bisestile in caso rendo l'1 a 29 giorni
    if (month < 1 || month > 12 || day < 1 )
        return (1);
    int month_daily[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        month_daily[1] = 29;
    if (day > month_daily[month - 1])
        return (1);
    for (; line[i] != '|'; i++)
    {
    }
    i++;
    for (; line[i] != '\0' && line[i] == ' '; i++)
    {
    }
    int character = 0;
    for (; i < line.size(); i++)
    {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '.' && (line[i] < '0' || line[i] > '9'))
            return (1);
        if (line[i] >= '0' && line[i] <= '9')
            character++;
    }
    if (character == 0)
        return (1);
    return (0);
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
        if (line.empty())
            continue ;
        if (i == 0 && check_file_validation(line) == 1)
            std::cout << "Error: bad input => " << line << std::endl;
        else if (ss >> date && ss.ignore(std::numeric_limits<std::streamsize>::max(), '|') && ss >> value)
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