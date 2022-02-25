#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
    
    public :

        FragTrap(void);
        ~FragTrap(void);
        FragTrap(const FragTrap &b);
        FragTrap & operator=(const FragTrap &b);
        FragTrap(std::string str);

        void highFivesGuys(void);

};


#endif