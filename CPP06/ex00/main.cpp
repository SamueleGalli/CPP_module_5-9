#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        ScalarConverter::convert(v[1]);
    }
}