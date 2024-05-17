#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>

class ScalarConverter
{
    private:   
        //costruttore di default
        ScalarConverter();
        
        //costruttore di copia
        ScalarConverter(ScalarConverter const &copy);
        
        //operatore di assegnazione
        ScalarConverter &operator=(ScalarConverter const &copy);
        
        //distruttore
        ~ScalarConverter();
    public:
        //funzione conversione
        static void convert(std::string const &input);
        
};

#endif