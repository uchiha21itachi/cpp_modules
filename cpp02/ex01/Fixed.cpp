#include "Fixed.hpp"

/*Default constructor*/
Fixed::Fixed(void): _fpnum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*Destructor*/
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/*Copy constructor*/
Fixed::Fixed(const Fixed & a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

/*Integer to Fixed constructor*/
Fixed::Fixed(const int num)
{
    std::cout << "Int Constructor called" << std::endl;
    this->_fpnum = num << this->_fbits;
}

/*Float to Fixed constructor*/
Fixed::Fixed (float const n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fpnum = roundf(n * (1 << Fixed::_fbits));
    return;
}
/*end of constructors*/


/*Member Function*/

/*To return the float equivalent of fixed point number*/
float Fixed::toFloat(void) const
{
	return ((float)(this->_fpnum)/(1 << Fixed::_fbits));
}

/*To return the Integer equivalent of fixed point number*/
int Fixed::toInt(void) const
{
	return (this->_fpnum >> Fixed::_fbits);
}

/*To get the value of fixed point number*/
int     Fixed::getRawBits(void) const
{
	return this->_fpnum;
}

/*To set the value of fixed point number*/
void    Fixed::setRawBits(int const raw)
{
	this->_fpnum = raw;
}


/*operator overload*/

Fixed   &Fixed::operator=(const Fixed &a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->_fpnum = a.getRawBits();
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return o;
}


