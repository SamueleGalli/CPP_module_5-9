#include "Span.hpp"

//costruttori
Span::Span()
{
}

Span::Span(const Span &copy)
{
    if (this != &copy)
        *this = copy;
}

Span::Span(unsigned int N)
{
    first = 0;
    size = N;
    vec = std::vector<int>(N);
}

//operatore di assegnazione
Span    &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        size = copy.size;
        vec = copy.vec;
        first = copy.first;
    }
    return (*this);
}

//metodi
//aggiunge un numero a span se non sono arrivato a N
void    Span::addNumber(int n)
{
    try
    {
        if (first < size)
        {
            vec[first] = n;
            first++;
        }
        else
            throw std::exception();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Span is full" << std::endl;
    }
}

//trova lo span piu corto se non ci sono numeri o solo 1 non ritorna nulla
//trova l'elemento piu piccolo del vettore
int Span::shortestSpan()
{
    if (size <= 1)
    {
        throw std::logic_error("Span is empty or have only 1 element");
        return (0);
    }
    //ordino i numeri
    std::sort(vec.begin(), vec.end());
    //prendo il numero piu grande possibile
    int min = INT_MAX;
    for (size_t i = 1; i < vec.size(); i++)
    {
        int span = vec[i] - vec[i - 1];
        if (span < min)
            min = span;
    }
    return (min);
}

//trova lo span piu lungo se non ci sono numeri o solo 1 non ritorna nulla
//calcolo max - min per ottenere il longest span
int Span::longestSpan()
{
    if (size <= 1)
    {
        throw std::logic_error("Span is empty or have only 1 element");
        return (0);
    }
    std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
    std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
    return (*max - *min);
}

Span::~Span()
{
}