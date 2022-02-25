#include "FragTrap.hpp"

FragTrap::FragTrap(void) :ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "(Default FragTrap)\tA new FragTrap champion with default name " << 
    this->_name << " is borned" << std::endl;
}

FragTrap::FragTrap(std::string str) :ClapTrap(str)
{
    this->_hit_point = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "(Name FragTrap)\tA new named FragTrap Champion " << this->_name << 
    " is borned"<< std::endl;
}

FragTrap::FragTrap(const FragTrap &b) :ClapTrap(b)
{
    std::cout << "(Copy FragTrap)\tA new FragTrap champion " <<
     this->_name << " is born from another FragTrap" << std::endl;
}

FragTrap & FragTrap::operator = (const FragTrap &b) 
{
    ClapTrap::operator=(b);
    std::cout << " (Copy=FragTrap)\tFragTrap Champion " << this->_name << 
    " - Has taken all the attributes from another champion "<< std::endl;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "(Destructor FragTrap)\tDestroyed FragTrap " << this->_name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::string input;

    std::cout << "FragTrap " << this->_name << " is really overwhelmed by your presence\n" << std::endl;
    std::cout << "FragTrap " << this->_name << " requesting a HIGH FIVEEE !!!**Fraggy_eyes**" << std::endl;
    while(1)
    {
        std::cout <<"please enter [YES/Y] or [NO/N]. say yes .. say yess \n" << std::endl;
        std::cin >> input;
        if ((input.compare("YES") == 0) || (input.compare("Y") == 0))
        {
            std::cout << "BAAAMMMMMM!!!. YOU ARE AMAZINGGG> THANKSSS>>>\n" << std::endl;
            return;
        }
        if ((input.compare("NO") == 0) || (input.compare("N") == 0))
        {
            std::cout << "You are HORRIBBLE PERSON. I am so sad I wanna die....\n" << std::endl;
            return; 
        }
    }    
}