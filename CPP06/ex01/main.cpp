#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data myData;
    uintptr_t serialized = Serializer::serialize(&myData);
    Data* deserialized = Serializer::deserialize(serialized);

    if (&myData == deserialized) {
        std::cout << "Deserialized pointer is equal to the original pointer" << std::endl;
        return 0;
    } else {
        std::cout << "Deserialized pointer is not equal to the original pointer" << std::endl;
        return 1;
    }
}