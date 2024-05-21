#include "Serializer.hpp"

uintptr_t    Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &copy)
{
    if (this != &copy)
        *this = copy;
}

Serializer &Serializer::operator=(Serializer const &copy)
{
    return (*this);
}

Serializer::~Serializer()
{
}