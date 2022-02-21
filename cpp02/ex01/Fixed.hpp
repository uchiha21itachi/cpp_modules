#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

    class Fixed {

            public:
                Fixed(void);                            //default constructor
                ~Fixed(void);                           //destructor
                Fixed(const Fixed & a);                 //copy constructor
                Fixed & operator=(const Fixed & b);     //copy operator
                
                Fixed(const int int_val);
                Fixed(const float float_val);
                
                int getRawBits( void ) const;
                void setRawBits( int const raw );
                
                int toInt(void) const;
                float toFloat(void) const;



            private:
                int                     _fpnum;
                static const int        _fbits = 8;
    };
std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif
