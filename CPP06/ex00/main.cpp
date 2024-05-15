#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    ScalarConverter convert;
    if (c == 2)
    {
        convert.convert(v[1]);
    }
}