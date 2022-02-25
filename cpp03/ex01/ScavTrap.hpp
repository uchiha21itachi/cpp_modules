#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    
    public :

        ScavTrap(void);
        ~ScavTrap(void);
        ScavTrap(const ScavTrap &b);
        ScavTrap & operator=(const ScavTrap &b);
        ScavTrap(std::string str);

        void attack(const std::string& target);
        void guardGate();

};


#endif