#include "Weapon.hpp"

const std::string & Weapon::getType(void) const
{
    return this->_type;
}

void    Weapon::setType(const std::string &newType)
{
    this->_type = newType;
}

Weapon::Weapon(std::string type)
{
    _type = type;
    std::cout << "Weapon created - title [" << type 
    << "] successfully bestowed " << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << this->_type << " -shattered."
    << std::endl;
}