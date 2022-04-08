#include "Scaler.hpp"

void    convertChar(std::string const & str)
{
    char c = str[1];

	if (static_cast<int> (c) < 32 || static_cast<int> (c)  > 126)
		std::cout << "char: The character is nor printable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(c) << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" <<std::endl;
}

void    convertInt(std::string const & str)
{
    double num = strtod(str.c_str(), NULL);

    //For printing char
	if ( num < 0. || num > 255.)
		std::cout << "char: Out of range" << std::endl;
	else if (num < 32. || num > 126.)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;

    //For printing Int
    if ( num < static_cast<double> (INT_MIN) || num > static_cast<double> (INT_MAX))
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

    //For Double and Float
    if ((num >= 999999) || (num < -999999))
    {
        std::cout << "float: "  << static_cast<float>(num) << std::endl;
    	std::cout << "double:"  << static_cast<double>(num) << std::endl;
    }
    else
    {
        std::cout << "float: "  << static_cast<float>(num) << ".0f" << std::endl;
	    std::cout << "double:"  << static_cast<double>(num) << ".0" << std::endl;
    }    
}

int     get_float_len(std::string const & str)
{
    int     ret = 0;
    size_t  i = 0;

    if (str[0] == '+' || str[0] == '-')
        i++;
    while (i != str.length() && str[i] == '0')
        i++;
    for (; i < str.length(); i++)
    {
        ret++;
        if (str[i] == '.')
            return(ret - 1);
    }
    return (ret - 1);
}

void    converFloat(std::string const & str)
{
    double  num = strtod(str.c_str(), NULL);

    //checking for nan
    if (!str.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		return;
	}

    //checking for char range(printable or not)
    if (num < 0. || num > 255.)
		std::cout << "char: Out of range" << std::endl;
	else if (num < 32. || num > 126.)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
    
    //checking the int range
    if ( num < static_cast<double> (INT_MIN) || num > static_cast<double> (INT_MAX))
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

    //checking the float and double
    print_float_double(str, num);
}

void    convertDouble(std::string const & str)
{
    double num = strtod(str.c_str(), NULL);

    //checking for nan
    if (!str.compare("nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" <<std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		return;
	}
    //checking for char range(printable or not)
    if (num < 0. || num > 255.)
		std::cout << "char: Out of range" << std::endl;
	else if (num < 32. || num > 126.)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
    
    //checking the int range
    if ( num < static_cast<double> (INT_MIN) || num > static_cast<double> (INT_MAX))
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

    //checking the float and double
    print_float_double(str, num);
   
}


int     main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error in args. Plese enter correct input. usage [./conversion arg1]" << std::endl;
        return (1);
    }
    std::string str =   av[1];
    int                 ret;

    if (str.length() == 0)
    {
        std::cout << "Error in args. Not valid argument. usage [./conversion arg1]" << std::endl;
        return (1);
    }
    void (*converter[4])(std::string const &) = {&convertChar, &convertInt, &converFloat, &convertDouble};
    ret = getType(str);
    if (ret == 0)
        std::cout << "arg type - Unknown. " << std::endl;
    else
        converter[ret - 1](str);
    return (0);
}