#include "HumanA.hpp"

HumanA::HumanA(std::string const & name, Weapon& weapon):
	_name(name), _weapon(weapon)
{}

HumanA::~HumanA(void)
{
    std::cout << "HumanA named - [" << this->_name << "] has left us foreverr " << std::endl;
}

void    HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with their " 
    << this->_weapon.getType() << std::endl;
}
