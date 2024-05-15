#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    public:
        //costruttore di default
        ScalarConverter();
        
        //costruttore di copia
        ScalarConverter(ScalarConverter const &copy);
        
        //operatore di assegnazione
        ScalarConverter &operator=(ScalarConverter const &copy);
        
        //funzione conversione
        static void convert(std::string const &input);
        
        //distruttore
        ~ScalarConverter();
};

#endif