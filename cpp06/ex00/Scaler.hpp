#ifndef SCALER_HPP
# define SCALER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "limits.h"
#include <limits>

int     checkIfChar(std::string str);
int	    checkIfInt(std::string str);
int	    checkIfFloat(std::string str);
int	    checkIfDouble(std::string str);
int     checkSpecial(std::string str);
int     getType(std::string str);


void    convertChar(std::string const & str);
void    convertInt(std::string const & str);
void    converFloat(std::string const & str);
void    convertDouble(std::string const & str);


int     get_float_len(std::string const & str);
void    print_float_double(std::string const & str, double num);


#endif