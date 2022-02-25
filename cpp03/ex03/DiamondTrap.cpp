#include "DiamondTrap.hpp"

//Default Constructor
DiamondTrap::DiamondTrap(void) :ClapTrap("Anonymous_Clap"),
ScavTrap(),
FragTrap()
{
    this->_name = "Anonymous";
    this->_hit_point = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
    std::cout << "(Default DiamondTrap)\tA new DiamondTrap champion with default name " << 
    this->_name << " is borned" << std::endl;
}

//Name Constructor
DiamondTrap::DiamondTrap(std::string str) :ClapTrap(str + "_Clap"),
ScavTrap(str),
FragTrap(str)
{
    this->_name = str;
    this->_hit_point = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
    std::cout << "(Name DiamondTrap)\tA new named DiamondTrap Champion " << this->_name << 
    " is borned"<< std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap & b)
{
    *this = b;
    std::cout << "(Copy DiamondTrap)\tA new DiamondTrap champion " <<
    this->_name << " is born from another DiamondTrap" << std::endl;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &b) 
{
    ClapTrap::_name = b._name + "_Clap";
    this->_name = b._name;
    this->_hit_point = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
     std::cout << " (Copy=DiamondTrap)\tDiamondTrap Champion " << this->_name << 
    " - Has taken all the attributes from another champion "<< std::endl;   
    return (*this);
}


DiamondTrap::~DiamondTrap(void)
{
    std::cout << "(Destructor DiamondTrap)\tDestroyed DiamondTrap " << this->_name << std::endl;
}


void    DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamonTrap Champion is called - " << this->_name <<
    ", But only few people know his true name  - " << ClapTrap::_name << std::endl;
}