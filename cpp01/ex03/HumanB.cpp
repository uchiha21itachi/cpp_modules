#include "HumanB.hpp"


HumanB::HumanB(std::string const & name):
	_name(name)
{
    this->_weapon = 0;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB named - [" << this->_name << "] has left us foreverr " << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack(void) const
{
    if (this->_weapon != 0)
    {
        std::cout << this->_name << " attacks with their " 
        << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->_name << " does not possess any weapon" << std::endl;
    }
}
