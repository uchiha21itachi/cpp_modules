#include "Fixed.hpp"

Fixed::Fixed(void): _fpnum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
	return this->_fpnum;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "getRawBits member function called" << std::endl;
	this->_fpnum = raw;
}

Fixed   &Fixed::operator=(const Fixed &a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->_fpnum = a.getRawBits();
    return (*this);
}