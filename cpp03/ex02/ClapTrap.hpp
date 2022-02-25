#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

    public :
        
        /*
            **Canonical form constructors
        */
            ClapTrap(void);
            ~ClapTrap(void);
            ClapTrap(const ClapTrap & b);
            ClapTrap & operator = (const ClapTrap &b); 

        /*
            Other Constructors
        */
            ClapTrap(std::string str);

            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
            int getAttackDamage(void) const;
            std::string getName(void) const;

    
    protected :
        std::string _name;
        int         _hit_point;
        int         _energy_points;
        int         _attack_damage;

};




#endif