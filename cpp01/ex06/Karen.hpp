#ifndef KAREN_CPP
# define KAREN_CPP

#include <iostream>
#include <string>

class Karen{

    public :
        Karen(void);
        ~Karen(void);
        void complain( std::string level );  
    
    private :
        void    (Karen::*_stages[4]) (void);
        void    _debug(void);
        void    _info(void);
        void    _warning(void);
        void    _error(void);
};

#endif