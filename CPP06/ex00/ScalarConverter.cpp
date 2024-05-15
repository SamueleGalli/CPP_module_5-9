#include "ScalarConverter.hpp"
//costruttore di default
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    if (this != &copy)
        *this = copy;
}

int check_error(std::string const &input)
{
    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (1);
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return (1);
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (1);
    }
    else
        return (0);
}

int ToInt(std::string const &input)
{
    int r = 0;
    int sign = 1;
    size_t  i = 0;

    //controllo valore negativo
    if (input[0] == '-')
    {
        sign = -1;
        i++;
    }
    for(; i < input.size(); ++i)
    {
        r = r * 10 + (input[i] - '0');
        if (input[i] == '.' || input[i] == 'f')
            i++;
    }
    return (r * sign);
}
float ToFloat(std::string const &input)
{
    float r = 0.0f;
    int sign = 1;
    size_t  i = 0;

    //controllo valore negativo
    if (input[0] == '-')
    {
        sign = -1;
        i++;
    }
    for(; i < input.size() && input[i] != '.'; ++i)
        r = r * 10.0f + (input[i] - '0');
    
    if (i < input.size())
    {
        float   fraction = 0.1f;
        i++;
        for(; i < input.size(); ++i)
        {
            r += (input[i] - '0') * fraction;
            fraction *= 0.1f;
        }
    }
    return (r * sign);
}
double ToDouble(std::string const &input)
{
    double r = 0.0;
    int sign = 1;
    size_t  i = 0;

    //controllo valore negativo
    if (input[0] == '-')
    {
        sign = -1;
        i++;
    }
    for(; i < input.size() && input[i] != '.'; ++i)
        r = r * 10.0 + (input[i] - '0');
    
    if (i < input.size())
    {
        double   fraction = 0.1;
        i++;
        for(; i < input.size(); ++i)
        {
            r += (input[i] - '0') * fraction;
            fraction *= 0.1;
        }
    }
    return (r * sign);
}

int CheckNumber(std::string const &input)
{
    int sign = 0;
    size_t i = 0;
    if (input[i] == '-')
        i++;
    for (; i < input.size(); i++)
    {
        if (input[i] > '0' && input[i] < '9')
            i++;
        else if (input[i] == '.' && sign == 0)
        {
            sign = 1;
        }
        else if (input[i] == 'f' && input[i + 1] == '\0')
            return (1);
        else
            return (0);
    }
    return (1);
}
//metodo di conversione
void ScalarConverter::convert(std::string const &input)
{
    if (check_error(input) == 1)
        return ;
    else
    {
        char    c = input[0];
        int     i = ToInt(input); 
        float   f = ToFloat(input);
        double  d = ToDouble(input);
        if (CheckNumber(input) == 0)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
        if (CheckNumber(input) == 1)
            std::cout << "int: Non displayable" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        if (CheckNumber(input) == 1)
            std::cout << "float: Non displayable" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
        if (CheckNumber(input) == 1)
            std::cout << "double: Non displayable" << std::endl;
        else
        std::cout << "double: " << d << std::endl;
    }
}

//operatore di assegnazione
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

//distruttore
ScalarConverter::~ScalarConverter()
{
}