#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

    class Fixed {

            public:
                Fixed(void);                                    //default constructor
                ~Fixed(void);                                   //destructor
                Fixed(const Fixed & a);                         //copy constructor
                Fixed(const int int_val);                       //Int constructor
                Fixed(const float float_val);                   //Float constructor
        
                Fixed & operator = (const Fixed & b);             //copy operator

                Fixed operator + (const Fixed & b);
                Fixed operator - (const Fixed & b);
                Fixed operator * (const Fixed & b);
                Fixed operator / (const Fixed & b);

                Fixed & operator ++ (void);
                Fixed & operator -- (void);
                Fixed operator ++ (int);
                Fixed operator -- (int);

                bool operator > (const Fixed & b) const;      
                bool operator < (const Fixed & b) const;      
                bool operator <= (const Fixed & b)const ;      
                bool operator >= (const Fixed & b)const ;      
                bool operator == (const Fixed & b)const ;      
                bool operator != (const Fixed & b)const ;      

                static const Fixed & min (const Fixed & a, const Fixed &b);
                static const Fixed & max (const Fixed & a, const Fixed &b);

                int getRawBits( void ) const;
                void setRawBits( int const raw );
                int toInt(void) const;
                float toFloat(void) const;


            private:
                int                     _fpnum;
                static const int        _fbits = 8;
    };
std::ostream & operator<<(std::ostream & o, Fixed const & src);
const Fixed & min (Fixed const & a, Fixed const &b);
const Fixed & max (Fixed const & a, Fixed const &b);

#endif
