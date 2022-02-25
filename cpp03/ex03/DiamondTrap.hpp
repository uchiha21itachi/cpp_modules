#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    
    public :

        DiamondTrap(void);
        ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap &b);
        DiamondTrap & operator=(const DiamondTrap &b);
        DiamondTrap(std::string str);

        void attack(const std::string& target);

		void whoAmI(void) const;

    private :
        std::string _name;
};


#endif