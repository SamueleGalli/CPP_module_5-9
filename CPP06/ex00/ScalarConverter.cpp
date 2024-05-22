#include "ScalarConverter.hpp"

//costruttore di default
ScalarConverter::ScalarConverter()
{
}

//int converter
int	convert_to_int(std::string const &input)
{
	int		r;
	int		sign;
	size_t	i;

	r = 0;
	sign = 1;
	i = 0;
	if (input[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; i < input.size(); ++i)
	{
		if (input[i] == '.')
			break ;
		r = r * 10 + (input[i] - '0');
	}
	r = r * sign;
	return (r);
}

int	CheckNumber(std::string const &input)
{
	size_t	i;

	i = 0;
	if (input[i] == '-')
		i++;
	for (; i < input.size(); i++)
	{
        if (input[i] >= '0' && input[i] <= '9')
            continue;
        else if (input[i] == 'f' || input[i] == '.')
            continue;
        return (0);
	}
	return (1);
}

int	CheckString(std::string const &input)
{
	size_t	i;

	i = 0;
	if (input[i] == '-')
		i++;
	for (; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			return (0);
        else
            i++;
	}
	return (1);
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	if (this != &copy)
		*this = copy;
}

int	check_error(std::string const &input)
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
	else if ((CheckNumber(input) == 0 && CheckString(input) == 0) || (input[input.size() - 1] == '.'))
    {
        std::cout << "char: invalid char" << std::endl;
		std::cout << "int: invalid int" << std::endl;
		std::cout << "float: invalid float" << std::endl;
		std::cout << "double: invalid double" << std::endl;
		return (1);
    }
    else
        return (0);
}

void	ToInt(std::string const &input)
{
	int		r;

	r = 0;
	if (CheckNumber(input) == 0)
	{
		std::cout << "int: non displayble" << std::endl;
		return ;
	}
    r = convert_to_int(input);
	std::cout << "int: " << r << std::endl;
	return ;
}

void	ToFloat(std::string const &input)
{
	if (CheckNumber(input) == 0)
	{
		std::cout << "float: non displayble" << std::endl;
		return ;
	}
    int dies = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '.')
        {
            dies++;
            break;
        }
    }
    if (input[input.size() - 1] != 'f' && dies == 1)
    {
        std::cout << "float: " << input << "f" << std::endl;
    }
    else if (dies == 0)
    {
        std::cout << "float: " << input << ".0f" << std::endl;
    }
    else
    {
        std::cout << "float: " << input << std::endl;
    }
	return ;
}

void	ToDouble(std::string const &input)
{
	if (CheckNumber(input) == 0)
	{
		std::cout << "double: non displayble" << std::endl;
		return ;
	}
	int dies = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '.')
		{
			dies++;
            break;
		}
    }
    if (dies == 0)
    {
        std::cout << "double: " << input << ".0" << std::endl;
    }
    else
    {
		if (input[input.size() - 1] == 'f')
			std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		else
    		std::cout << "double: " << input << std::endl;
    }
	return ;
}

void	ToChar(std::string const &input)
{
	char	c;
	int		r;
	int		overflow;
	int		non_displyable;

    if (input.size() == 1 && isdigit(input[0]) == 0)
    {
        std::cout << "char: '" << input << "'" << std::endl;
        return ;
    }
    else if (input.size() > 1 && isdigit(input[0]) == 0)
    {
        std::cout << "char: invalid char" << std::endl;
        return ;
    }
	r = convert_to_int(input);
	overflow = 0;
	non_displyable = 0;
	if (r > 127 || r < -128)
		overflow = 1;
	else if (r < 32 || r == 127)
		non_displyable = 1;
	else
		c = static_cast<char>(r);
	if (overflow == 1)
		std::cout << "char: overflow" << std::endl;
	else if (non_displyable == 1)
		std::cout << "char: non displayble" << std::endl;
	else
	{
		c = static_cast<char>(r);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

//metodo di conversione
void ScalarConverter::convert(std::string const &input)
{
	if (check_error(input) == 1)
		return ;
	else
	{
		ToChar(input);
		ToInt(input);
		ToFloat(input);
		ToDouble(input);
	}
}

//operatore di assegnazione
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
	(void)copy;
	return (*this);
}

//distruttore
ScalarConverter::~ScalarConverter()
{
}
