#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

    class Fixed {

            public:
                Fixed(void);                            //default constructor
                ~Fixed(void);                           //destructor
                Fixed(const Fixed & a);                 //copy constructor
                Fixed &operator=(const Fixed & b);     //copy operator
                int getRawBits( void ) const;
                void setRawBits( int const raw );

            private:
                int                     _fpnum;
                static const int        _fbits = 8;
    };


#endif