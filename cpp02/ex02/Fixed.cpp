#include "Fixed.hpp"

/*constructors*/

Fixed::Fixed(void): _fpnum(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & a)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed::Fixed(const int num)
{
    // std::cout << "Int Constructor called" << std::endl;
    this->_fpnum = num << this->_fbits;
}

Fixed::Fixed (float const n)   
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fpnum = roundf(n * (1 << Fixed::_fbits));
    return;
}

/*end of constructors*/


/*Member Function*/

float Fixed::toFloat(void) const
{
	return ((float)(this->_fpnum)/(float)(1 << Fixed::_fbits));
}

int Fixed::toInt(void) const
{
	return (this->_fpnum >> Fixed::_fbits);
}

int     Fixed::getRawBits(void) const
{
	return this->_fpnum;
}

void    Fixed::setRawBits(int const raw)
{
	this->_fpnum = raw;
}

const Fixed & Fixed::min(const Fixed &a ,const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed & min(Fixed const &a , Fixed const &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed & max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return a;
    return b;
}

/*End of Member Function*/



/*Operator Overload*/

/* Copy assignment operator*/
Fixed   &Fixed::operator=(const Fixed &a)
{
    if (this != &a)
        this->_fpnum = a.getRawBits();
    return (*this);
}


/*Arthimetic functions */

Fixed Fixed::operator + (const Fixed & b)
{
    Fixed temp;

    temp.setRawBits(this->_fpnum + b.getRawBits());
    return (temp);
}

Fixed Fixed::operator - (const Fixed & b)
{
    Fixed temp;

    temp.setRawBits(this->_fpnum - b.getRawBits());
    return (temp);
}

Fixed Fixed::operator * (Fixed const & b)
{
	Fixed	temp;

    temp.setRawBits( (this->_fpnum * b.getRawBits()) / (1 << Fixed::_fbits) );
	return temp;
}

Fixed Fixed::operator / (Fixed const & b)
{
    Fixed temp;

    if (b.getRawBits() == 0)
    {
        std::cout << "Cannot divide by zero. Returning zero" << std::endl;
        temp.setRawBits(0);
    }
    else
    {
        temp.setRawBits( (this->_fpnum * (1 << Fixed::_fbits)) / b.getRawBits() );
    }
    return temp;
}

/*Increment Decrement Operators */
Fixed & Fixed::operator ++(void)
{
    this->_fpnum++;
    return (*this);
}

Fixed & Fixed::operator --(void)
{
    this->_fpnum--;
    return (*this);
}

Fixed Fixed::operator ++(int)
{
    Fixed temp;

    temp = *this;
    ++(*this);
    return (temp);
}

Fixed Fixed::operator --(int)
{
    Fixed temp;
    temp = *this;
    --(*this);
    return (temp);
}

/* Comparison Operators*/

bool Fixed::operator == (const Fixed & b) const
{
    return (this->_fpnum == b.getRawBits());
}

bool Fixed::operator != (const Fixed & b)const
{
    return (this->_fpnum != b.getRawBits());
}

bool Fixed::operator > (const Fixed & b)const
{
    return (this->_fpnum > b.getRawBits());
}

bool Fixed::operator < (const Fixed & b)const
{
    return (this->_fpnum < b.getRawBits());
}

bool Fixed::operator >= (const Fixed & b)const
{
    return (this->_fpnum >= b.getRawBits());
}

bool Fixed::operator <= (const Fixed & b)const
{
    return (this->_fpnum <= b.getRawBits());
}


std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return o;
}


/*Destructor*/

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}
