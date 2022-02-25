#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "(Default ScavTrap)\tA new ScavTrap champion with default name " << 
    this->_name << " is borned" << std::endl;
}

ScavTrap::ScavTrap(std::string str) :ClapTrap(str)
{
    this->_hit_point = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "(Name ScavTrap)\tA new named ScavTrap Champion " << this->_name << 
    " is borned"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &b) :ClapTrap(b)
{
    std::cout << "(Copy ScavTrap)\tA new ScavTrap champion " <<
     this->_name << " is born from another ScavTrap" << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &b) 
{
    ClapTrap::operator=(b);
    std::cout << " (Copy=ScavTrap)\tScavTrap Champion " << this->_name << 
    " - Has taken all the attributes from another champion "<< std::endl;
    return (*this);
}


ScavTrap::~ScavTrap(void)
{
    std::cout << "(Destructor ScavTrap)\tDestroyed ScavTrap " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hit_point <= 0)
    {
        std::cout << "(Attack Scav)\tScavTrap " << this->_name << " Cannot attack. No HP left " << std::endl;
        return;
    }
    if (this->_energy_points > 0)
    {
        this->_energy_points--;
        std::cout << "(Attack Scav)\tScavTrap " << this->_name << " Attacked - " << target <<
        " causing " << this->_attack_damage << " Points of damage !!\n" << std::endl;  
    }
    else
    {
        std::cout << "(Attack Scav)\tScavTrap " << this->_name << " Wants to attack " << this << std::endl;
        std::cout << "Cannot attack no Energy Points left to attack\n\n" << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout <<"ScavTrap " << this->_name << "is in GATE KEEPER MODE..!!!" << std::endl;
}