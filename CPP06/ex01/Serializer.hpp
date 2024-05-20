#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

//placeholder of a usable data class
struct Data
{
};


class Serializer
{
    private:
        //costruttore
        Serializer();
        //costruttore di copia
        Serializer(Serializer const &copy);
        //operatore di assegnazione
        Serializer &operator=(Serializer const &copy);
        //distruttore
        ~Serializer();
    public:
        //funzione di conversione
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif