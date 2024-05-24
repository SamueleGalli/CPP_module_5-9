#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
class Span
{
    private:
        std::vector<int> vec;
        unsigned int size;
        unsigned int first;
    public:
        //costruttore
        Span();
        //costruttore di copia
        Span(const Span &copy);
        //costruttore che crea N integer
        Span(unsigned int N);

        //operatore di assegnazione
        Span    &operator=(const Span &copy);
        
        //metodi
        //aggiunge un numero a span se non sono arrivato a N
        void    addNumber(int n);
        //trova lo span piu corto se non ci sono numeri o solo 1 non ritorna nulla
        int shortestSpan();
        //trova lo span piu lungo se non ci sono numeri o solo 1 non ritorna nulla
        int longestSpan();


        //distruttore
        ~Span();

};

#endif