#include "Scaler.hpp"


int     checkIfChar(std::string str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return 1;
	return 0;
}

int	    checkIfInt(std::string str)
{
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

int	    checkIfFloat(std::string str)
{
	int	    d = 0;

    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return 0;
    if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
    for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
            {
                if (str[i] == 'f')
                    return (1);
                else
                    return (0);
            }
			if (str[i] == '.')
			{
				if (d)
					return 0;
				d = 1;
			}
			else
				return 0;
		}
	}
	return 0;
}

int	    checkIfDouble(std::string str)
{
	int	    d = 0;

    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return 0;
    if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
    for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (d == 1)
					return 0;
				d = 1;
			}
			else
				return 0;
		}
	}
	return 1;
}

int     checkSpecial(std::string str)
{
    if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (3);
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (4);
	return (0);
}

int     getType(std::string str)
{
    int     ret;

    if ((ret = checkSpecial(str)) != 0)
        return (ret);
    if (checkIfChar(str))
        return (1);
    if (checkIfInt(str))
        return (2);
    if (checkIfFloat(str))
        return (3);
    if (checkIfDouble(str))
        return (4);
    return (0);
}


void    print_float_double(std::string const & str, double num)
{
    int     temp_num = get_float_len(str);
    int     prec_num = 0;
    float   int_float_diff = 0;

    if (temp_num > 6)
    {
        std::cout << "float: " << static_cast<float>(num)   << std::endl;
        std::cout << "double: " << static_cast<double>(num)   << std::endl;
    }
    else
    {
        prec_num = 6 - temp_num;
        if (prec_num == 0)
        {
            std::cout << "float: " << static_cast<float>(num)  << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(num)  << ".0" << std::endl;
        }
        else
        {
            int_float_diff = static_cast<float>(num) - static_cast<int>(num);
            if (std::abs(int_float_diff) > 0)
            {
                std::cout << "float: " << static_cast<float>(num)  << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(num)  << std::endl;
            }
            else
            {
                std::cout << "float: " << static_cast<float>(num)  << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(num)  << ".0" << std::endl;
            }
        }

    }    
}